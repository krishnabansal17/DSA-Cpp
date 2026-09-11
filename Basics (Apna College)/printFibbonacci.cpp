#include<iostream>
#include<vector>
using namespace std;

vector<int> printFibbonacci(int n){
    vector<int> v(n);
    v[0]=0; v[1]=1;
    for(int i=2;i<n;i++){
        v[i] = v[i-2] + v[i-1];
    }
    return v;
}

int main(){
    int n=6;
    vector<int> v = printFibbonacci(n);
    for(int val:v){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}