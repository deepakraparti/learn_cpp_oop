#include <iostream>
#include <cstring>

class media
{
  protected:
    char title[50];
    float price;
  public:
    media (char *s, float a)
    {
      strcpy(title, s);
      price = a;
    }

    virtual void display(){} // empty virtual func
};

class book : public media
{
    int pages;
  public:
    book (char *s, float a, int p) : media (s, a)
    { pages = p; }

    void display();
};

class tape : public media
{
    float time;
  public:
    tape (char *s, float a, float t) : media (s, a)
    { time = t; }

    void display();
};

void book :: display()
{
  std::cout << "\nTitle: " << title;
  std::cout << "\nPrice: " << price;
  std::cout << "\nPages: " << pages;
}

void tape :: display()
{
  std::cout << "\nTitle: " << title;
  std::cout << "\nPrice: " << price;
  std::cout << "\nPlay time: " << time << "mins\n";;
}

int main()
{
  char *title = new char[30];
  float price, time;
  int pages;

  // Book details
  std::cout << "\nENTER BOOK DETAILS\n";
  std::cout << " Title: "; std::cin >> title;
  std::cout << " Price: "; std::cin >> price;
  std::cout << " Pages: "; std::cin >> pages;

  book book1(title, price, pages);

  std::cout << "\nENTER TAPE DETAILS\n";
  std::cout << " Title: "; std::cin >> title;
  std::cout << " Price: "; std::cin >> price;
  std::cout << " Play time (mins): "; std::cin >> time;

  tape tape1(title, price, time);

  media *list[2];
 
  list[0] = &book1;
  list[1] = &tape1;

  std::cout << "\nMEDIA DETAILS";
  std::cout << "\n........ BOOK ........";
  list[0]->display();

  std::cout << "\n........ TAPE ........";
  list[1]->display();

  return 0;
}
