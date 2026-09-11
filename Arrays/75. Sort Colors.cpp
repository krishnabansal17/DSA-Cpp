#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Brute Force Approach
void sortColors(vector<int>& nums){// TC: O(nlogn), SC: O(1)
    sort(nums.begin(), nums.end());
    return;
}

//Better Approach
void sortColors2(vector<int>& nums){// TC: O(2*n), SC: O(1)
    int sz=nums.size();
    vector<int> hash(3, 0);
    for(int i=0;i<sz;i++) hash[nums[i]]++;
    for(int i=0;i<hash[0];i++) nums[i]=0;
    for(int i=hash[0];i<hash[0]+hash[1];i++) nums[i]=1;
    for(int i=hash[0]+hash[1];i<hash[0]+hash[1]+hash[2];i++) nums[i]=2;
}

// Dutch National Flag Algorithm
void sortColors(vector<int>& nums){ //TC: O(n), SC:O(1)
    int sz=nums.size();
    int low=0, mid=0, high=sz-1; // Assuming the whole arr is unsorted intially in range [mid, high]
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if(nums[mid]==1){
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return;
}