#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int indexSmallestNum(vector<int> v){
    int min = INT_MAX, n=v.size(), minI=0;
    for(int i=0;i<n;i++){
        if(min>v[i]){
            min=v[i];
            minI = i;
        }
    }
    return minI;
}
int main(){
    vector<int> v = {10,24,23,43,5,6,7,8};
    int minI = indexSmallestNum(v);
    cout<<minI<<endl;
}
