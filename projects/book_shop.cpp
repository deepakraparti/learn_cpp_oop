#include <iostream>
#include <cstring>
#include <iomanip>

class Book
{
    char *author;
    char *title;
    char *publisher;
    int stock_position;
    float price;
    static int successfulTrans;
    static int unsuccessfulTrans;
  public:
    Book() {}

    Book (char *a, char *t, char *p, int stock_pos, float cost)
    {
      author = new char[strlen(a) + 1];
      strcpy(author, a);

      title = new char[strlen(t) + 1];
      strcpy(title, t);

      publisher = new char[strlen(p) + 1];
      strcpy(publisher, p);

      stock_position = stock_pos;
      price = cost;
    }

    void displayTotalCost(int copies)
    {
      std::cout << "Total Cost: " << (copies * price) << "\n";
      stock_position -= copies;
    }

    static void displayTransactions()
    {
      std::cout << "\n===========================================\n";
      std::cout << std::setw(30) << "Successful Transactions\t" << std::setw(30) << "Unsuccessful Transactions\n";
      std::cout << std::setw(30) << successfulTrans << "\t" << std::setw(30) << unsuccessfulTrans << "\n";
      std::cout << "\n===========================================\n";
    }

    int checkIfCopiesAvailable(int copies);
    void updatePrice();
    friend Book& search_book();
};

int Book::successfulTrans = 0;
int Book::unsuccessfulTrans = 0;

Book *books = new Book[10];
Book defaultObj;

Book& search_book()
{
  bool bookAvailable = false;
  char *title = new char[30];
  char *author = new char[30];

  std::cout << "Enter the title of the book: ";
  std::cin >> title;

  std::cout << "Enter the author of the book: ";
  std::cin >> author;

  int i;
  for (i = 0; i < 10; i++)
  {
    if ((strcasecmp(books[i].title, title) == 0) && (strcasecmp(books[i].author, author) == 0))
    {
      bookAvailable = true;
      std::cout << "\n============== Book Details ===============\n";
      std::cout << "Title: " << books[i].title << std::endl;
      std::cout << "Author: " << books[i].author << std::endl;
      std::cout << "Publisher: " << books[i].publisher << std::endl;
      std::cout << "Price: " << books[i].price << std::endl;
      std::cout << "Stock: " << books[i].stock_position << std::endl;
      std::cout << "============================================\n";
      break;
    }
  }

  if (bookAvailable)
  {
    return books[i];
  }
  else
  {
    Book::unsuccessfulTrans++;
    return defaultObj;
  }
}

int Book :: checkIfCopiesAvailable(int copies)
{
  if (stock_position >= copies)
  {
    Book::successfulTrans++;
    return 1;
  }
  else
  {
    return 0;
    Book::unsuccessfulTrans++;
  }
}

void Book :: updatePrice()
{
  float newprice;
  std::cout << "Enter the updated price of the book: ";
  std::cin >> newprice;

  price  = newprice;
}

int main()
{

  // Books
  Book b1 = Book("Robin_Sharma", "Sold_Ferrari", "XYZ", 10, 160);
  Book b2 = Book("JK", "HP1", "JK", 20, 300);
  Book b3 = Book("Amith", "Trilogy_P1", "Rudra", 13, 240);

  books[0] = b1;
  books[1] = b2;
  books[2] = b3;

  while(1)
  {
    std::cout << "\n===========================================\n";
    std::cout << "1. Search the book\n";
    std::cout << "2. Update the book price\n";
    std::cout << "3. Display Transactions\n";
    std::cout << "\nOR Enter q or Q to exit ...\n";
    std::cout << "\n===========================================\n";

    char ch;
    std::cout << "Enter your choice:";
    std::cin >> ch;

    switch(ch)
    {
      case '1':
      {
        Book& book = search_book();

        if (&book == &defaultObj)
        {
          std::cout << "\nBook is out of stock, Please look for another book in stock...\n";
        }
        else
        {
          int copies;
          std::cout << "Enter the number of copies required:";
          std::cin >> copies;

          if (book.checkIfCopiesAvailable(copies) == 0)
          {
            std::cout << "Required copies not in stock\n";
          }
          else
          {
            book.displayTotalCost(copies);
          }
        }
        break;
     }
     case '2':
     {
        Book& book = search_book();

        if (&book == &defaultObj)
        { 
          std::cout << "\nBook is out of stock...\n";
        }
        else
        { 
          book.updatePrice();
        }
        break;
     }
     case '3':
        Book::displayTransactions();
        break;
     case 'q':
     case 'Q':
        std::cout << "Exiting...\n";
        goto exit;

    }
  }

exit:
  return 0;
}
