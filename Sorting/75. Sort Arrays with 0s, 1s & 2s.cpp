#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force Approach - TC: O(nlogn)
void sortColors(vector<int>& arr){
    sort(arr.begin(), arr.end());
}

// Optimal Approach - TC: O(2n): Uses 2 Passes.
void sortColors(vector<int>& arr){
    int n=arr.size(), count0=0, count1=0, count2=0;
    // Count no of 0s, 1s & 2s
    for(int i=0;i<n;i++){
        if(arr[i]=0) count0++;
        else if(arr[i]=1) count1++;
        else count2++;
    }

    int idx=0;
    for(int i=0;i<count0;i++){
        arr[idx++]=0;
    }
    for(int i=0;i<count1;i++){
        arr[idx++]=1;
    }
    for(int i=0;i<count2;i++){
        arr[idx++]=2;
    }

    /* 2nd way to do same thing:

    for(int i=0;i<count0;i++){
        arr[i]=0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i]=1;
    }
    for(int i=count0+count1;i<count0+count1+count2;i++){
        arr[i]=2;
    } 

    */
}

// Optimal ApproachL Dutch National Flag Algo
void sortColors(vector<int>& arr){ // TC: O(n), SC: O(1)
    int low=0,mid=0, high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid], arr[high]);
            high--;
        }
        else {
            mid++;
        }
    }
}