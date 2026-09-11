#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int m, int n, int minAllowedDistance) {  //O(n)
    int cows=1, lastStallPos=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-lastStallPos>=minAllowedDistance) {
            cows++;
            lastStallPos = arr[i];
        }
        if(cows>=m) return true;
    }
    return false;
}

//m: no of cows, n: no of stalls
int aggresiveCow(vector<int> & arr, int m, int n){
    sort(arr.begin(), arr.end());
    int st=1, end = *max_element(arr.begin(), arr.end())-*min_element(arr.begin(), arr.end());
    int ans=-1;
    while(st<=end) { //O(logRange * n)
        int mid = st + (end-st)/2;
        if(isPossible(arr, m, n, mid)){
            ans = mid;
            st=mid+1;
        } else {
            end = mid-1;
        }
    }
    return ans;
}