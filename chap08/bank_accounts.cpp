#include <iostream>
#include <cstring>
#include <cmath>

#define MIN_BALANCE		5000
#define SERVICE_CHARGE		200
#define RATE_OF_INTEREST	0.15

class acct
{
  protected:
    char customer_name[50];
    int acct_number;
    char acct_type[10];
    float balance;

  public:
    void create_account(char *type)
    {
      std::cout << "Enter Name:";
      fgets(customer_name, sizeof(customer_name), stdin);

      std::cout << "Enter account number:";
      std::cin>>acct_number;

      strcpy(acct_type, type);
      balance = 0;
    }

    void display_balance()
    {
      std::cout << "Avilable balance: " << balance << "\n";
    }
};

class cur_acct : public acct
{
  public:
    void deposit(float amount)
    {
      balance += amount;
    }

    void withdraw(float amount)
    {
      if (balance < amount) 
      {
        std :: cout << "Sorry, insufficient balance\n"; 
      }
      else
      {
        balance -= amount;
        if (balance < MIN_BALANCE)
        {
          std::cout << "Your balance " << balance << " is less than " << MIN_BALANCE << " to avoid penaulty.\n Do you want to withdraw? If yes, press 1 or If no, press 0\n";

          int res;
          std :: cin >> res;

          if (res  == 0)
            balance += amount;
          else
            balance -= SERVICE_CHARGE;
        }
      }
    }
};

class sav_acct : public acct
{
   int date, month, year;
  public:
    void deposit(float amount)
    {
      std :: cout << "Enter today's date (date, month, year): ";
      std :: cin >> date >> month >> year;

      balance += amount;
    }

    void withdraw(float amount)
    {
      if (balance < amount)
      {
        std :: cout << "Sorry, insufficient balance\n\n";
      }
      else
      {
        balance -= amount;
      }
    }

    void compute_and_deposit_interest()
    {
      int Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      int d, m , y;
      std :: cout << "Enter today's date (date, month, year): ";
      std::cin >> d >> m >> y; 

      // Calculate the period in years 
      int iday = date, fday = d;
      for (int i = 0; i < m; i++)
      {
        fday += Days[i];
      }

      for (int j = 0; j < month; j++)
      {
        iday += Days[j];
      }
 
      // Total number of days
      int tday = fday - iday;

      // Total years
      float ty = (float)(tday/365) + (y-year);

      balance = balance * std::pow((1 + RATE_OF_INTEREST), ty);
#if 0
      // Another way to calculate interest
      float interest = ty*RATE_OF_INTEREST*balance;
      std::cout << interest << std::endl;
      balance += interest;
#endif
    }
};

int main()
{
  sav_acct sav;
  sav.create_account("Savings");
  sav.display_balance();
  sav.deposit(500);
  sav.display_balance();
  sav.withdraw(1000);
  sav.display_balance();
  sav.compute_and_deposit_interest();
  sav.display_balance();
 
  cur_acct cur;
  cur.create_account("Current");
  cur.display_balance();
  cur.deposit(6000);
  cur.display_balance();
  cur.withdraw(500);
  cur.display_balance();
  cur.withdraw(7000);
  cur.display_balance();
  return 0;
}
