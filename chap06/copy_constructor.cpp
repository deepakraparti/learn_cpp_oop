#include <iostream>

using namespace std;

class code
{
    int id;
  public:
    code() {}
    code(int a) { id = a;}
    code(code &x) { id = x.id; cout << "Its me, COPY\n";}  //copy constructor

    void display() { cout << id; }  
};

int main()
{
  code A(100);
  code B(A);    // copy constructor
  code C = A;	// calling copy constructor again

  code D;
  D = A;        // copy contructor is not called, assignment operator overload

  cout << "\nid of A: "; A.display();
  cout << "\nid of B: "; B.display();
  cout << "\nid of C: "; C.display();
  cout << "\nid of D: "; D.display();
  cout << "\n";

  return 0;
}
