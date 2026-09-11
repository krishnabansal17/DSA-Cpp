#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Brute-Force Approach // TC: o(n!.n) - through Recursion
    // 1. Get all permutations sorted.
    // 2. Linear Search
    // 3. Next Permutation

// Better Approach - Using STL
void nextPermutation2(vector<int>& nums) { // TC: O(n), SC: O(1)
    next_permutation(nums.begin(), nums.end());
}

// Optimal Solution
void nextPermutation3(vector<int>& nums){ // TC: O(3n), SC:O(1)
    int n=nums.size();
    //1. Find the pivot
    int pivot=-1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]) {
            pivot=i; 
            break;
        }
    }

    // if num is biggest possible number that can be formed: we will revese the array.
    if(pivot==-1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    //2. Find rightmost element > pivot
    for(int i=n-1;i>pivot;i--){
        if(nums[i]>nums[pivot]) {
            swap(nums[i], nums[pivot]); 
            break;
        }
    }

    //3. Reverse (pivot+1) to n-1
    // reverse(nums.begin() + pivot + 1, nums.end());
    int i=pivot+1, j=n-1;
    while(i<=j){
        swap(nums[i], nums[j]);
        i++; j--;
    }
}