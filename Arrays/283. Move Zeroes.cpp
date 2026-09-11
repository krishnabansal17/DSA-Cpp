#include<iostream>
#include<vector>

using namespace std;

// Brute Force Approach
void moveZeroes1(vector<int>& nums){ // TC: O(2sz) & SC: O(x), x=non-zero numbers in arr
    int sz = nums.size();
    vector<int> temp;
    for(int i=0;i<sz;i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        } 
    }
    for(int i=0; i<temp.size(); i++){
        nums[i] = temp[i];
    }
    for(int i=temp.size();i<sz;i++){
        nums[i]=0;
    }
}

// Optimal-Approach
void moveZeroes2(vector<int>& nums){ // Time-Complexity: O(2sz) & Space-Complexity: O(1)
    int sz = nums.size(), index=0;
    for(int i=0;i<sz;i++){
        if(nums[i]!=0){
            nums[index]=nums[i];
            index++;
        } 
    }
    for(int i=index;i<sz;i++){
        nums[i]=0;
    }
}

// moveZeroes2() & moveZeroes3() are two different way of same intution.
void moveZeroes3(vector<int>& nums){ // Time-Complexity: O(2sz) & Space-Complexity: O(1)
    int sz = nums.size(), j=-1;
    for(int i=0; i<sz; i++){
        if(nums[i]==0) j=i;
        break;
    }
    for(int i=j+1;i<sz;i++){
        if(nums[i]!=0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}