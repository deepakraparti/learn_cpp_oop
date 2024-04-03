#include <iostream>
#include <cstring>

using namespace std;

struct Student{
  char name[30];
  int roll_no;
};

int main()
{
  struct Student A; // C style of declaring struct variables
  strcpy(A.name, "XYZ");
  A.roll_no = 1;

  Student B;	// C++ sytle of struct declartion, struct keyword is not required while declaring variables
  strcpy(B.name, "ABCD");
  B.roll_no = 2;

  return 0;
}
