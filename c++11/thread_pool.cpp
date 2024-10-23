#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;


class SimpleThreadPool
{
  public:
    SimpleThreadPool(size_t numThreads);
    ~SimpleThreadPool();
    void enqueue(function<void()> task);

  private:
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex queueMutex;
    condition_variable cvar;
    atomic<bool> stop;
};

SimpleThreadPool::SimpleThreadPool(size_t numThreads) : stop(false)
{
  for (size_t i = 0; i < numThreads; ++i)
  {
    workers.emplace_back([this] {
      while(true)
      {
        function<void()> task;

        {
          unique_lock<mutex> lock(this->queueMutex);
          this->cvar.wait(lock, [this] {
             return this->stop || !this->tasks.empty() ;
          });

          // Exit if stopping and no tasks left
          if (this->stop && this->tasks.empty())
          {
            return;
          }

          // Get the next task
          task = move(this->tasks.front());
          this->tasks.pop();
        }

        task(); // Execute task
      }
    });
  }
}

SimpleThreadPool::~SimpleThreadPool()
{
  {
    unique_lock<mutex> lock(queueMutex);
    stop = true;
  }
  cvar.notify_all(); // Wake up all worker threads

  for (thread& worker: workers)
  {
    worker.join();
  }
}

void SimpleThreadPool::enqueue(function<void()> task)
{
  {
    unique_lock<mutex> lock(queueMutex);
    tasks.emplace(move(task));
  }
  cvar.notify_one(); //Notify one worker thread
}

int main()
{
  SimpleThreadPool pool(4); //Pool of 4 threads

  // Enqueue simple tasks
  for (int i = 0; i < 8; ++i)
  {
    pool.enqueue([i] {
      cout << "Task " << i << " is being executed by thread " << this_thread::get_id() << endl;
      this_thread::sleep_for(chrono::milliseconds(500));
    });
  }

  this_thread::sleep_for(chrono::seconds(3));

  return 0;
}
