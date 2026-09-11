#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &nums, int st, int end, int target){ // TC: O(logn), SC: O(logn)
    if(st<=end){
        int mid = (end+st)/2;
        if(target>nums[mid]) return binarySearch(nums, mid+1, end, target);
        else if(target<nums[mid]) return binarySearch(nums, st, mid-1, target);
        else return mid; 
    }
    return -1;
}