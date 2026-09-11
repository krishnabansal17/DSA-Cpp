#include<iostream>
#include<vector>
using namespace std;

// Brute-Force Approach
void rotate1(vector<int>& nums, int k){ // Time Complexity - O(k*sz),  S.C. - O(1)
    int sz = nums.size();
    if(sz==1) return;
    k = k%sz;
    for(int i=1;i<=k;i++){
        int nums0=nums[0];
        for(int j=sz-1;j>0;j--) nums[(j+1)%sz] = nums[j];
        nums[1]=nums0;
    }
    return;
}

//Better-Approach
void rotate2(vector<int>& nums, int k){ // Time Complexity - O(k + (sz-k) + k) - O(sz+k)
    int sz= nums.size();
    if(sz==1) return;
    k%=sz;
    vector<int> temp; // Space Compleexity - O(k)
    for(int i=sz-k;i<sz;i++){ // last k elemts stored in seperate temp
        temp.push_back(nums[i]);
    }
    for(int i=sz-k-1;i>=0;i--){ // shifting of first sz-k elemts
        nums[i+k]=nums[i];
    }
    for(int i=0;i<temp.size();i++){ // last elemts shifted to front
        nums[i]=temp[i];
    }
}

void swapArray(vector<int>& nums, int beg, int end){ // O(end-beg+1)
    int mid = (beg+end)/2;
    for(int i=beg;i<=mid;i++){
        int j=end+beg-i;
        if(i==j) continue; // XOR trick fails when (i==j), nums[i]^nums[i]==0
        nums[i] = nums[j]^nums[i]; // nums[end] will get swapped
        nums[j]=nums[j]^nums[i];
        nums[i]=nums[j]^nums[i];
    }
}

//Optimal-Approach
void rotate3(vector<int>& nums, int k){ // Time-Complexity: O(2*sz) & Space-Complexity: O(1)
    int sz=nums.size();
    if(sz==1) return;
    k%=sz;
    swapArray(nums, sz-k, sz-1);
    swapArray(nums, 0, sz-k-1);
    swapArray(nums, 0, sz-1);
}

int main(){

}