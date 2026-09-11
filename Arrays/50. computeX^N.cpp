#include<iostream>
using namespace std;

// No O(n)- Linear Time Complexity, instead use 'Binary Exponentiation'
    // Binary Exponentiation Method: Power ki Binary-Form use krenge. 
    // n number - No. of digits = at Max 'log2n +1'

double xToPowerN(double x, int n){ //  Time-Complexity - O(logN)
    if(x==0) return 0.0;
    if(x==1) return 1.0;
    if(n==0) return 1.0;
    if(n==1) return x; 
    if(x==-1 && n%2==0) return 1.0;
    if(x==-1 && n%2==1) return -1.0; // Some corner edge cases

    double ans=1.0;
    long binForm=n;
    if(binForm<0) { // for negative-power 
        x=1/x;
        binForm=-1*binForm;
    }
    while (binForm>0){ // No need to convert n into binaryForm as algorithm automatically does it.
        if(binForm%2==1) ans*=x; // if x<0 then in 1st step ans will store x, then after all values are x2, x4...>0
        x*=x;
        binForm/=2;
    }
    return ans;
}

int main(){

    return 0;
}