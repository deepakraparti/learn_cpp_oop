#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream file1("Source1");
  ifstream file2("Source2");
  ofstream target("Target");

  int num1, num2;
  bool hasNum1 = false;
  bool hasNum2 = false;

  if (file1 >> num1)
    hasNum1 = true;

  if (file2 >> num2)
    hasNum2 = true;

  while(hasNum1 || hasNum2)
  {
    if (hasNum1 && hasNum2)
    {
      if (num1 <= num2)
      {
        target << num1 << " ";

        if (file1 >> num1) 
        {
          hasNum1 = true;
        }
        else
        {
          hasNum1 = false;
        }
      }
      else
      {
        target << num2 << " ";

        if (file2 >> num2) 
        {
          hasNum2 = true;
        }
        else
        {
          hasNum2 = false;
        }
      }
    }
    else if (hasNum1)
    {
      target << num1 << " ";

      if (file1 >> num1) 
      {
        hasNum1 = true;
      }
      else
      {
        hasNum1 = false;
      }
    }
    else if (hasNum2)
    {
      target << num2 << " ";

      if (file2 >> num2) 
      {
        hasNum2 = true;
      }
      else
      {
        hasNum2 = false;
      }
    }
  }

  cout << "Files merged successfully" << endl;

  file1.close();
  file2.close();
  target.close();
  
  return 0;
}
