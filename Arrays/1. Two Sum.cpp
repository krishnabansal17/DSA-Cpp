#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//Brute-Force Approach
vector<int> twoSum(vector<int>& nums, int target){ //TC: O(n2), SC: O(1)
    int sz=nums.size();
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            if(nums[i]+nums[j]==target) return {i, j};
        }
    }
    return {-1, -1};
}

// Better Approach - Hashing
vector<int> twoSum(vector<int>& nums, int target){ //TC: O(n), SC: O(n)
    int sz=nums.size();
    unordered_map<int, int> mp;
    for(int i=0;i<sz;i++){
        int a = nums[i];
        int more = target - nums[i];
        if(mp.find(more)!=mp.end()) return {i, mp[more]};
        mp[a]=i;
    }
    return {-1, -1};
}

//Optimal Approach - Using 2 Pointer
vector<int> twoSum(vector<int>& nums, int target){// TC: O(n(2+logn)), SC: O(n)
    int sz=nums.size();
    vector<vector<int>> nw;
    for(int i=0;i<sz;i++){
        nw.push_back({nums[i], i});
    }
    sort(nw.begin(), nw.end());
    int st=0, end=sz-1;
    while(st<end){
        int first = nw[st][0];
        int last = nw[end][0];
        if(first+last==target) return {nw[st][1], nw[end][1]};
        else if(first+last>target) end--;
        else st++;
    }
    return {-1, -1};
}