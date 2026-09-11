#include<iostream>
using namespace std;
// Binary to Decimal Conversion
int binaryToDecimal(int binary){
    int pow = 1, decimal = 0;
    while(binary>0){
        int rem = binary%10;
        binary/=10;
        decimal += (pow*rem);
        pow*=2;
    }
    return decimal;
}

int main(){
    cout<<binaryToDecimal(1010101);
    return 0;
}