#include <iostream>

using namespace std;

void display_matrix(int **A, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    cout << "|";
    for (int j = 0; j < cols; j++)
    {
      cout << A[i][j] << " ";
    }
    cout << "|\n";
  }
}

void read_matrix(int **A, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  { 
    for (int j = 0; j < cols; j++)
    {
      cout << "A[" << i << "][" << j << "] = ";
      cin >> A[i][j];
    }
  }
}

int main()
{
  int rows, cols;
  cout << "Enter the number of rows:";
  cin >> rows;

  cout << "Enter the number of cols:";
  cin >> cols;

  int **A = new int *[rows];
  for (int i = 0; i < rows; i++) 
  {
    A[i] = new int[cols];
  }

  read_matrix(A, rows, cols);
  display_matrix(A, rows, cols);
}
