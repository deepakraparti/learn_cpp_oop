#include <iostream>

class invent2;	//forward declaration

class invent1
{
    int code;
    int items;
    float price;
  public:
    invent1(int a, int b, float c) // basic to class conversion
    {
      code = a;
      items = b;
      price = c;
    }

    void putdata()
    {
      std::cout << "Code: " << code << "\n";
      std::cout << "Items: " << items << "\n";
      std::cout << "Value: " << price << "\n";
    }

    int getcode() { return code; }
    int getitems() { return items; }
    float getprice() { return price; }
    operator float() { return (items * price); }  // class to basic conversion
    operator invent2(); //forward declaration of conversion function
};

class invent2
{
    int code;
    float value;
  public:
    invent2()
    {
      code = 0;
      value = 0;
    }

    invent2(int x, float y)
    {
      code = x;
      value = y;
    }

    void putdata()
    {
      std::cout << "Code: " << code << "\n";
      std::cout << "Value: " << value << "\n";
    }

    void setcode(int c)
    {
      code = c;
    }

    void setvalue(float v)
    {
      value = v;
    }
/*
    invent2(invent1 p)
    {
      code = p.getcode();
      value = p.getprice() * p.getitems();
    }*/
};

invent1 :: operator invent2()  // class to class conversion
{
  invent2 temp;
  temp.setcode(code);
  temp.setvalue(price * items);
  return temp;
}

int main()
{
  invent1 s1(100, 5, 140.0);
  invent2 d1;
  float total_value;

  // invent1 to float
  total_value = s1;

  // invent1 to invent2
  d1 = s1;
  
  std::cout << "Prouct details - invent1 type" << "\n";
  s1.putdata();

  std::cout << "\nStock value\n";
  std::cout << "Value = " << total_value << "\n\n";

  std::cout << "Product details - invent2 type" << "\n";
  d1.putdata();

  return 0;
}
