#include<iostream>
#include<string>
#include<cstring>

//1.
class bank_account{
public:
    bank_account();
    bank_account(std::string deposit_name, int account, double balance = 0){
        name = deposit_name;
        this->account = account;
        this->balance = balance;
    }
    void display(){
        std::cout << "Account name is " << name
            << "\nAcount number = " << account
            << "\nbalance = " << balance << std::endl;
    }
    void diposit(double cash){
        balance += cash;
    }
    void withdraw(double cash){
        if (balance < 0){
            std::cout << "currently there is no saving in this account\n";
        } else if(cash > balance){
            std::cout << "You don't have enough money\n";
        } else {
            balance -= cash;
        }
    }
    ~bank_account();
private:
    std::string name;
    int account;
    double balance;
};
 
void bak(){
    bank_account newaccount("Ork", 110);
    std::cout << "What would you like to do:\n";
    std::cout << "1.deposit          2.withdraw";
    int option;
    switch (option){
    case 1:
        std::cout << "How much would you like to deposit: ";
        double cash;
        std::cin >> cash;
        newaccount.diposit(cash);
    case 2:
        std::cout << "How much would you like to withdraw: ";
        double cash;
        std::cin >> cash;
        newaccount.withdraw(cash);
    }

    newaccount.display();
}

//2.
class Person{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person(){
        lname = "";
        fname[0] = '\0';
    }
    Person(const std::string &ln, const char *fn = "Heyyou"){
        lname = ln;
        strcpy(fname, fn);
    }
    void show() const{
        std::cout << "First name is " << fname << "\nLast name is"
            << lname << std::endl;
    }
    void FormalShow()const{
        std::cout << "First name is " << lname << "\nLast name is"
            << fname << std::endl;
    }
};

//3.
class golf{
private:
    static const int LEN = 40;
    char fullname[LEN];
    int handicap;
public:
    golf(char *name, int hc){
        strcpy(fullname, name);
        handicap = hc;
    }

    void setgolf(){
        char temp[LEN];
        int hand;
        std::cout << "please enter a name\n";
        std::cin.getline(temp, 40);
        std::cout << "Please enter handicap: ";
        std::cin >> hand;
        golf::golf(temp, hand);
    }

    void handicap(int hc){
        handicap = hc;
    }

    void  showgolf(){
        std::cout << "Fullname is " << fullname <<
            "\nHandicap = " << handicap << std::endl;
    }
};

//4.
namespace SALES{
    class sales{
    public:
        sales(const double ar[], int n){
            min = max = ar[0];
            average = 0;
            for (int i = 0; i < n; i++){
                sale[i] = ar[i];
                if (ar[i]>max){
                    max = ar[i];
                }
                if (ar[i] < min){
                    min = ar[i];
                }
                average += ar[i];
            }
            while (n < QUARTERS){
                sale[n] = 0;
                n++;
            }
            average /= QUARTERS;
        }
        sales(){
            std::cout << "Please enter sales: ";
            double input;
            std::cin >> input;
            average = max = min = input;
            for (int i = 0; i < QUARTERS; i++){
                std::cin >> input;
                if (input > max){
                    max = input;
                }
                if (input < min){
                    min = input;
                }
                average += input;
            }
            average /= 4;
        }
        void showsales(){
            for (int i = 0; i < QUARTERS; i++){
                std::cout << "Sales for season " <<
                    i + 1 << " is " << sale[i] << std::endl;
            }
            std::cout << "\nMax sales is " << max;
            std::cout << "\nMin sales is " << min;
            std::cout << "\nAverage sales is " << average << std::endl;
        }
    private:
        static const int QUARTERS = 4;
        double average;
        double max;
        double min;
        double sale[QUARTERS];
    };
}

//5.
struct customer{
    char fullname[35];
    double payment;
};

class Stack{
public:
    Stack(){
        bottom = new customer[LEN];
        top = bottom;
        stackSize = 40;
    }
    ~Stack(){
        delete[stackSize]bottom;
    }
    void push(customer &c){
        if (top - bottom > stackSize){
            std::cout << "Not enough space\n";
        } else {
            *top = c;
            top++;
        }
    }
    customer pop(){
        return *(top--);
    }
private:
    static const int LEN = 40;
    customer *top;
    customer *bottom;
    int stackSize;
};

//6.
class Move{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0){
        x = a;
        y = b;
    }
    void showmove()const{
        std::cout << "x = " << x << "\ny = "
            << y << std::endl;
    }
    Move add(const Move &m) const{
        Move *newMove = new Move;
        newMove->x = this->x + m.x;
        newMove->y = this->y + m.y;
        return *newMove;
    }
    void reset(double a = 0, double b = 0){
        x = a;
        y = b;
    }
};

void useMove(){
    Move something(0, 0);
    Move stuff(10, 10);
    something = something.add(stuff);
    something.reset(0, 0);
    something.showmove();
}

//7.
class plorg{
private:
    std::string name;
    int CI;
public:
    plorg(){
        name = "Plorga";
        CI = 50;
    }
    plorg(std::string name, int CI){
        this->name = name;
        this->CI = CI;
    }
    void changeCI(int CI){
        this->CI = CI;
    }
    void display(){
        std::cout << "My name is " << name << " and "
            " my CI is " << CI << std::endl;
    }
};

void usePlorg(){
    plorg newplorg;
    plorg secplorg("Amy",10);
    newplorg.changeCI(10);
    secplorg.display();
}

//8.
template<typename ITEM>
class list{
public:
    list(){
        listSize = 0;
    }
    void add(ITEM a){
        element[listSize] = a;
        listSize++;
    }
    bool empty(){
        if (listSize == 0){
            return true;
        } else{
            return false;
        }
    }
    bool full(){
        if (listSize >= size){
            return true
        } else {
            return false;
        }
    }
    void visit(void (*pf)(ITEM &a)){
        for (int i = 0; i < listSize; i++){
            pf(element[i]);
        }
    }
private:
    static const int size = 40;
    ITEM element[size];
    int listSize;
};
