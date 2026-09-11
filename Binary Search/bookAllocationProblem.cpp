#include<iostream>
#include<vector>
using namespace std;

// n: no of books & m: no of students
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){ //O(n)
    int std=1, pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxAllowedPages) return false;
        if(pages+arr[i]<=maxAllowedPages){
            pages+=arr[i];
        } else {
            std++;
            pages=arr[i];
        }
    }
    if(std>m) return false;
    else return true;
}


//T.C.: O(logN*n)
int allocateBook(vector<int>& arr, int n, int m){
    if(m>n) return -1;

    int sum=0;
    for(int i=0;i<n;i++){ //O(n)
        sum+=arr[i];
    }

    int ans=-1;
    int st=0, end=sum; //range of possible answers

    while(st<=end){ //O(logN * n)
        int mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid)){ //if mid value is valid - left
            ans=mid;
            end=mid-1;
        } else { //if mid value is not valid - right
            st=mid+1;
        }

    }
    return ans;
}