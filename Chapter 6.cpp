#include<iostream>
#include<cctype>
#include<array>
#include<string>
#include<fstream>

//1.
void convert(){
    char c;
    std::cout << "Please enter random characters\n";
    while ((c = std::cin.get()) != '@'){
        if (!isdigit(c)){
            if (islower(c))
                c = (char)toupper(c);
            else if (isupper(c))
                c = (char)tolower(c);
            std::cout << c;
        }
    }
}

//2.
void average(){
    const int size = 10;
    double sum = 0;
    std::array<double, size>donation;
    for (int count = 0; count < size; count++){
        std::cout << "Please enter donation: ";
        std::cin >> donation[count];
        sum += donation[count];
    }

    sum /= size;
    int counter  = 0;
    for (int count = 0; count < size; count++){
        if (donation[count]> sum){
            counter++;
        }
    }
    std::cout << "The average donation is " << sum << "\nand there are " << counter << " donations greater than the average\n";
}

//3.
void interface(){
    
    std::cout << "Please enter one fo the following choices:\n";
    std::cout << "c) carnivore        p) pianist\n"
                 "t) tree             g) game\n";
    char c;
    int complete = 0;
    while (!complete){
    std::cin >> c;
        switch (c){
        case 'c':
        case 'C':
            std::cout << "A meat eating duck is a carnivore\n";
            complete = !complete;
            break;
        case 'p':
        case 'P':
            std::cout << "A guy playing piano is a pianist\n";
            complete = !complete;
            break;
        case 't':
        case 'T':
            std::cout << "A maple is a tree\n";
            complete = !complete;
            break;
        case 'g':
        case 'G':
            std::cout << "Artificial Academy 3 is a game\n";
            complete = !complete;
            break;
        default:
            std::cout << "Pease enter a c,p,t,or g: ";
            break;
        }
    }
}

//4.
const int strsize = 20;
struct bop{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

void bopt(){
    int n;
    std::cout << "Enter the number of bop you want to register: ";
    (std::cin >> n).get();

    bop *newbop = new bop[n];
    for (int i = 0; i < n; i++){
        std::cout << "Enter you real name #" << i << ": ";
        std::cin.getline((newbop + i)->fullname, strsize);
        std::cout << "Enter you title " << (newbop + i)->fullname << ": ";
        std::cin.getline((newbop + i)->title, strsize);
        std::cout << "Enter you bopname " << (newbop + i)->fullname << ": ";
        std::cin.getline((newbop + i)->bopname, strsize);
        std::cout << "Enter your preference:";
        (std::cin >> (newbop + i)->preference).get();
    }

    std::cout << "Benevolent Order of Programmers Report\n"
                 "a. display by name      b.display by title\n"
                 "c. display by bopname   d.display by preference\n"
                 "q. quit\n";
    char c;
    std::cout << "Enter your choice: ";
    while ((c = std::cin.get()) != 'q'){
        switch (c){
        case 'a':
        case 'A':
            for (int i = 0; i < n; i++){
                std::cout << (newbop + i)->fullname << std::endl;
            }
            std::cout << "Next Choice: ";
            break;
        case 'b':
        case 'B':
            for (int i = 0; i < n; i++){
                std::cout << (newbop + i)->title << std::endl;
            }
            std::cout << "Next Choice: ";
            break;
        case 'c':
        case 'C':
            for (int i = 0; i < n; i++){
                std::cout << (newbop + i)->bopname << std::endl;
            }
            std::cout << "Next Choice: ";
            break;
        case 'd':
        case 'D':
            for (int i = 0; i < n; i++){
                switch ((newbop + i)->preference){
                case 0:
                    std::cout << (newbop + i)->fullname << std::endl;
                    break;
                case 1:
                    std::cout << (newbop + i)->title << std::endl;
                    break;
                case 2:
                    std::cout << (newbop + i)->bopname << std::endl;
                    break;
                }
            }
            std::cout << "Next Choice: ";
            break;
        default:
            std::cout << "Enter a,b,c,d or q: ";
            break;
        }
    }
    std::cout << "Bye\n";
    delete[n]newbop;
}

//5.
void incomeTax(){
    double income;
    double tax;
    std::cout << "Input you income: ";
    std::cin >> income;
    while (income > 0 && std::cin){
        if (income > 35000){
            tax = (income - 35000)*0.2 + 20000 * 0.15 + 10000 * 0.1;
        } else if (income > 15000){
            tax = (income - 15000)*0.15 + 10000 * 0.1;
        } else if (income > 5000){
            tax = (income - 5000)*0.1;
        } else {
            tax = 0;
        }
        std::cout << "Your income tax is " << tax << std::endl;
        std::cout << "Input your next income: ";
        std::cin >> income;
    }

}

//6.
struct _patron{
    std::string name;
    double patronize;
};

void patron(){
    int n;
    std::cout << "Please enter the number of patrons: ";
    (std::cin >> n).get();
    _patron *newpatron = new _patron[n];

    for (int i = 0; i < n; i++){
        std::cout << "Please enter the name of patron #" << i+1 << ":\n";
        std::getline(std::cin, (newpatron + i)->name);
        std::cout << "Please enter donation of " << (newpatron + i)->name << ":\n";
        (std::cin >> (newpatron + i)->patronize).get();
    }
    std::cout << "===================================\n";
    std::cout << "========== Grand Patron ===========\n";
    std::cout << "===================================\n";

    int count = 0;
    for (int i = 0; i < n; i++){
        if ((newpatron + i)->patronize > 10000){
            std::cout << "\t  " << (newpatron + i)->name << std::endl;
            count++;
        }
    }
    if (count == 0){
        std::cout << "None\n";
    }

    count = 0;
    std::cout << "\n\n========== Patron ============\n";
    for (int i = 0; i < n; i++){
        if ((newpatron + i)->patronize <= 10000){
            std::cout << "\t  " << (newpatron + i)->name << std::endl;
            count++;
        }
    }

    if (count == 0){
        std::cout << "None\n";
    }

    delete[n]newpatron;
}

//7.
void countAlpha(){
    std::string word;
    std::cout << "Enter words(q to quit)\n";
    std::cin >> word;
    int vowelcount = 0;
    int constacount = 0;
    int othercount = 0;
    while (word != "q" && word != "Q"){
        if (isalpha(word[0])){
            if (word[0] == 'A' || word[0] == 'a' || word[0] == 'e' || word[0] == 'E' ||
                word[0] == 'i' || word[0] == 'I' || word[0] == 'O' || word[0] == 'o' ||
                word[0] == 'U' || word[0] == 'u'){
                vowelcount++;
            } else {
                constacount++;
            }
        } else {
            othercount++;
        }
        std::cin >> word;
    }

    std::cout << vowelcount << " words begin with vowels\n" << constacount
                            << " words begin with consonants\n" << othercount
                            << " others\n";
}

//8.
void readfile(){
    std::string filename;
    std::cout << "Input file name: ";
    std::cin >> filename;
    std::ifstream openfile(filename);
    
    if (!openfile.is_open()){
        std::cout << "Failed to open file\n";
        system("pause");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while (openfile.good()){
        std::cout << (char)openfile.get();
        count++;
    }

    std::cout << std::endl;
    if (openfile.eof()){
        std::cout << "reach end of file\n" << "read " << count << " characters\n";
    }
    else if (openfile.fail()){
        std::cout << "input terminated by mismatch data\n";
    }else{
        std::cout << "input terminated by unknown reason\n";
    }
    openfile.close();
}

//9.
void readfilepatron(){
    std::string filename;
    std::cout << "Enter the file containing the patrons\n";
    std::ifstream inputFile(filename);
    
    if (!inputFile.is_open()){
        std::cout << "Failed to open file\n";
        system("pause");
        exit(EXIT_FAILURE);
    }

    int n;
    (inputFile >> n).get();
    _patron *newpatron = new _patron[n];

    for (int i = 0; i < n; i++){
        std::getline(inputFile,(newpatron+i)->name);
        (inputFile >> (newpatron + i)->patronize).get();
    }

    std::cout << "===================================\n";
    std::cout << "========== Grand Patron ===========\n";
    std::cout << "===================================\n";

    int count = 0;
    for (int i = 0; i < n; i++){
        if ((newpatron + i)->patronize > 10000){
            std::cout << "\t  " << (newpatron + i)->name << std::endl;
            count++;
        }
    }
    if (count == 0){
        std::cout << "None\n";
    }

    count = 0;
    std::cout << "\n\n========== Patron ============\n";
    for (int i = 0; i < n; i++){
        if ((newpatron + i)->patronize <= 10000){
            std::cout << "\t  " << (newpatron + i)->name << std::endl;
            count++;
        }
    }

    if (count == 0){
        std::cout << "None\n";
    }

    delete[n]newpatron;
    inputFile.close();
}
