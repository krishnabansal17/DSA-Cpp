#include<iostream>
#include<vector>

using namespace std;

bool isSorted(vector<int> v, int sz){ // Time-Complexity - O(n)
    if(sz==1) return true;
    for(int i=1;i<sz;i++){
        if(v[i-1]>v[i]) {
            return false;
        }
    }
    return true;
}

