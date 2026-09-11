#include<iostream>
#include<vector>
using namespace std;

// Brute-Force Approach
int missingNumber1(vector<int>& nums, int N){ //TC: O(N2), SC: O(1)
    int sz = nums.size();
    for(int i=1;i<=N;i++){
        bool flag=0;
        for(int j=0;j<sz;j++){
            if(nums[j]==i){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}

// Better Solution - HASHING
int missingNumber2(vector<int>& nums, int N){ //TC: O(N2), SC: O(N)
    int sz= nums.size();
    vector<int> hash(N+1, 0);
    for(int i=0;i<sz;i++){
        hash[nums[i]]=1;
    }
    for(int i=1;i<N+1;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
}

// Optimal Solution 1 - Sum Method
int missingNumber3(vector<int>& nums, int N){// TC:O(N), SC:O(1)
    int sum = (N*(N+1))/2, sz=nums.size();
    for(int i=0;i<sz;i++){
        sum-=nums[i];
    }
    return sum;
}

// Optimal Solution 2 - XOR Method
int missingNumber4(vector<int>& nums, int N){// TC:O(N), SC:O(1)
    int sz = nums.size(), XOR=0;
    /* for(int i=1;i<=N;i++){// TC:O(2N)
        XOR^=i;
    } */
    for(int i=0;i<sz;i++){
        XOR^=nums[i];
        XOR^=(i+1);
    }
    XOR^=N;
    return XOR;
}

// Optimal Soln 2 is slightly better than Optimal Soln 1:
    // The sum-method calculates 'sum' which can exceed range of int(10^5): have to use long.
    // The XOR-method calculates XOR, which will never exceed the range of INT(10^5)