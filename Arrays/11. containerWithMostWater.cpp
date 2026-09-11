#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Brute Force Approach - Calculating capacity of all storage
int containerWithMostWater1(vector<int> v, int sz){ // Time-Complexity - O(n2)
    int maxStorage=0;
    for(int i=0;i+1<sz;i++){
        for(int j=i+1;j<sz;j++){
            int areaEnclosed = min(v[i], v[j])*(j-i); // Height*Width
            maxStorage = max(maxStorage, areaEnclosed);
        }
    }
    return maxStorage;
}

// Optimal or 2 Pointer Approach
    // If big line shifted, then either next line is big, or small, or of samme size, in all three cases 
    // there will be decrement in area - So, Shift smaller line only.
int containerWithMostWater2(vector<int> v, int sz){ // Time-Complexity - O(n)
    int lp=0, rp=sz-1, maxWater=0;
    while(rp>lp){
        int currWater = min(v[lp], v[rp])*(rp-lp);
        maxWater = max(maxWater, currWater);
        v[lp]>v[rp]?rp--:lp++;
    }
    return maxWater;
}

// 2-Pointer Approach: Usually used to convert O(n2)->O(n).