// Majority Element
#include<bits/stdc++.h>
using namespace std;

// Element appearing more then n/2 times, its freqency will automatically +ve even if other elements try to cancel it;
int mooreAlgo(vector<int>& nums){ // TC: O(n), SC: O(1)
    int sz=nums.size(), freq=0, ans=0;
    for(int i=0;i<sz;i++){
        if(freq==0) ans=nums[i]; // Initial(1st) element condn;
        if(ans==nums[i]) freq++; // If we found same elem we would increace frequency;
        else freq--; // If another element then we would decrease the frequency
    }
}