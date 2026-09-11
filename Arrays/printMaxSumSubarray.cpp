// Max Subarray Sum
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSubArray(vector<int>& nums) {
    int currSum=0, maxSum=INT_MIN, sz=nums.size(), start=0, ansStart=-1, ansEnd=-1;
    for(int i=0;i<sz;i++){
        if(currSum==0) start=i;
        currSum+=nums[i];
        if(currSum>maxSum){
            maxSum=currSum;
            ansStart=start;
            ansEnd=i;
        }
        if(currSum<0) currSum=0;
    }
    vector<int> ans;
    for(int i=ansStart; i<=ansEnd; i++){
        ans.push_back(nums[i]);
    }
    return ans;
}