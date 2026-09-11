#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int> arr, int n, int m, int maxAllowedTime) {//O(n)
    int painters=1, time=0;
    for(int i=0;i<n;i++){
        if(time+arr[i]<=maxAllowedTime) time+=arr[i];
        else {
            painters++;
            time=arr[i];
        }
    }
    return (painters>m)?false:true;
}

int minTimeToPaint(vector<int>& arr, int n, int m) {
    int sum=0, ans=-1;
    for(int i=0;i<n;i++){ //O(n)
        sum+=arr[i];
    }

    int st=*(max_element(arr.begin(), arr.end()));
    int end=sum;

    while(st<=end){ //O(log(sum)*n)
        int mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid)){
            ans = mid;
            end=mid-1;
        } else {
            st=mid+1;
        }
    }
    return ans;
}