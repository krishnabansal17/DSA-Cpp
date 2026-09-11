#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool checkPrime(int n){
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
vector<int> primeRange(int l, int r){
    vector<int> nums;
    for(int i=l;i<=r;i++){
        if(checkPrime(i)){
            nums.push_back(i);
        }
    }
    return nums;
}
int main(){
    vector <int> nums = primeRange(2,5);
    for(int val:nums){
        cout<<val<<" ";
    }
    return 0;
}