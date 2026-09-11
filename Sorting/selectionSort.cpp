#include<iostream>
#include<vector>
using namespace std;

// Selection Sort: Just find the smallest el in arr & swap with its correct position.
    // It is not a stable sorting algo.

void selectionSort(vector<int>& arr){ // O(n2)
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int minIndex=i; // unsorted part starting
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}