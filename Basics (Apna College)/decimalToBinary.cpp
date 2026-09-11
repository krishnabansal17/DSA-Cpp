#include<iostream>
using namespace std;
//Decimal to Binary Conversion
int decimalToBinary(int decimal){
    int binary=0, pow=1;
    while(decimal>0){
        int rem = decimal%2;
        decimal/=2;
        binary += (rem*pow);
        pow*=10; 
    }
    return binary;
}
int main(){
    int decimal;
    cin>>decimal;
    cout<<decimalToBinary(decimal)<<endl;
    return 0;
}