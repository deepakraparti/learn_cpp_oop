#include <iostream>

using namespace std;

class matrix
{
    int **p;  // this is a pointer to matrix
    int m,n;  // dimensions of matrix
  public:
    matrix(int x, int y);
    void get_element(int i, int j, int value)
    {
      p[i][j] = value;
    }

    int & put_element(int i, int j)
    {
      return p[i][j];
    }
};

matrix :: matrix(int x, int y)
{
  m = x;
  n = y;
  p = new int *[m]; // array of pointers

  for (int i=0; i < m; i++)
  {
    p[i] = new int[n];  // space for row
  }
}

int main()
{
  int m, n;

  cout << "Enter size of matrix (m x n): ";
  cin >> m >> n;
  matrix A(m,n);

  cout << "Enter matrix elements row by row:\n";
  int i, j, value;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> value;
      A.get_element(i, j, value);
    }

  cout << "\n";
  cout << A.put_element(1,2) << endl;

  return 0;
}
