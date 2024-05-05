#include <iostream>
#include <iomanip>
#include <cstring>

class staff
{
  protected:
    int code;
    char name[30];

  public:
    void set_staff_details(int c, char* n) 
    { 
      code = c;
      strcpy(name, n);
    }
};

class education
{
  protected:
    char highest_academic_qual[30]; 
    char highest_prof_qual[30]; 
  public:
    void set_qualificatons(char *gen_qual, char *prof_qual)
    {
      strcpy(highest_academic_qual, gen_qual);
      strcpy(highest_prof_qual, prof_qual);
    }
};

class teacher : public staff, public education
{
  protected:
    char subject[20];
    char publication[20];
  public:
    void set_details(char *sub, char *pub)
    {
      strcpy(subject, sub);
      strcpy(publication, pub);
    } 

    void show(void)
    {
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Subject" << std::setw(20) << "Publication" << std::setw(25) << "Academic Qualification" << std::setw(30) << "Professional Qualification" << "\n";
      std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
      std::cout << std::setw(5) << code << std::setw(15) << name << std::setw(15) << subject << std::setw(20) << publication << std::setw(25) << highest_academic_qual << std::setw(30) << highest_prof_qual << "\n\n";
    }
};

class officer : public staff, public education
{
  protected:
    char grade[10];

  public:
    void set_details(char *g) { strcpy(grade, g); }
    void show(void)
    {
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Grade" << std::setw(25) << "Academic Qualification" << std::setw(30) << "Professional Qualification" << "\n";
      std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
      std::cout << std::setw(5) << code << std::setw(15) << name << std::setw(15) << grade << std::setw(25) << highest_academic_qual << std::setw(30) << highest_prof_qual << "\n\n";
    }
 
};

class typist : public staff
{
  protected:
    float speed;
  public:
    void set_speed(float s) { speed = s; }

};

class regular_typist : public typist
{
  public:
    void show()
    { 
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Daily Wages" << "\n";
      std::cout << "-----------------------------------------------------------------------\n";
      std::cout << std::setw(5) << code << std::setw(15) << name << std::setw(15) << "\n\n";
    }
};

class casual_typist: public typist
{
    float daily_wages;
  public:
    void set_wage(float w) { daily_wages = w; }

    void show()
    {
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Daily Wages" << "\n";
      std::cout << "-----------------------------------------------------------------------\n";
      std::cout << std::setw(5) << code << std::setw(15) << name << std::setw(15) << daily_wages << "\n";
    } 
};

int main()
{
  teacher t;
  t.set_staff_details(123, "Thomson");
  t.set_qualificatons("PhD", "AI certifiation");
  t.set_details("C++", "ABC publications");
  t.show();

  officer o;
  o.set_staff_details(134, "Ramesh");
  o.set_qualificatons("HSC", "Safety Certification");
  o.set_details("First Class");
  o.show();
  
  regular_typist rt;
  rt.set_staff_details(112, "Gyanesh");
  rt.show();

  casual_typist ct;
  ct.set_staff_details(345, "Ramesh");
  ct.set_wage(1000.00);
  ct.show();

  return 0;
}
