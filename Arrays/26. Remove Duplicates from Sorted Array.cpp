#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

// Brute-Force Approach
vector<int> removeDuplicates1(vector<int>& nums){ // T.C - O(nlogn + n) S.C. - O(n)
    set<int> st;
    int sz = nums.size();
    for(int val : nums){
        st.insert(val);
    }
    int index=0;
    for(auto it : st){
        nums[index] = it;
        index++;
    }
    return nums;
}

// Optimal Approach
int removeDuplicates2(vector<int>& nums){ // T.C. - O(n)
    int sz = nums.size(), i=0, j=1;
    while(j<sz){
        if(nums[i]!=nums[j]) {
            nums[i+1]=nums[j];
            i++;
        }
        j++;
    }
    return i+1;
}