#include <iostream>
//#include <string>
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
    acct (char *name, int num, char* type)
    {
      strcpy(customer_name, name);
      acct_number = num;
      strcpy(acct_type, type);
      balance = 0;
    }

    void display_balance()
    {
      std::cout << "Avilable balance: " << balance << "\n\n";
    }
};

class cur_acct : public acct
{
  public:
    cur_acct(char *name, int num): acct(name, num, "Current") {}
    
    void deposit(float amount)
    {
      balance += amount;
      std::cout << "Deposit of amount " << amount << " is successful\n";
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

        std::cout << "Withdraw of amount " << amount << " is successful\n";
      }
    }
};

class sav_acct : public acct
{
   int date, month, year;
  public:
    sav_acct(char *name, int num): acct(name, num, "Savings") 
    {
      std::cout << "Account created\n\n";
    }

    void deposit(float amount)
    {
      std :: cout << "Enter today's date (date, month, year): ";
      std :: cin >> date >> month >> year;

      balance += amount;
      std::cout << "Deposit of amount " << amount << " is successful\n";
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
        std::cout << "Withdraw of amount " << amount << " is successful\n";
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
#if 1
  int sav_acct_num;
  char name1[40];
  std::cout << "Enter Name:";
  fgets(name1, sizeof(name1), stdin); 

  std::cout << "Enter account number:";
  std::cin>>sav_acct_num;

  sav_acct sav(name1, sav_acct_num);
  sav.display_balance();
  sav.deposit(5000);
  sav.display_balance();
  sav.withdraw(1000);
  sav.display_balance();
  sav.compute_and_deposit_interest();
  sav.display_balance();
#endif 

  // Clear the input buffer
  std::cin.ignore();

  char name2[40];
  std::cout << "Enter Name:";
  fgets(name2, sizeof(name2), stdin);
  
  int cur_acct_num;
  std::cout << "Enter account number:";
  std::cin>>cur_acct_num;

  cur_acct cur(name2, cur_acct_num);
  cur.display_balance();
  cur.deposit(6000);
  cur.display_balance();
  cur.withdraw(500);
  cur.display_balance();
  cur.withdraw(3000);
  cur.display_balance();
  return 0;
}
