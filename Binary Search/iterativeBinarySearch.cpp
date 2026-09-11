#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) { // TC: O(logn), SC:O(1)
    int start = 0, end = nums.size()-1;
    int mid = (start+end)/2; // mid = start + (end-start)/2: to avoid overflow condition.
    while(start<end) {
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) end=mid-1;
        else start = mid+1;
    }
    return -1;
}

int main(){

}