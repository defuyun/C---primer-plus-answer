#include<iostream>
#include<string>
#include<climits>
#include<cstring>

//1.
void print(const char *str){
    std::cout << str << std::endl;
}

void print(const char *str, int n){
    static int counter = 0;
    counter++;
    if (n){
        for (int count = 0; count < counter; count++){
            std::cout << str << std::endl;
        }
    }
}

void testPrint(){
    char test[20] = "Hello!";
    print(test);
    print(test, 1);
    print(test, 2);
    print(test, 3);
}

//2.
struct CandyBar{
    std::string name;
    double weigh;
    int calory;
};

void initCandy(CandyBar &candy, const char* name = "Millenium Munch", 
                              double weigh = 2.85, int calory = 250){
    candy.name = name;
    candy.weigh = weigh;
    candy.calory = calory;
}

void printCandy(CandyBar &candy){
    std::cout << "Brand name: " << candy.name << "\nWeigh: " 
              << candy.weigh << "\nCalory: " << candy.calory 
              << std::endl;
}

//3.
void capitalize(std::string &str){
    for (int i = 0; str[i] != '\0'; i++){
        if (isupper(str[i])){
            str[i] = (char)toupper(str[i]);
        }
    }
}

void checkCap(){
    std::string str;
    std::cout << "Enter a string(q to quit): ";
    std::getline(std::cin, str);
    while (str != "q"){
        capitalize(str);
        std::cout << str << std::endl
            << "Next string(q to quit): ";
        std::getline(std::cin, str);
    }
}

//4.
struct stringy{
    char *str;
    int ct;
};

void set(stringy &str,char *test){
    str.ct = strlen(test);
    str.str = new char[str.ct + 1];
    strcpy(str.str, test);
}
void show(const char *str, int n = 1){
    int count = 0;
    while (count<n){
        std::cout << str << std::endl;
        count++;
    }
}
//using reference to save space, doesn't have to be.
void show(const stringy &str, int n = 1){
    int count = 0;
    while (count<n){
        std::cout << str.str << std::endl;
        count++;
    }
}

//5.
template<typename T>
T max5(T arr[]){
    T large = arr[0];
    for (int index = 0; index < 5; index++){
        if (arr[index] > large){
            large = arr[index];
        }
    }
    return large;
}

void testMax5(){
    int mat[] = { 1, 2, 3, 4, 5 };
    double mad[] = { 1.0, 2.0, 3.0, 4.0, 6.0 };
    std::cout << max5(mat) << " " << max5(mad) << std::endl;
}

//6.
template<typename T>
T maxn(T arr[], int n){
    T large = arr[0];
    for (int index = 0; index < n; index++){
        if (arr[index] > large){
            large = arr[index];
        }
    }
    return large;
}

template<>
char *maxn(char *arr[], int n){
    int large = strlen(arr[0]);
    int largeIndex = 0;
    for (int index = 0; index < n; index++){
        if (strlen(arr[index]) > large){
            large = strlen(arr[index]);
            largeIndex = index;
        }
    }

    return arr[largeIndex];
}

void testMaxn(){
    int mat[] = { 1, 2, 3, 4, 5, 6 };
    double mad[] = { 1.0, 2.0, 3.0, 4.0 };
    std::cout << maxn(mat,6) << " " << maxn(mad,4) << std::endl;

    char *arr[] = { "Spring", "Autumn", "Summer", "Thisisverylong" };
    std::cout << maxn(arr, 4) << std::endl;
}

//7.

template<typename T>
T sumArray(T arr[],int n){
    std::cout << "template A\n";
    T sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

template<typename T>
T sumArray(T *arr[], int n){
    std::cout << "template B\n";
    T sum = 0;
    for (int i = 0; i < n; i++){
        sum += *arr[i];
    }
    return sum;
}
