#include<iostream>
using namespace std;

bool checkPallindrome(int n){
        int num=(n<0 ? -1*n : n);
        int absNum = num;
        int reverseNum = 0;
        while(num>0){
            reverseNum = (reverseNum*10)+(num%10);
            num/=10;
        }
        return reverseNum==absNum ? true : false;
    }
int main(){
    cout<<checkPallindrome(0);
    return 0;
}