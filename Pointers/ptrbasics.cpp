#include<iostream>
#include<vector>
using namespace std;

void changeA1(int a){ // pass by value
    a = 20;
    return;
}

void changeA2(int* ptr) { // pass by refrence using pointers
    *ptr = 20;
    return;
}

void changeA3(int &a){ // pass by refrence using alias
    a = 30;
}

int main() {
    int a = 10;

    changeA1(a);
    cout<<"By pass by value: "<<a<<endl;

    changeA2(&a);
    cout<<"By pass by refrence using pointers: "<<a<<endl;

    changeA3(a);
    cout<<"By pass by refrence using alias: "<<a<<endl;
    return 0;

// Array Pointer -> Constant Pointer
}