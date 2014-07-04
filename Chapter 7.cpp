#include<iostream>
#include<array>
#include<cstring>
#include<string>

//1.
double reconcile_mean(double x,double y){
    return ((2 * x*y) / (x + y));
}
void consistent(){
    double x, y;
    std::cout << "Please enter 2 numbers: ";
    std::cin >> x >> y;
    while (x != 0 && y != 0){
        std::cout << reconcile_mean(x, y) << std::endl;
        std::cin >> x >> y;
    }
}

//2.
double mean(std::array<int, 10>stuff){
    double mean = 0;
    int i = 0;
    for (; stuff[i] != 0; i++){
        mean += stuff[i];
    }
    return(mean / (i - 1));
}

void input(std::array<int, 10>*in){
    std::cout << "Enter at most 10 scores, 0 to end\n";
    int x = 0;
    std::cin >> (*in)[x];
    for (x = 0; ((*in)[x] != 0&& x<8); x++){
        std::cin >> (*in)[x+1];
    }
}
void ouput(std::array<int, 10>out){
    for (int i = 0; out[i] != 0; i++){
        std::cout << out[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Your mean is " << mean(out) << std::endl;
}

//3.
struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void out(box something){
    std::cout << "Maker = " << something.maker << std::endl
        << "height = " << something.height << std::endl
        << "width = " << something.width << std::endl
        << "lenght = " << something.length << std::endl
        << "volume = " << something.volume << std::endl;
}

void getVolume(box *something){
    something->volume = (something->height*something->width * something->length);
}

void doSomething(){
    box something;
    std::cout << "Please enter the maker: ";
    std::cin.getline(something.maker, 40);

    std::cout << "Please enter the Height, width and length of a cube: ";
    std::cin >> something.height >> something.width >> something.length;

    getVolume(&something);
    out(something);
}

//4.
long double probability(unsigned numbers, unsigned picks,unsigned numbers2,unsigned picks2){
    return (numbers*1.0 / picks)*(numbers2*1.0 / picks2);
}

void lotto(){
    int field_number, choices;
    int field_number2, choices2;
    std::cout << "Enter the toaal number of choices on the game card\n"
                 "and the number of picks aviablale\n";

    while ((std::cin >> field_number >> choices) && choices <= field_number
        && (std::cin >> field_number2 >> choices2) && choices2 <=field_number2){
        std::cout << "You have 1 chance in " << probability(field_number, choices,field_number2,choices2)
            << " of winning.\n" << "Next 4 number(character to quit): ";
    }
    std::cout << "bye\n";
}

//5.
int factorial(int num){
    int fac = 1;
    if (num > 0){
        fac = num*factorial(num - 1);
    }
    return fac;
}

//6.
int Fill_array(double arr[], int n){
    std::cout << "Please enter a array of " << n << " elements\n";
    int count = 0;
    for (int i = 0; (i < n && std::cin >> arr[i]); i++){
        count++;
    }
    return count;
}

void Show_array(const double arr[], int n){
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Reverse_array(double arr[], int n){
    for (int i = 0; i < n / 2; i++){
        double temp = arr[n - 1 - i];
        arr[n - 1 - i] = arr[i];
        arr[i] = temp;
    }
}

void doStuff(){
    double arr[5] = { 0 };
    int count =  Fill_array(arr, 5);
    Show_array(arr,count);
    Reverse_array(arr, count);
    Show_array(arr, count);

    //to the Reverse function arr[1] becomes the head
    //of the array, so it interprets it as arr[0] and starts counting 
    //from the 1st element
    //e.g.
    //in doStuff arr[] = 5,4,3,2,1 and arr[1] is the address of 4
    //count - 1 = 4 which is the index of 1
    //to the reverse function arr = 4,3,2,1;
    //and arr[0] is 4, here count - 1 = 4 but is the index of something random
    //arr[0] = 4;
    //arr[1] = 3;
    //arr[2] = 2;
    //arr[3] = 1;
    //when you use this number in the reverse function, it will still access the
    //last element (4-1-0 = 3 which is the index of 1) and we don't want that, 
    //that's why we pass in count-2 instead of count -1;
    Reverse_array(&arr[1], count - 2);
    Show_array(arr, count);
}

//7.
const int Max = 5;
int fill_array(double *beg, double *end){
    double temp;
    int i;
    for (i = 0; beg != end ; beg++,i++){
        std::cout << "Enter value #" << (i + 1) << ":";
        std::cin >> temp;
        if (!std::cin){
            std::cin.clear();
            while (std::cin.get() != '\n'){
                continue;
            }
            std::cout << "Bad input, input terminate\n ";
            break;
        } else if (temp < 0){
            break;
        }
        *beg = temp;
    }
    return i;
}

void show_array(const double *beg,const double *end){
    for (int i = 0; beg!=end; beg++, i++){
        std::cout << "Property #" << (i + 1) << ":$ "
            << *beg << std::endl;
    }
}

void revalue(double r, double *beg, double *end){
    for (int i = 0; beg != end; beg++, i++){
        *beg *= r;
    }
}


//8a.
const char *Snames[] = { "Spring", "Summer", "Fall", "Winter" };

void fill(double *pa,int n){
    for (int i = 0; i < n; i++){
        std::cout << "Enter " << Snames[i] << "expenses: ";
        std::cin >> pa[i];
    }
}

void show(const double *pa, int n){
    double total = 0.0;
    std::cout << "\nExpenses\n";
    for (int i = 0; i < n; i++){
        std::cout << Snames[i] << ": $" << pa[i] << std::endl;
        total += pa[i];
    }
    std::cout << "Total expenses: $" << total << std::endl;
}

//8b.
struct expense{
    double expen;
};

void fill(expense *pa, int n){
    for (int i = 0; i < n; i++){
        std::cout << "Enter " << Snames[i] << "expenses: ";
        std::cin >> pa[i].expen;
    }
}

void show(const expense *pa, int n){
    double total = 0.0;
    std::cout << "\nExpenses\n";
    for (int i = 0; i < n; i++){
        std::cout << Snames[i] << ": $" << pa[i].expen << std::endl;
        total += pa[i].expen;
    }
    std::cout << "Total expenses: $" << total << std::endl;
}


//9
const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        std::cout << "Enter fullname #" << i + 1 << "\n";
        std::cin.getline(pa[i].fullname, SLEN);
        
        if (!strcmp(pa[i].fullname, "")){
            break;
        }

        std::cout << "Enter hobby #" << i + 1 << "\n";
        std::cin.getline(pa[i].hobby, SLEN);
        std::cout << "Enter ooplevel #" << i + 1 << "\n";
        (std::cin >> pa[i].ooplevel).get();
        count++;
    }
    return count;
}

void display1(student st){
    std::cout << "Fullname: " << st.fullname << "\n"
        << "hobby: " << st.hobby << "\n"
        << "ooplevel: " << st.ooplevel << "\n";
}

void display2(const student *pa){
    std::cout << "Fullname: " << pa->fullname << "\n"
        << "hobby: " << pa->hobby << "\n"
        << "ooplevel: " << pa->ooplevel << "\n";
}

void display3(const student pa[], int n){
    for (int i = 0; i < n; i++){
        std::cout << "Fullname: " << (pa+i)->fullname << "\n"
            << "hobby: " << (pa+i)->hobby << "\n"
            << "ooplevel: " << (pa+i)->ooplevel << "\n\n";
    }
}

//10.
int enter = 1;
double add(double x, double y){
    std::cout << "The sum of " << x << " and " << y << " is ";
    return (x + y);
}
double multiply(double x, double y){
    std::cout << "The product of " << x << " and " << y << " is ";
    return(x*y);
}
double power(double x, double y){
    if (enter){
        std::cout << x << " to the power of " << y << " is ";
        enter = 0;
    }
    if (y > 1)
        x *= power(x, y - 1);
    return x;
}
double calculate(double x, double y, double (*p)(double x, double y)){
    return p(x, y);
}

void run(){
    double(*p[3])(double x, double y) = { &add, &multiply, &power };
    double x, y;
    std::cout << "Please enter 2 values: ";
    while (std::cin >> x >> y){
        for (int i = 0; i < 3; i++){
            std::cout << calculate(x, y, p[i]) << std::endl;
            enter = 1;
        }
    }
}
