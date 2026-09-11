#include<iostream>
#include<vector>
using namespace std;

// Index - 0 & n-1 will never be peak-element

// Linear Search Approach
int printPeakElem(vector<int>& arr){ // TC: O(N), SC: O(1)
    int n = arr.size();
    if(n==1) return 0;
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1]) return i;
    }
    return -1;
}

//Binary Search Approach
int peakIndexInMountainArray(vector<int>& arr){
    int sz=arr.size();
    if(sz==1) return 0;
    int st=1, end=sz-2;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
        else if(arr[mid]>arr[mid-1]) st=mid+1; //increasing-peak of mountain
        else end=mid-1; //decreasing-peak of mountain
    }
    return -1;
}