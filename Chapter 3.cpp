#include<iostream>
#include<assert.h>
#include<climits>

using std::cout;
using std::cin;
using std::endl;

//1.
void height(){
    const short exRate = 12;
    cout << "Enter you height in inch:____\b\b\b\b";
    int inch;
    cin >> inch;
    cout << "Your height in foot = " << inch*exRate << endl;
}

//2.
void BMIs(){
#define BMI(x,y) (x*1.0/y)*(x*1.0/y)
    const short exInchToFoot = 12;
    const float exFootToMeter = 0.0254;
    const double exPoundToKilo = (1 / 2.2);

    double heightInch, weight, heightFoot;
    cout << "Height in inch: ";
    cin >> heightInch;
    cout << "Height in Foot: ";
    cin >> heightFoot;
    cout << "Weight in pound: ";
    cin >> weight;
    assert(heightInch != 0 && heightFoot != 0); //保证不出现除以0的情况 会崩溃
    cout << "Your BMI is: " << BMI((weight*exPoundToKilo), ((heightInch*exInchToFoot + heightFoot)*exFootToMeter)) << endl;
}

//3.
void degree(){
    const short exRate = 60;
    cout << "Enter a latitude in degrees, minutes, and seconds:\n";
    cout << "First, enter the degree: ";
    double degree,minutes,seconds;
    cin >> degree;
    cout << "Next,enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;
    cout << degree << " degrees, " << minutes << " minutes, " << seconds << " seconds = " <<
        degree + minutes / exRate + seconds / (exRate*exRate) << " degrees\n";
}

//4.
void sectime(){
    const int exSecToDay = 86400;
    const short exSecTohour = 3600;
    const short exSecToMin = 60;
    int second;
    cout << "Enter the number of seconds: ";
    cin >> second;

    //注:假如前面second声明为浮点型(float,double)则需要强制转换(int)(second / exSecToDay)
    cout << second << " seconds = " << (second / exSecToDay) << " days, " << ((second%exSecToDay) / exSecTohour)
        << " hours, " << (((second%exSecToDay) % exSecTohour) / exSecToMin) << " minutes, "
        << (((second%exSecToDay) % exSecTohour) % exSecToMin) << " seconds";
}

//5.
void USPop(){
    cout << "Enter the world's population: ";
    int worldpop;
    cin >> worldpop;
    cout << "Enter the population of the US: ";
    int USpop;
    cin >> USpop;
    cout << "THe population of the US is " << (USpop*1.0 / worldpop) * 100 << "% of the world population.\n";
}

//6.
void gasKilo(){
    cout << "Enter distance drove[in kio]: ";
    double distance;
    cin >> distance;
    cout << "Enter gas used[in litre]: ";
    double gas;
    cin >> gas;
    cout << "gas per kilo = " << gas/distance << endl;
}

//7.
void EuroToUS(){
    const double exKiloToMile = 0.6214;
    const double exLtoGalon = 1/3.875;

    cout << "Enter litre consumed for 100Kilo: ";
    double litre;
    cin >> litre;
    cout << "gas per kilo Euro = " << litre / 100 << "l/km\n";
    cout << "gas per kilo US = " << (litre / 100)*(exKiloToMile / exLtoGalon)<<" mile/gal\n";
}
