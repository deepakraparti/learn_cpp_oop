#include <iostream>
#include <cstring>

int main()
{
  int i = 0;
  char *ptr[4] = { "books", "television", "computer", "sports" };

  char str[25];
  std::cout << "Enter your favorite leisure pursuit: ";
  std::cin >> str;

  for (i=0; i < 4; i++)
  {
    if (strcmp(str, ptr[i]))
    {
      std::cout << "Your favorite pursuit " << str << " is available here\n";
      break;
    }
  }

  if (i == 4)
  {
    std::cout << "Your favorite pursuit " << str << " is not available\n";
  }

  return 0;
}
