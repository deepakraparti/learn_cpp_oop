#include <iostream>
#include <vector>

using namespace std;

class FloatVector
{
  vector<float> elements;
public:
  void createVector(vector<float>& initialElements)
  {
    elements = initialElements;
  }

  void modify(int index, float newValue)
  {
    if (index >= 0 && index < elements.size())
    {
      elements[index] = newValue;
    }
    else
    {
      cout << "Invalid index\n"; 
    }
  }

  void scalarMultiply(int multiplier)
  {
    for(int i = 0; i < elements.size(); i++)
    {
      elements[i] = elements[i] * (float)multiplier;
    }
  }

  void display()
  {
    for (float element : elements)
    {
      cout << element <<", ";
    }
    cout <<"\n";
  }
};

int main()
{
  FloatVector vec;
  vector<float> initialValues = {1.1, 2.2, 3.3, 4.4, 5.5};
  vec.createVector(initialValues);
  vec.display();
  vec.modify(2, 6.6);
  vec.display();
  vec.scalarMultiply(2);
  vec.display();
  return 0;
}
