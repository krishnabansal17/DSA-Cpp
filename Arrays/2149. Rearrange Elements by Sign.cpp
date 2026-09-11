#include<iostream>
#include<vector>

using namespace std;

//Brute Force Approach
vector<int> rearrangeArray1(vector<int>& nums){ // TC: O(3n/2), SC: O(2n): pv+nv+ans;
    int sz=nums.size();
    vector<int> pv, nv, ans;
    for(int i=0;i<sz;i++) {
        if(nums[i]>0) pv.push_back(nums[i]);
        else nv.push_back(nums[i]);
    }
    for(int i=0;i<sz/2;i++){
        ans.push_back(pv[i]);
        ans.push_back(nv[i]);
    }
    return ans;
}

// Optimal Solution
vector<int> reaarangeArray2(vector<int>& nums){ // TC: o(n), SC: O(n)
    int sz=nums.size(), pvPointer=0, nvPointer=1;
    vector<int> ans(sz, 0);
    for(int i=0;i<sz;i++){
        if(nums[i]>0){
            ans[pvPointer] = nums[i];
            pvPointer+=2;
        } else {
            ans[nvPointer] = nums[i];
            nvPointer+=2;
        }
    }
    return ans;
}

// --------------- Follow-Up Question -------------------
// What if number of +ves & number of -ves are not equal?
// --> We will again fall back to Brute Force Solution.

vector<int> reaarangeArray3(vector<int>& nums){
    int sz=nums.size();
    vector<int> pv, nv, ans(sz, 0);
    for(int i=0;i<sz;i++) {
        if(nums[i]>0) pv.push_back(nums[i]);
        else nv.push_back(nums[i]);
    }
    if(pv.size()>nv.size()){
        for(int i=0;i<nv.size();i++){
            ans[i*2]=pv[i];
            ans[]
        }
    }
}