#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>& arr, int m, int n, int maxAllocatedBooks){
    int pages=0, students=1;
    for(int i=0;i<n;i++){
        if(pages+arr[i]<=maxAllocatedBooks){
            pages+=arr[i];
        } else {
            students++;
            pages=arr[i];
        }
    }
    return students<=m;
}

int allocateBook(vector<int>& arr, int m, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int st=0, end=sum;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isPossible(arr, m, n, mid)){
            ans=mid;
            end=mid-1;
        } else {
            st=mid+1;
        }
    }
    return ans;
}