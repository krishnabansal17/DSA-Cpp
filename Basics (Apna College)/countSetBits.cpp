#include<iostream>
using namespace std;
// Binary Subtraction Property:-
    // The position at which the rightmost '1' in any number say 'n' is present, let that position be 'a'.
    // In 'n-1', bit at ath position will be '0', from positions 'a-1' down to 0th will be '1' & above position 'a' all bits remains same;.

// Set Bits - '1' in Binary Number
int countSetBits(int n){
    int count=0;
    while(n>0){
         if(n & 1){ //returns 0 if '0' at ones place & returns 1 if '1' at ones place of 'n'.
            count++;
        }
        n>>=1; //move to next bit
    }
}

int brianKernighanAlgorithm(int n){
    int count=0;
    while(n>0){
        n = n & (n-1); 
        // n & (n-1) makes the rightmost 1 in n = 0, this way at end of loop the n becomes '0'
        count++;
    }
    return count;
}
int main(){

    return 0;
}