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

bool isSortedAndRotated(vector<int> v, int sz){ // Time-Complexity - O(n2)
    // vector<int> vCopy = v;
    for(int x=1;x<=sz;x++){
        int v0=v[0];
        if(isSorted(v, sz)) return true;
        else {
            // for(int j=0;j<sz;j++) vCopy[j] = v[(j+x)%sz];
            for(int j=0;j<sz-1;j++) v[j] = v[(j+1)%sz];
            v[sz-1]=v0;
        }
    }
    return false;
}