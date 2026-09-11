#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    int sz=nums.size(), numOfSubarray=0;
    for(int st=0;st<sz;st++){
        int sum=0;
        for(int end=st;end<sz;end++){
            sum+=nums[end];
            if(sum==k){
                numOfSubarray++;
            }
        }
    }
    return numOfSubarray;
}