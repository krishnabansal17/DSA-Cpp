#include<iostream>
#include<math.h>
using namespace std;
bool checkArmstrong(int n){
    int armNum = 0, num = n;
    while(num>0){
        int remainder = num%10;
        armNum += (remainder*remainder*remainder);
        num/=10;
    }
    if(armNum == n) return true;
    else return false;
}

int main(){
    cout<<checkArmstrong(100);
    return 0;
}