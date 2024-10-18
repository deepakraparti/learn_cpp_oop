#include <iostream>

using namespace std;

template <class T>
class vector
{
    T *v;
    int size;
  public:
    vector(int m);
    vector(T *a, int m);
    void modifyValue(int pos, T value);
    void multiplyByScalar(int value);
    void display();
    void operator=(vector &y); 
};

template <class T>
vector<T> :: vector(int m)
{
  v = new T[size = m];
  for (int i = 0; i < size; i++)
    v[i] = 0;
}

template <class T>
vector<T> :: vector(T *a, int m)
{
  size = m;
  v = new T[size];
  for (int i = 0; i < size; i++)
  {
    v[i] = a[i];
  }
}

template <class T>
void vector<T> :: modifyValue(int pos, T value)
{
  v[pos-1] = value;
}

template <class T>
void vector<T> :: multiplyByScalar(int value)
{
  for (int i = 0; i < size; i++)
    v[i] *= value;
}

template <class T>
void vector<T> :: display()
{
  cout << "\n(";
  for (int i = 0; i < size; i++)
    cout << v[i] << ",";
  cout << ")\n"; 
}

template <class T>
void vector<T> :: operator=(vector &y)
{
  cout << "= operator\n";
  this->size = y.size;
  for (int i = 0; i < this->size; i++)
    this->v[i] = y.v[i];
}

int main()
{
  int x[3] = {1, 2, 3};
  float y[3] = {1.1, 2.2, 3.3};

  vector<int> v1(x, 3);
  vector<float> v2(y, 3);

  // Modify the value
  v1.modifyValue(2, 4);
  v2.modifyValue(1, 4.4);

  // multiply by scalar
  v1.multiplyByScalar(2);
  v2.multiplyByScalar(2);

  // Display vectors
  v1.display();
  v2.display();
  return 0;
}
