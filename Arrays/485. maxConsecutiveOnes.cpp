#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums){ //TC: O(n), SC:: O(1)
    int sz = nums.size(), count=0, maxCount=0;
    for(int i=0;i<sz;i++){
        if(nums[i]==1) count++;
        else count=0;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}