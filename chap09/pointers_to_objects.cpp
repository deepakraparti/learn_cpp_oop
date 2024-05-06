#include <iostream>

class item
{
    int code;
    float price;
  public:
    void getdata(int a, float b)
    {
      code = a;
      price = b;
    }

    void show(void)
    {
       std::cout << "Code: " << code << "\n";
       std::cout << "Price: " << price << "\n";
    }
};

const int size = 2;

int main()
{
  item *p  = new item[size];
  item *d  = p;
  int x, i;
  float y;

  for (i = 0; i < size; i++)
  {
    std::cout << "Input code and price for item " << i+1 << ": ";
    std::cin >> x >> y;
    p->getdata(x, y);
    p++;
  }

  for (i = 0; i < size; i++)
  {
    std::cout << "Item: " << i+1 << "\n";
    d->show();
    d++;
  }

  return 0;
}
