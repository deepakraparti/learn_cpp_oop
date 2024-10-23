#include <iostream>
#include <thread>
#include <mutex>


using namespace std;

mutex mtx;

void printMessage(const string &message)
{
  lock_guard<mutex> lock(mtx); //Acquires the lock
  cout << message << endl;

  // unlike c, in c++ if lock_guard goes out of scope,
  // mutex is released automatically
}

int main()
{
  thread t1(printMessage, "Hello from thread 1");
  thread t2(printMessage, "Hello from thread 2");

  t1.join();
  t2.join();

  return 0;
}
