#include<iostream>
#include<vector>
using namespace std;

// TC: O(n2) [Best-Case: O(n)]
// Bubble Sort: Check adjacent elements & swap. Brings largest element to last first.
    // It is a stable sort.

void bubbleSort(vector<int>& arr, int n){
    for(int i=0;i<n-1;i++){ // for no of passes
        bool flag=true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag=false; //false means swapping ho rahi hain
            }
        }
        if(flag) break;
    }
    return;
}