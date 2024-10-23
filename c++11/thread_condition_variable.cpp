#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;

mutex mtx;
condition_variable cvar;
bool ready = false;

void printMessage()
{
  unique_lock<mutex> lock(mtx); //Acquires the lock
  cvar.wait(lock, []{ return ready; }); //wait until ready is true
  cout << "Thread is executing after condition is met" << endl;

  // unlike c, in c++ if lock_guard goes out of scope,
  // mutex is released automatically
}

int main()
{
  thread t(printMessage);
  this_thread::sleep_for(chrono::seconds(3));

  {
    lock_guard<mutex> lock(mtx);
    ready = true;
  }

  cvar.notify_one(); // Notify the waiting thread

  t.join();

  return 0;
}
