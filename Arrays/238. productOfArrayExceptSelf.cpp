#include<iostream>
#include<vector>
using namespace std;

// Brute Force Approach
vector<int> productOfArrayExceptSelf1(vector<int> v, int sz){  // Time Complexity - O(n2)
    vector<int> ans(sz);
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if(i!=j) ans[i]*=v[j];
        }
    }
    return ans;
}

// Optimal Approach - Calculate prefix-products & suffix-products corresponding to element.
vector<int> productOfArrayExceptSelf2(vector<int> v, int sz){ // Time-Complexity - O(n) && Space-Complexity - O(2n+2)
    vector<int> product(sz), prefixArr(sz,1), suffixArr(sz,1);
    int prefix=1, suffix=1;
    for(int i=1;i<sz;i++){
        prefix*=v[i-1];
        prefixArr[i]=prefix;
    }
    for(int i=sz-2;i>=0;i--){
        suffix*=v[i+1];
        suffixArr[i]=suffix;
    }
    for(int i=0;i<sz;i++){
        product[i]=prefixArr[i]*suffixArr[i];
    }
    return product;
}

// Space-Complexity Optimization
vector<int> productOfArrayExceptSelf3(vector<int> v, int sz){ // Time-Complexity - O(n) && Space-Complexity - O(1)
    vector<int> ans(sz, 1);
    for(int i=1;i<sz;i++){
        ans[i]=v[i-1]*ans[i-1];
    }
    int suffix=1;
    for(int i=sz-2;i>=0;i--){
        // ans[i]=v[i+1]*ans[i+1]; Can't use this approach directly as 'ans(sz, 1)' is updated after 1st-loop, prefix is already stored in it.
        suffix*=v[i+1];
        ans[i]*=suffix; // as 'ans(sz, 1)' is changed, we need to multiply the changed vector with corresponding suffix
    }
    return ans;
}