#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

atomic<int> counter(0); // Atomic counter

void incrementCounter(int iterations)
{
  for (int i = 0; i < iterations; i++)
  {
    ++counter; //atomic increment
  }
}

int main()
{
  const int numThreads = 10;
  const int iterations = 1000;

  vector<thread> threads;

  // create threads
  for (int i = 0; i < numThreads; ++i)
  {
    threads.emplace_back(incrementCounter, iterations);
  }

  // wait for all threads to finish
  for (auto& t : threads)
  {
    t.join();
  }

  cout << "Final counter value: " << counter.load() << endl;

  return 0;
}
