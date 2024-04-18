#include <iostream>

class FLOAT
{
    float data;
  public:
    FLOAT() { data = 0.0; }
    FLOAT(float a) { data = a; }

    FLOAT operator+(float num) { std::cout << "+\n"; return (data + num); }
    FLOAT operator-(float num) { std::cout << "-\n"; return (data - num); }
    FLOAT operator*(float num) { std::cout << "*\n"; return (data * num); }
    FLOAT operator/(float num) { std::cout << "/\n"; return (data / num); }

    void display() { std::cout << data << "\n"; }
     
};

int main()
{
  FLOAT obj(7.5);
  obj.display();

  obj = obj + 2.5;
  obj.display();
  
  obj = obj - 5.0;
  obj.display();

  obj = obj * 1.5;
  obj.display();

  obj = obj / 2.5;
  obj.display();
  
  return 0;
}
