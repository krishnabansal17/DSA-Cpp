#include<iostream>
using namespace std;
// Return Index at which Traget is Found
int linearSearch(int arr[], int sz, int target){
    for(int i=0;i<sz;i++){
        if(target == arr[i]){
            return i;
        }
    }
    return -1;
}
