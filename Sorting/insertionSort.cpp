#include<iostream>
#include<vector>
using namespace std;

//Insertion Sort: Based on playing cards. It is a stable-sort.

void insertionSort(vector<int>& arr, int n){ // TC: O(n2) [Best-Cae: O(n)]
    for(int i=1;i<n;i++){
        int curr=arr[i], prev=i-1;
        while(prev>=0 && curr<arr[prev]){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr; // placing curr el in its correct position
    }
}