#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<cstring>
#pragma warning(disable:4996)

const int size = 30;
//1.
void name(){
    std::cout << "What is your first name? ";
    char first[size];
    std::cin.get(first, size).get();
    std::cout << "What is your last name? ";
    char last[size];
    std::cin.getline(last, size);
    std::cout << "What letter grade do you deserve? ";
    char letter;
    std::cin >> letter;
    std::cout << "What is your age? ";
    int age;
    std::cin >> age;
    std::cout << "Name: " << last << ", " << first << "\nGrade: " << (char)(letter + 1) << "\nAge: " << age << std::endl;
}

//2.
void instr2(){
    const int ArSize = 20;
    std::string name;
    std::string dessert;
    std::cout << "Enter your name:\n";
    std::getline(std::cin, name);
    std::cout << "Enter your favourite desert:\n";
    std::getline(std::cin, dessert);
    std::cout << "I have some delicious " << dessert;
    std::cout << " for you, " << name << ".\n";
}

//3.
void strapp(){
    char first[size];
    char last[size];
    std::cout << "Enter your first name: ";
    std::cin.getline(first, size);
    std::cout << "Enter your last name: ";
    std::cin.getline(last, size);
    //strcat returns the address of the std::string passed as parameter 1
    std::cout << "Here's the info in a single std::string: " << strcat(strcat(last, ", "), first) << std::endl;
}

//4.
void strapp2(){
    std::string first;
    std::string last;
    std::cout << "Enter your first name: ";
    std::getline(std::cin, first);
    std::cout << "Enter your last name: ";
    std::getline(std::cin, last);
    std::cout << "Here's the info in a single std::string: " << last+", "+first << std::endl;
}

//5.
struct CandyBar{
    std::string brand;
    double weight;
    int calorie;
};

void snack(){
    CandyBar snack{ "Mocha Munch", 2.3, 350 };
    std::cout << "Brand: " << snack.brand << "\nWeight: " << snack.weight << "\nCalorie: " << snack.calorie << std::endl;
}

//6.
void snacks(){
    CandyBar snack[3];
    for (int i = 0; i < 3; i++){
        std::cout << "Enter the brand of snack " << i << ": ";
        std::getline(std::cin, snack[i].brand);
        std::cout << "Enter the weight: ";
        std::cin >> snack[i].weight;
        std::cout << "Enter the calorie: ";
        (std::cin >> snack[i].calorie).get(); //gets the \n from input stream so getline doesn't take it in
    }
    for (int i = 0; i < 3; i++){
        std::cout << snack[i].brand << " weighs " << snack[i].weight<< " and contains " << snack[i].calorie << " calorie\n";
    }
}

//7.
struct Pizza{
    std::string name;
    double d;
    double weigh;
};

void pizza(){
    Pizza pizza;
    std::cout << "Enter the brand of pizza: ";
    std::getline(std::cin, pizza.name);
    std::cout << "Enter the weight: ";
    std::cin >> pizza.weigh;
    std::cout << "Enter the diameter: ";
    std::cin >> pizza.d;
    std::cout << pizza.name << " weigh " << pizza.weigh << " with diameter " << pizza.d << std::endl;
}

//8.
void newpizza(){
    Pizza *pizza = new Pizza;
    std::cout << "Enter the diameter: ";
    (std::cin >> pizza->d).get();
    std::cout << "Enter the brand of pizza: ";
    std::getline(std::cin, pizza->name);
    std::cout << "Enter the weight: ";
    std::cin >> pizza->weigh;
    std::cout << pizza->name << " weigh " << pizza->weigh << " with diameter " << pizza->d << std::endl;
    delete pizza;
}

//9.
void newsnack(){
    CandyBar *snack = new CandyBar[3];
    for (int i = 0; i < 3; i++){
        std::cout << "Enter the brand of snack " << i << ": ";
        std::getline(std::cin, (snack+i)->brand);
        std::cout << "Enter the weight: ";
        std::cin >> snack[i].weight;
        std::cout << "Enter the calorie: ";
        (std::cin >> snack[i].calorie).get();
    }
    for (int i = 0; i < 3; i++){
        std::cout << snack[i].brand << " weighs " << snack[i].weight << " and contains " << snack[i].calorie << " calorie\n";
    }
    delete[3]snack;
}

//10.
void arrayrun(){
    std::array<double, 3>runtime;
    for (int i = 0; i < 3; i++){
        std::cout << "Please input your time for 40m: ";
        std::cin >> runtime[i];
    }
    for (int i = 0; i < 3; i++){
        std::cout << "runtime for trial " << i << " is " << runtime[i] << std::endl;
    }
}
