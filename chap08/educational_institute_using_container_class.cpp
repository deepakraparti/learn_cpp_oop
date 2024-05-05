#include <iostream>
#include <iomanip>
#include <cstring>

class staff
{
  protected:
    int code;
    char name[30];

  public:
    staff(int c, char* n) 
    { 
      code = c;
      strcpy(name, n);
    }

    char* getName() {return name;}
    int getCode() {return code;}
};

class education
{
  protected:
    char highest_academic_qual[30]; 
    char highest_prof_qual[30]; 
  public:
    education(char *gen_qual, char *prof_qual)
    {
      strcpy(highest_academic_qual, gen_qual);
      strcpy(highest_prof_qual, prof_qual);
    }

    char *getAcQual() { return highest_academic_qual; }
    char *getPfQual() { return highest_prof_qual; }
};

class teacher 
{
  protected:
    staff st;
    education ed;
    char subject[20];
    char publication[20];
  public:
    teacher(char *name, int code, char *ac_qual, char *pf_qual, char *sub, char *pub) : st(code, name), ed(ac_qual, pf_qual)
    {
      strcpy(subject, sub);
      strcpy(publication, pub);
    } 

    void show(void)
    {
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Subject" << std::setw(20) << "Publication" << std::setw(25) << "Academic Qualification" << std::setw(30) << "Professional Qualification" << "\n";
      std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
      std::cout << std::setw(5) << st.getCode() << std::setw(15) << st.getName() << std::setw(15) << subject << std::setw(20) << publication << std::setw(25) << ed.getAcQual() << std::setw(30) << ed.getPfQual() << "\n\n";
    }
};

class officer
{
  protected:
    staff st;
    education ed;
    char grade[10];

  public:
    officer (char *name, int code, char *ac_qual, char *pf_qual, char *g) : st(code, name), ed(ac_qual, pf_qual) 
    { strcpy(grade, g); }

    void show(void)
    {
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Grade" << std::setw(25) << "Academic Qualification" << std::setw(30) << "Professional Qualification" << "\n";
      std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
      std::cout << std::setw(5) << st.getCode() << std::setw(15) << st.getName() << std::setw(15) << grade << std::setw(25) << ed.getAcQual() << std::setw(30) << ed.getPfQual() << "\n\n";
    }
 
};

class typist
{
  protected:
    float speed;
  public:
    typist(float s) { speed = s; }

  float getSpeed() { return speed; }

};

class regular_typist
{
  staff st;
  typist ty;
  public:
    regular_typist(char *name, int code, float s) : ty(s), st(code, name) {}

    void show()
    { 
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Speed" << std::setw(15) << "Daily Wages" << "\n";
      std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
      std::cout << std::setw(5) << st.getCode() << std::setw(15) << st.getName() << std::setw(15) << ty.getSpeed() << std::setw(15) << "\n\n";
    }
};

class casual_typist
{
    staff st;
    typist ty;
    float daily_wages;
  public:
    casual_typist(char *name, int code, float s, float w) : ty(s), st(code, name)
    { daily_wages = w; }

    void show()
    {
      std::cout << std::setw(5) << "Code" << std::setw(15) << "Name" << std::setw(15) << "Speed" << std::setw(15) << "Daily Wages" << "\n";
      std::cout << "--------------------------------------------------------------------------------------------------------------------\n";
      std::cout << std::setw(5) << st.getCode() << std::setw(15) << st.getName() << std::setw(15) << ty.getSpeed() << std::setw(15) << daily_wages << "\n\n";
    } 
};

int main()
{
  teacher t("Thomson", 123, "PhD", "AI certifiation", "C++", "ABC publications");
  t.show();

  officer o("Ramesh", 134, "HSC", "Safety Certification", "First Class");
  o.show();
  
  regular_typist rt("Gyanesh", 112, 30.0);
  rt.show();

  casual_typist ct("Ramesh", 412, 40.00, 1000.00);
  ct.show();

  return 0;
}
