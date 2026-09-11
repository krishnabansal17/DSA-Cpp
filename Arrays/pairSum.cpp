#include<iostream>
#include<vector>
using namespace std;

// Brute Force Approach 
vector<int> pairSum1(vector<int> v, int sz, int target){ // Time Complexiy - O(n2)
    vector<int> result(2);
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            if(v[i]+v[j]==target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return {-1,-1};
}

// Two Pointer Approach - Given Array is sorted.
vector<int> pairSum2(vector<int> v, int sz, int target){ // Time Complexity - O(n)
    vector<int> result(2);
    int start=0, end=sz-1;
    while(start<end){
        int pairSum = v[start] + v[end];
        if(pairSum==target){
            result.push_back(start);
            result.push_back(end);
            return result;
        } else if(pairSum<target){
            start++;
        } else {
            end--;
        }
    }
}