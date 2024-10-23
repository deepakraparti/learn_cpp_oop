#include <iostream>
#include <thread>
#include <future>

using namespace std;


void calculateSquare(int x, promise<int>&& prom)
{
  this_thread::sleep_for(chrono::seconds(1));
  prom.set_value(x*x); // set the result in the promis
}

int main()
{
  promise<int> prom;
  future<int> fut = prom.get_future(); // get the associated future

  thread t (calculateSquare, 5, move(prom)); // star the thread with promise

  cout << "waiting for the result.." << endl;
  int result = fut.get(); // wait and get the result
  cout << "Square is: " << result << endl;

  t.join();
  return 0;
}
