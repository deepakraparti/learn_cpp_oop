#include <iostream>

using namespace std;

const int size = 3;

template<class T>
class vector
{
    T *v;

  public:
    vector()
    {
      cout << "Default constructor" << endl;
      v = new T[size];
      for (int i = 0; i < size; i++)
        v[i] = 0;
    }

    vector(T *a)
    {
      v = new T[size];
      for (int i = 0; i < size; i++)
        v[i] = a[i];
    }

    T operator*(vector &y)
    {
      T sum = 0;
      for (int i = 0; i < size; i++)
        sum += this->v[i] * y.v[i];

      return sum;
    }

    void display(void)
    {
      for (int i = 0; i < size; i++)
        cout << v[i] << "\t";
      cout << "\n";
    }

    ~vector()
    {
      delete[] v;
    }
};

int main()
{
  cout << "INTEGER VECTOR\n" << endl;

  int x[3] = {1, 2, 3};
  int y[3] = {4, 5, 6};

  vector <int> v1(x);
  vector <int> v2(y);

  cout << "v1 = ";
  v1.display();

  cout << "v2 = ";
  v2.display();

  cout << "v1 x v2 = " << v1*v2 << endl;

  cout << "FLOAT VECTOR\n" << endl;

  float a[3] = {1.1, 2.2, 3.3};
  float b[3] = {4.4, 5.5, 6.6};

  vector <float> v3(a);
  vector <float> v4(b);

  cout << "v3 = ";
  v3.display();

  cout << "v4 = ";
  v4.display();

  cout << "v3 x v4 = " << v3*v4 << endl;

  return 0;
}

