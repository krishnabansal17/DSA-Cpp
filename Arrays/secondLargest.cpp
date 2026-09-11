#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int largest(vector<int> v, int sz){
    int largestNum=INT_MIN;
    for(int i=0;i<sz;i++){
        if(v[i]>largestNum) largestNum=v[i];
    }
    return largestNum;
}

//Brute-Force Approach
int secondLargest1(vector<int> v, int sz){ //Time Complexity - O(nlogn+n)
    sort(v.begin(), v.end());
    int largest = v[sz-1];
    for(int i=sz-2;i>0;i--){
        if(v[i]!=largest) return v[i];
    }
    return -1;
}

//Better-Approach
int secondLargest2(vector<int> v, int sz){ // Time Complexity - O(2*n)
    int largestNum=largest(v, sz);         
    int secondLargestNum=-1; // Assuming all numbers are +ve
    for(int i=0;i<sz;i++){
        if(v[i]>secondLargestNum && v[i]!=largestNum) secondLargestNum=v[i];
    }
    return secondLargestNum;
}

//Optimal-Approach
int secondLargest3(vector<int> v, int sz){
    int largest=v[0], secondLargest=-1;
    for(int i=0;i<sz;i++){
        if(v[i]>largest) {
            secondLargest=largest;
            largest=v[i];
        }else if (v[i]<largest && v[i]>secondLargest) 
            secondLargest=v[i]; 
    }
    return secondLargest;
}

int main(){

    return 0;
}