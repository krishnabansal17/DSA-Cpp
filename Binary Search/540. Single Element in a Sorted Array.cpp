#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums){
    int sz=nums.size();
    if(sz==1) return nums[0];
    int st=0, end=nums.size()-1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(mid==0 && nums[0]!=nums[1]) return nums[mid];
        if(mid==sz-1 && nums[mid]!=nums[mid-1]) return nums[mid];

        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid]; //condn for mid to be target value

// if mid=even -> has even number of elems each side of it && if mid=odd -> has odd number of elems each side of it.
        if(mid%2==0){ // if each side of mid has even number of elements
            if(nums[mid]==nums[mid-1]) end=mid-2;
            else st=mid+2;
        } else { // if each side of mid has odd number of elements
            if(nums[mid]==nums[mid-1]) st=mid+1;
            else end=mid-1;
        }
    }
    return -1;
}