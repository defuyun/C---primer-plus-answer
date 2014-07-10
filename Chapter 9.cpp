#include<iostream>
#include<cstring>
#include"Chapter9.h"
#include<string>
#include<new>

//1.
void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g){
    std::cout << "Please enter your fullname: ";
    std::cin.getline(g.fullname, Len);
    std::cout << "Please enter handicap: ";
    std::cin >> g.handicap;
    
    if (strcmp(g.fullname, "") == 0){
        return 0;
    } else {
        return 1;
    }
}


void handicap(golf & g, int hc){
    g.handicap = hc;
}

void showgolf(const golf & g){
    std::cout << "Fullname: " << g.fullname 
        << "\nHandicap: " << g.handicap << std::endl;
}

//2.
void strcount(const std::string str)
{
    using namespace std;
    static int total = 0; // static local variable
    int count = 0; // automatic local variable
    cout << "\"" << str << "\" contains ";
    
    cout << str.size() << " characters\n";
    total += str.size();
    cout << total << " characters total\n";
}

void usestrcount(){
    using namespace std;
    std::string input;
    cout << "Enter a line:\n";
    getline(cin,input);
    while (cin){
        strcount(input);
        cout << "Enter another line:\n";
        getline(cin, input);
    }
    cout << "Bye\n";
}

//3.
struct chaff{
    char dross[20];
    int slag;
};
const int BUF = 48;
void initialize(chaff &stuff){
    std::cout << "Input dross: ";
    std::cin.getline(stuff.dross, 20);
    std::cout << "Input slag: ";
    std::cin >> stuff.slag;
}
void display(const chaff &stuff){
    std::cout << "dross: " << stuff.dross << std::endl;
    std::cout << "slag: " << stuff.slag << std::endl;
}

void option1(){
    char buffer[BUF];
    chaff *stuff = new(buffer)chaff;
    initialize(stuff[0]);
    initialize(stuff[1]);
    display(stuff[0]);
    display(stuff[1]);
}

void option2(){
    chaff *stuff = new chaff[2];
    initialize(stuff[0]);
    initialize(stuff[1]);
    display(stuff[0]);
    display(stuff[1]);
    delete[]stuff;
}

//4.
// copies the lesser of 4 or n items from the array ar
// to the sales member of s and computes and stores the
// average, maximum, and minimum values of the entered items;
// remaining elements of sales, if any, set to 0
void SALES::setSales(Sales & s, const double ar[], int n){
    double sum = 0;
    s.max = s.min = ar[0];
    for (int i = 0; i < n; i++){
        s.sales[i] = ar[i];
        sum += ar[i];
        if (ar[i] > s.max){
            s.max = ar[i];
        }
        if (ar[i] < s.min){
            s.min = ar[i];
        }
    }
    s.average = sum / QUARTERS;
    if (n < QUARTERS){
        s.sales[n] = 0;
        n++;
    }
}

// gathers sales for 4 quarters interactively, stores them
// in the sales member of s and computes and stores the
// average, maximum, and minimum values
void SALES::setSales(Sales & s){
    double max, min, sum = 0;
    for (int i = 0; i < QUARTERS; i++){
        std::cout << "Please enter sales for season " << i << ": ";
        std::cin >> s.sales[i];
        while(!std::cin){
            std::cin.clear();
            std::cin.sync();
            std::cin >> s.sales[i];
        }
    }
    s.min = s.max = s.sales[0];

    for (int i = 0; i < QUARTERS; i++){
        if (s.min > s.sales[i]){
            s.min = s.sales[i];
        }
        if (s.max < s.sales[i]){
            s.max = s.sales[i];
        }
        sum += s.sales[i];
    }

    s.average = sum / QUARTERS;
}

// display all information in structure s
void SALES::showSales(const Sales & s){
    std::cout << "Sales for 4 seasons are: ";
    for (int i = 0; i < QUARTERS; i++){
        std::cout << s.sales[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "average sale is: " << s.average << std::endl;
    std::cout << "max sale is: " << s.max << std::endl;
    std::cout << "min sale is: " << s.min << std::endl;
}
