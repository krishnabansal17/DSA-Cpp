#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Brute Force Approach
int maxSubarraySum1(vector<int> v, int sz){ // Time Complexity - O(n3)
    int maxSum=INT_MIN;
    for(int st=0;st<sz;st++){
        for(int end=st;end<sz;end++){
            int currSum=0;
            for(int i=st;i<=end;i++){
                currSum+=v[i];
            }   
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

// Optimized Approach
int maxSubarraySum2(vector<int> v, int n){
    int maxSum=INT_MIN;
    for(int st=0;st<n;st++){
        int currSum=0;
        for(int end=st;end<n;end++){ // Time Complexity - O(n2)
            currSum+=v[end];
            maxSum = max(maxSum, currSum);
        }
    }
}
 // Kadane's Algorithm is a DP-algo.
int kadanesAlgo(vector<int> v, int n){ // Time Complexity - O(n)
    int maxSum=INT_MIN, currSum=0;
    for(int i=0;i<n;i++){
        currSum+=v[i];
        maxSum = max(maxSum, currSum);
        if(currSum<0) currSum=0; // if Current-Sum<0 -> will eventually decrease maxSum, hence we should make Current-Sum=0 & skip that pair.
        // this condn is taken after maxSum evaluation not before that, it comes from edge-case evaluation where all elems are -ve. 
        // refer img 'Kadane's Algorithm 1.png'
    }
    return maxSum;
}
int main(){
    vector<int> v = {3,-4,4,5,-1,7,-8};
    int n = v.size();
    int maxSum = kadanesAlgo(v,n);
    cout<<maxSum<<endl;
}