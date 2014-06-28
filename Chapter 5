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
