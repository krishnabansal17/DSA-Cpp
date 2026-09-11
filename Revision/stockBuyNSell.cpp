#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& nums){
    int sz = nums.size(), buyPrice=nums[0], maxProfit=0;
    for(int i=1;i<sz;i++) {
        if(buyPrice>nums[i]) buyPrice=nums[i];
        if(buyPrice<nums[i]) maxProfit=max(maxProfit, nums[i]-buyPrice);
    }
    return maxProfit;
}


int maxProfit2(vector<int>& nums){
    int sz = nums.size(), buyPrice=nums[0], maxPft=0;
    for(int i=1;i<sz;i++) {
        int cost = nums[i]-buyPrice;
        maxPft = max(maxPft, cost);
        buyPrice=min(buyPrice, nums[i]);
    }
    return maxPft;
}