#include <iostream>
#include <cstring>

int main()
{
  int i, j;
  char str[] = "C++ is better than C";
  int len = strlen(str);

  char *substr = new char[len];
  std::cout << "The main string is : " << str;
  std::cin.ignore();
  std::cout << "\nEnter the substring to be searched: ";
  fgets(substr, len, stdin);
  std::cout << "Substring: " << substr << "\n";

  int k, len2 = strlen(substr);

  for (i = 0; i < len; i++)
  { 
    k = i;
    for (j = 0; j < len2-1; j++)
    {
      if (str[k] == substr[j])
      {
        if (j == len2-2)
        {
          std::cout << "\nThe substring is present in the main string\n";
          exit(0);
        }

        k++;
      }
      else
      {
        break;
      }
    }

  }

  if (i == len)
  {
    std::cout << "The substring is not present in the main string\n";
  }

  return 0;
}
