#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

//1.
void usvector(){
    using VECTOR::vector;

    srand(time(0));
    std::ofstream stuff("file.txt",std::ofstream::app | std::ofstream::out);

    double direction;
    vector step;
    vector result(0, 0);
    unsigned long steps = 0;
    double target;
    double dstep;
    std::cout << "Enter target distance (q to t0 quit): ";
    while (std::cin >> target){
        std::cout << "Enter step lenght: ";
        if (!(std::cin >> dstep)){
            break;
        }
        stuff << "Target distance = " << target << ", Step Size = " << dstep << "\n";
         while (result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, vector::POL);
            result = result + step;
            stuff << steps << ": " << result << "\n";
            std::cout << steps << ": " << result << "\n";
            steps++;
        }

        stuff<< "After " << steps << " steps the subject "
            "has the following location:\n";
        stuff<< result << std::endl;
        result.polar_mode();
        stuff<< "or\n" << result << std::endl;

        stuff<< "average outward distance per step = "
            << result.magval() / steps << std::endl;
        steps = 0;
        result.reset(0, 0);
        std::cout << "Enter target distance (q to quit): ";
    }
    std::cout << "Bye!\n";
    std::cin.clear();
    std::cin.sync();
    stuff.close();
}

//2.
namespace VECTOR{
    class vector{
    public:
        enum mode{ RECT, POL };
    private:
        double x;
        double y;
        mode m;

    public:
        vector();
        vector(double n1, double n2, mode form = RECT);
        void reset(double n1, double n2, mode form = RECT);
        double xval()const{
            return x;
        }
        double yval()const{
            return y;
        }
        double magval()const{
            return std::sqrt(x*x + y*y);
        }
        double angval()const{
            return atan2(y,x);
        }
        void polar_mode();
        void rect_mode();
        vector operator+(const vector &b)const;
        vector operator-(const vector &b)const;
        vector operator-()const;
        vector operator*(double)const;
        friend vector operator*(double n, const vector &a);
        friend std::ostream &operator<<(std::ostream &os, const vector &v);
    };
}

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR{
    const double rad_to_deg = 45.0 / atan(1.0);


    vector::vector(){
        x = y = 0;
        m = RECT;
    }

    vector::vector(double n1, double n2, mode form){
        m = form;
        if (form == RECT){
            x = n1;
            y = n2;
        }
        else if (form = POL){
            x = n1 * cos(n2);
            y = n1 * sin(n2);
        }
        else {
            cout << "Incorrect argument\n";
            x = y = 0;
            m = RECT;
        }
    }

    void vector::reset(double n1, double n2, mode form){
        *this = vector(n1, n2, form);
    }

    void vector::polar_mode(){
        m = POL;
    }

    void vector::rect_mode(){
        m = RECT;
    }

    vector vector::operator+(const vector &b)const{
        return vector(x + b.x, y + b.y);
    }
    vector vector::operator-(const vector &b)const{
        return vector(x - b.x, y - b.y);
    }

    vector vector::operator-()const{
        return vector(-x ,-y);
    }
    vector vector::operator*(double n)const{
        return vector(n*x, n*y);
    }

    vector operator*(double n, const vector &a){
        return a*n;
    }

    std::ostream &operator<<(std::ostream &os, const vector &v){
        if (v.m == vector::RECT){
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        } else if (v.m == vector::POL){
            os << "(m,a) = (" << v.magval() << ", " << v.angval() * rad_to_deg << ")";
        } else {
            os << "vector object is invalid";
        }
        return os;
    }
}

//3.
void usevector(){
    using VECTOR::vector;

    srand(time(0));
    std::ofstream stuff("file.txt");

    double direction;
    vector step;
    vector result(0, 0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int frequency;

    int large = 0;
    int min;
    double average = 0;

    std::cout << "Enter target distance (q to t0 quit): ";
    std::cin >> target;
    std::cout << "Enter step lenght: ";
    std::cin >> dstep;
    std::wcout << "Enter number of trials: ";
    std::cin >> frequency;

    stuff << "Target distance = " << target << ", Step Size = " << dstep << ", trial = " << frequency << "\n";
    int n = 0;
    while (n++ < frequency){
        while (result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, vector::POL);
            result = result + step;
            stuff << steps << ": " << result << "\n";
            std::cout << steps << ": " << result << "\n";
            steps++;
        }
        if (large < steps){
            large = steps;
        }

        if (n == 1 || min > steps){
            min = steps;
        }

        average += steps;
        average /= n;

        stuff << "After " << steps << " steps the subject "
            "has the following location:\n";
        stuff << result << std::endl;
        result.polar_mode();
        stuff << "or\n" << result << std::endl;

        stuff << "average outward distance per step = "
            << result.magval() / steps << std::endl;
        steps = 0;
        result.reset(0, 0);
    }

    stuff << "Largest number of steps for " << frequency << " trials is " << large << "\nMin number of steps is " << min
        << "\nand average number of steps is " << average << std::endl;

    std::cout << "Bye!\n";
    std::cin.clear();
    std::cin.sync();
    stuff.close();
}

//4.
namespace TIME{
    class Time{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void reset(int h = 0, int m = 0){
            hours = h;
            minutes = m;
        }

        friend Time operator+(const Time &a, const Time &t){
            return Time(a.hours + t.hours + (a.minutes + t.minutes) / 60, (a.minutes + t.minutes) % 60)
        }
        friend Time operator-(const Time &a, const Time &t){
            int s = a.hours * 60 + t.hours * 60;
            return Time(s / 60, s % 60);
        }
        friend Time operator*(const Time &a, double n){
            int s = a.hours * 60 * n + a.minutes*n;
            return Time(s / 60, s % 60);
        }
        friend Time operator*(double n, const Time &a){
            return (a*n)
        }
    };
}

//5.
namespace STONE{
    class stonewt{
    private:
        enum mode{STN,LBS};
    private:
        enum{lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
        mode m;
    public:
        stonewt(double lbs);
        stonewt(int stn, double lbs);
        stonewt();

        stonewt operator+(const stonewt t)const{
            return stonewt(stone + t.stone, pounds + t.pounds);
        }
        stonewt operator-(const stonewt t)const{
            return stonewt(stone - t.stone, pounds - t.pounds);
        }
        stonewt operator*(const stonewt t)const{
            return stonewt(stone * t.stone, pounds * t.pounds);
        }
        
        friend std::ostream &operator<<(std::ostream &os, const stonewt &a){
            if (a.m == stonewt::STN){
                os << a.stone << " stone, " << a.pds_left << " pounds";
            } else if (a.m == stonewt::LBS){
                os << a.pounds << " pounds\n"
            }
        }
    };
}

//6.
class stonewt{
private:
    enum{lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    stonewt(int stone,int pounds){
        this->stone = stone;
        this->pounds = pounds+stone*14;
    }
    bool operator<(const stonewt t)const{
        return pounds < t.pounds ? true : false;
    }
    bool operator>(const stonewt t)const{
        return pounds > t.pounds ? true : false;
    }
    bool operator==(const stonewt t)const{
        return pounds == t.pounds ? true : false;
    }
    bool operator<=(const stonewt t)const{
        return pounds <= t.pounds ? true : false;
    }
    bool operator>=(const stonewt t)const{
        return pounds >= t.pounds ? true : false;
    }
    friend std::ostream &operator<<(std::ostream &os, const stonewt &a){
        os << stone << " stone, " << pounds << ", pounds";
        return os;
    }
}

void usestone(){
    stonewt stuff[6];
    stuff[0] = stonewt(1,2);
    stuff[1] = stonewt(4,5);
    stuff[2] = stonewt(6,7);
    int n = 3;
    int stone, pound;
    while(n < 6){
        std::cout << "Please input stone: ";
        std::cin >> stone;
        std::cout << "Please input pounds: ";
        std::cin >> pound;
        stuff[n] = stonewt(stone,pound);
        n++;
    }
    stonewt large,min;
    stonewt elev(11,0);
    large = min = stuff[0];
    
    n = 0;
    int counter = 0;
    while(n < 6){
        if(large<stuff[n]){
            large = stuff[n];
        }
        if(min > stuff[n]){
            min = stuff[n];
        }
        if(stuff[n] > elev){
            counter++;
        }
    }
    std::cout << "largest stone is " << large << " smallest stone is " << min;
    std::cout << "\nthere are " << counter << "greater than 11\n";
}
