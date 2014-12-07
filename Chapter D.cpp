#include<iostream>
#include<string>
#pragma warning(disable:4996)

/*
    chapter review
    1. everything except constructor and destructor
    2. constructor and destructor
    3. the whole thing would not work
        a copy constructor is invoked because parse by value takes place
    4. base-con
        derive-con
        derive-del
        base-del
    5. no
    6. derived one
    7. when the derive one has more data member then base
    8. Yes,no
    9. Yes,no
   10. because the derive one contains everything in the base one so there isn't any problem
   11. same as above
   12. efficient
   13. a. use base function
        b. use derive func
   14. House access private member in Kitchen
*/

//1. 2.
class Cd{
private:
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    Cd(char *s1, char *s2, int n, double x) :selections(n), playtime(x){
        performers = new char[strlen(s1) + 1];
        label = new char[strlen(s2) + 1];
        strcpy(performers, s1);
        strcpy(label, s2);
    }

    Cd(const Cd & d) :selections(d.selections), playtime(d.playtime){
        performers = new char[strlen(d.performers) + 1];
        label = new char[strlen(d.label) + 1];
        strcpy(performers, d.performers);
        strcpy(label, d.label);
    }

    Cd(){
        performers = nullptr;
        label = nullptr;
        selections = 0;
        playtime = 0;
    }

    ~Cd(){
        delete[] performers;
        delete[] label;
        selections = 0;
        playtime = 0;

    }

    virtual void report()const{
        if (performers == nullptr || label == nullptr)return;
        std::cout << performers << "\n" << label << "\n" << selections << "\n" << playtime << "\n";
    }

    Cd & operator=(const Cd & d){
        std::cout << "Invoked" << std::endl;
        delete[]performers;
        delete[]label;

        performers = new char[strlen(d.performers) + 1];
        label = new char[strlen(d.label) + 1];

        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;

        return *this;
    }
};

class Classic :public Cd{
private:
    std::string primary_work;
public:
    Classic():Cd(){};
    Classic(std::string s, char *s1, char *s2, int n, double x) :Cd(s1, s2, n, x), primary_work(s){};
    virtual void report()const{
        Cd::report();
        std::cout << "primary work is " << primary_work << std::endl;
    }
};

void useClasssic(){
    Classic p("Hi", "Im", "Here", 1, 2);
    Cd a("Hi", "llo", 1, 2);

    Classic n;
    Cd b;

    n = p;
    n.report();

    b = p;
    b.report();

    b = a;
    b.report();
    system("pause");
}

//4.
//a.
class Port{
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char *br = "none", const char *st = "none", int b = 0) :bottles(b){
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
        strncpy(style, st, 19);
    }
    Port(const Port & p) :bottles(p.bottles){
        delete[]brand;
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
        strncpy(style, p.style, 19);
    }

    virtual ~Port(){ delete[] brand; }

    Port & operator=(const Port & p){
        delete[]brand;
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
        strncpy(style, p.style, 19);
    }

    Port & operator+=(int b){
        bottles += b;
        return *this;
    }

    Port & operator-=(int b){
        bottles -= b;
        if (bottles < 0)bottles = 0;
        return *this;
    }

    int BottleCount()const{ return bottles; }
    
    virtual void Show()const{
        std::cout << brand << " " << style << " " << bottles << std::endl;
    }

    friend std::ostream & operator<<(std::ostream & os, const Port & p){
        os << p.brand << " " << p.style << " " << p.bottles;
        return os;
    }
};

class VintagePort :public Port{
private:
    char *nickname;
    int year;
public:
    VintagePort() :Port(), year(0){
        nickname = new char[5];
        strcpy(nickname, "none");
    }

    VintagePort(const char * br,const char *st , int b, const char *nn, int y) :Port(br,st, b){
        nickname = new char[strlen(nn)+1];
        strcpy(nickname, nn);
        year = y;
    }

    VintagePort(const VintagePort & vp) :Port(vp){
        delete[]nickname;
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }

    ~VintagePort(){ delete[]nickname; }

    VintagePort & operator=(const VintagePort & vp){ 
        delete[]nickname;
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
    virtual void Show()const{ 
        Port::Show();  
        std::cout << nickname << " " << year << std::endl;
    }

    friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp){
        os << (Port)vp << vp.nickname << " " << vp.year;
    }
};

/*
    b.Constructors redefined because they are not inherited
      = and copy redefined because they have dynamic mem allo member: nickname which
      cannot be memberwise copied

      << redefined because this is not a member and if not added, the obj would be treated
      like the base-class

      show redefined because it has extra featured
   
    c.<< is not a member function, it cannot be virtual
      = is not inherited so there's no point to be virtual
   */
