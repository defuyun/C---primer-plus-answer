#include<iostream>
#include"Chapter9.h"
//1.
void usegolf(){
    golf g[10];
    int n = 0;
    while (setgolf(g[n])!= 0 && n<10){
        n++;
    }
    int i = 0;
    while (i<n){
        showgolf(g[i++]);
    }
}

//2.
void usesales(){
    SALES::Sales pro1, pro2;
    double arr[4] = { 1.0, 2.0, 3.0, 4.0 };
    SALES::setSales(pro1);
    SALES::setSales(pro2, arr, 4);
    SALES::showSales(pro1);
    SALES::showSales(pro2);
}
