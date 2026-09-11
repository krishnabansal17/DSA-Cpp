// Max Subarray Sum
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums){ // TC: O(n), SC: O(1)
    int currSum=0, maxSum=INT_MIN, sz=nums.size();
    for(int i=0;i<sz;i++){
        currSum+=nums[i];
        maxSum=max(maxSum, currSum); // for max. sum retriveal;
        if(currSum<0) currSum=0; // no need to take -ve sum as it will eventually decrease whole sum at the end;
    }
    return maxSum;
}