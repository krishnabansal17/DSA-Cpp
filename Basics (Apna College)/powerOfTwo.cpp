#include<iostream>
using namespace std;

// The number which is power of two, has exactky one '1' bit and rest all are zero.
    // Such Number - 1 has all bits as '1' with 0 at position same as that of 1 in such number (power of two).
     
bool isPowerOfTwo(int n){
    if(n<=0) return 0;
    else return (n&(n-1))==0;
// The diffrence in binary form of n & (n-1) is at the position of the rightmost '1' of n, 'n-1' has 0
}

int main(){

    return 0;
}