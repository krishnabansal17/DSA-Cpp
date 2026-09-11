#include<iostream>
#include<vector>
using namespace std;

int searchInRotatedSortedArray(vector<int> &nums, int target) {
    int start = 0, end = nums.size()-1;
    while(start<=end) {
        int mid = (start+end)/2;
        if(target==nums[mid]) return mid;
        if(nums[start]<=nums[mid]) { //Left-sorted array
            if(target>=nums[start] && target<=nums[mid]) end = mid-1; //does exist in left side??
            else start = mid+1;
        } 
        else { //Right-sorted array
            if(target>=nums[mid] && target<=nums[end]) start = mid+1; //does exist in right side??
            else end = mid-1;
        }
    }
    return -1;
}