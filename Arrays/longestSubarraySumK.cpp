#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;

//Brute-Force Approach
int subarraySum1(vector<int>& nums, int k){ //TC: O(n2), SC:O(1)
    int sz=nums.size(), subarrayLenght=0, maxSubarrayLenght=0;
    for(int st=0;st<sz;st++){
        int sum=0;
        for(int end=st;end<sz;end++){
            sum+=nums[end];
            if(sum==k){
                subarrayLenght = end-st+1;
                maxSubarrayLenght = max(subarrayLenght, maxSubarrayLenght);
            }
        }
    }
    return maxSubarrayLenght;
}

//Better Approach - Use of Hashing
int subArraySum2(vector<int>& nums, int k){ //TC: O(n*1) OR O(n2), SC: O(n); In orderedmaps: O(nlog n)
    int sz=nums.size(), sum=0, maxLenght=0;
    unordered_map<int, int> preMap;
    for(int i=0;i<sz;i++){
        sum+=nums[i];
        if(sum==k) maxLenght = max(maxLenght, i+1);
        int rem=sum-k;
        if(preMap.find(rem)!=preMap.end()){ // find() = O(log n), end() = O(1
            //Always, preMap.end() is used with preMap.find() to check if a specific key exists in your map.
            int lenght = i-preMap[rem];
            maxLenght = max(maxLenght, lenght);
        }
        if(preMap.find(sum)==preMap.end()){
            preMap.insert({sum, i}); // or preMap[sum] = i; // insert() = O(log n)
        }
    }
    return  maxLenght;
}

//Two-Pointer Approach - Optimal Approach when array[] contains 0s & +ves
int subArraySum3(vector<int>& nums, int k){ // TC: O(2n), SC: O(1)
    int sz=nums.size(), maxLenght=0, lenght=0, sum=nums[0];
    int i=0, j=0;
    while(i<sz){
        while(j<=i && sum>k) {
            sum-=nums[j];
            j++;
        }
        if(sum==k) maxLenght=max(maxLenght, i-j+1);
        i++;
        if(i<sz) sum+=nums[i];
    }
    return maxLenght;
}

