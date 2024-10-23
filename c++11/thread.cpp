#include <iostream>
#include <thread>

using namespace std;

/* Thread handler function */
void threadFunction()
{
  std::cout << "Thread is executing\n";
}

int main()
{
  thread t(threadFunction);  // creates a thread using function pointer
  t.join();

  //t.detach(); // detaches the thread and run independantly like background job
                // It cannot be joined later.

  return 0;
}
