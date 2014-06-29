#include<iostream>
#include<array>
#include<climits>
#include<string>
#include<cstring>

//1.
void sum(){
    int min, max,sum = 0;
    std::cout << "Input min and max: " << std::endl;
    std::cin >> min >> max;
    
    //swap them around if min > max
    if (min > max){
        min ^= max;
        max ^= min;
        min ^= max;
    }

    while (min <= max){
        sum += min;
        min++;
    }

    std::cout << "The sum is " << sum << std::endl;
}

//2.
void factorial(){
    std::array<long double, 101>fact;
    std::cout << 0 << "! = "<< (fact[0] = fact[1] = 1)<<"\n" 
        << 1<<"! = " << fact[1]<<std::endl;
    for (int i = 2; i <= 100; i++){
        std::cout << i << "! = " << (fact[i] = fact[i - 1] * i) << std::endl;
    }
}

//3.
void coutNum(){
    int num,count = 0;
    std::cout << "I will count how many numbers you've entered, enter 0 to terminate\n";
    std::cin >> num;
    while ( num!= 0){
        //check if the user entered a legal input, cin returns a bool
        //istream provides a function that turns &istream to bool type if needed
        //in this case, the function will be called and the &stream would be
        //converted into a bool
        if (!std::cin){
            std::cout << "An error has occured, you've either\n"
                "entered a character or the number is too big\n"
                "Please enter a number between " << INT_MIN << " and "
                << INT_MAX << std::endl;
            std::cin.clear(); //clear the failbit
            std::cin.sync();  //flush the input stream(cin does not fetch the input stream if error occured)
            std::cin >> num;
        } else {
            count++;
            std::cout << "You have now inputted " << count << " numbers\n";
            std::cin >> num;
        }
    }
    if (count == 0){
        std::cout << "You have now inputted " << count << " numbers\n";
    }
}

//4.
void interestRate(){
    const float intRateC = 0.05F;
    const float intRateD = 0.1F;
    double Cleo, Daphne, initialInv = 100;
    Cleo = Daphne = initialInv;
    int count = 0;
    while (Cleo < Daphne){
        Cleo *= (1 + intRateC);
        Daphne += initialInv*intRateD;
        count++;
    }

    std::cout << "after " << count << " years Cleo holds $" << Cleo
        << " and Daphne holds $" << Daphne << std::endl;
}

//5.
void sales(){
    const int size = 12;
    char* month[size] = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
    double sales[size];
    int i = 0;
    for (char* x : month){
        std::cout << "Please enter the sales for " << x << ": ";
        std::cin >> sales[i];
        i++;
    }

    double sum = 0;
    for (double x : sales){
        sum += x;
    }
    std::cout << "Sales for the year = " << sum << std::endl;
}

//6.
void sales2D(){
    const int months = 12;
    const int years = 3;
    char *time[years][months] = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" ,
                                  "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" ,
                                  "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };

    int sales[years][months],sum = 0;
    for (int year = 0; year < years; year++){
        for (int month = 0; month < months; month++){
            std::cout << "Please input the sales for " << time[year][month] << " year " << year+1<<std::endl;
            std::cin >> sales[year][month];
            sum += sales[year][month];
        }
    }
    std::cout << "Sales for the year = " << sum << std::endl;
}

//7.
struct car{
    std::string maker;
    int year;
};
void cStruct(){
    int n;
    std::cout << "enter the amount of cars: ";
    (std::cin >> n).get();
    car* Car = new car[n];
    for (int i = 0; i < n; i++){
        std::cout << "Car #" << i + 1 << ":\n";
        std::cout << "Please enter the make: ";
        std::getline(std::cin,(Car+i)->maker);
        std::cout << "Please enter the year made: ";
        (std::cin >> Car[i].year).get();
    }

    std::cout << "Here is your collection: \n";
    for (int i = 0; i < n; i++){
        std::cout << Car[i].year << " " << Car[i].maker << std::endl;
    }
    delete [n]Car;
}

//8.
void countWord1(){
    const int size = 25;
    char word[size];
    std::cout << "Enter words(to stop, type the word done):\n";
    std::cin >> word;
    int count = 0;
    while (strcmp(word,"done")){
        count++;
        std::cin >> word;
    }
    std::cout << "You entered a total of " << count << " words\n";
}

//9.
void countWords2(){
    std::string word;
    std::cout << "Enter words(to stop, type the word done):\n";
    std::cin >> word;
    int count = 0;
    while (word != "done"){
        count++;
        std::cin >> word;
    }
    std::cout << "You entered a total of " << count << " words\n";
}

//10.
void printStar(){
    int lines;
    std::cout << "Enter number of rows: ";
    std::cin >> lines;
    for (int row = 0; row < lines; row++){
        for (int col = 0; col < lines; col++){
            if (row + col >= lines - 1){
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}
