#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/*
    Chapter 2, 2.7 
*/

//1.编写一个C++程序,它显示您的姓名和地址
void printAddressName(){
    std::cout << "Name " << "MyName\nAddress " << "Mars" << endl;
}

//2.编写一个程序，要求用户输入一个long单位的距离,然后将它转换为码(1 long = 220码)
void longToYard(){
    int longs;
    cout << "input a long measurment and we would convert it to yards: ";
    cin >> longs;
    cout << longs << " is " << longs * 220 << " yards\n";
}

/*
    3.编写一个程序,使用3个用户定义的函数（包括main），并称生下面的输出:
    Three blind mice
    Three blind mice
    See how they run
    See how they run
    每个函数调用两次
*/
void printmice(){ 
    cout << "Three blind mice\n"; 
}
void printrun(){
    cout << "See how they run\n"; 
}
void print(){
    printmice(); 
    printmice();
    printrun(); 
    printrun();
}

//4.编写一个程序,让用户输入年龄,然后显示改年龄包含多少个月
//Enter your age: 29
void calmonth(){
    int year;
    cout << "Enter your age\n";
    cin >> year;
    cout << "The number of months you have lived = " << year * 12 << endl;
}

//5.编写一个程序,其中的main()调用一个用户定义的函数(以摄氏温度值为参数,并返回华氏温度值)。该程序按照下面的格式
//要求用户输入摄氏温度值,并显示其结果:
//please enter a celsius value: 20
//20 degrees celsuis is 68 degree Fahrenheit

void CtoF(){
    cout << "please enter a celsius value: ";
    int c;
    cin >> c;
    cout << c " degrees celsuis is " << 1.8*c + 32 << " degree Fahrenheit\n";
}

//6.编写一个程序,其main()调用一个用户定义的函数(以光年值为参数,并返回对应天文单位的值)改程序按下面的格式要求用户输入光年值，并显示结果:
//Enter the number of light years: 4.2
//4.2 light years = 265608 astronomical units.

void LtoA(){
    cout << "Enter the number of light years: ";
    double l;
    cin >> l;
    cout << l " 4.2 light years = " << 63240*l << " astronomical units.\n";
}

/*7.要求用户输入小时和分钟，在main里将这两个值传递给一个void函数,后者以下面这样的格式显示这两个数
    Enter the number of hours: 9
    Enter the number of minutes: 28
    Time: 9:28
*/

void printime(){
    int hour, minute;
    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minute;
    cout >> "Time: " >> hour >> ":" >> minute >> endl;
}
