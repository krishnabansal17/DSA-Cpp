#include<iostream>
#include<vector>
using namespace std;

// ^ - XOR opertaor (Bitwise Operator)
    // Properties: 1. a^a=0 2. a^0=a

void swapTwoNumbers(int& a, int& b){
    a = a^b;
    b = a^b; // = a^b^b = a
    a = a^b; // = a^b^a = b
}
int main(){

    return 0;
}