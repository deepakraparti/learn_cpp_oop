#include <iostream>

using namespace std;

class Sample{
  private:
    int data1;
    char data2;
  public:
    void set(int i, char c)
    {
      data1 = i;
      data2 = c;
    }

    void display(void)
    {
      cout << "Data1 = " << data1 << endl;
      cout << "Data2 = " << data2 << endl;
    }
};

int main(void)
{
  Sample *s_ptr;

  try
  {
    s_ptr = new Sample;
  }
  catch (bad_alloc ba)
  {
    cout << "Bad allocation occured... the program will terminate now" << endl;
    return 1;
  }

  s_ptr->set(25, 'A');
  s_ptr->display();

  delete s_ptr;
  return 0;
}
