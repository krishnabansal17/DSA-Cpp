#include<iostream>
#include<vector>
using namespace std;
void reverseArray1(vector<int> &v, int n){
    for(int i=0;i<n/2;i++){
        v[i] = v[i]^v[n-1-i];
        v[n-1-i] = v[i]^v[n-i-1];
        v[i]^=v[n-i-1]; 
    }
}

void reverseArray2(vector<int>& v, int n){
    int start =0, end = n-1;
    while(start<end){
        swap(v[start], v[end]); // Use of Swap-Function (Time Complexity - O(1))
        start++;
        end--;
    }
}
int main(){
    vector<int> v = {1,2,3,4,5,6,7,8};
    reverseArray2(v, 8);
    for(int val : v){
        cout<<val<<" ";
    }
    cout<<endl;
}