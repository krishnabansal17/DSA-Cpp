#include<iostream>
#include<vector>
using namespace std;

//Brute-Force Approach
vector<int> intersectionArray1(vector<int>& a, vector<int>& b){ //TC - O(n1.n2)
    vector<int> inte;  
    vector<bool> visited(b.size()); 
    // SC: O(n2) -- logically visited[] should apply on array with less no. of elements.
        // To reduce the Space-Time Complexity i.e. visited[min(b.size(), a.size())];
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(!visited[j] && a[i]==b[j]) {
                inte.push_back(a[i]);
                visited[j]=1;
                break; // move to next a[i] once matched
            }
        }
    }
    return inte;
}

//Optimal Approach
vector<int> intersectionArray2(vector<int>& a, vector<int>& b){ //TC - O(n1+n2), SC - O(1)
    vector<int> inte;
    int i=0, j=0, sz1=a.size(), sz2=b.size();
    while(i<sz1 && j<sz2){
        if(a[i]==b[j]){ //whenever they match, move both & when they don't match move smaller.
            inte.push_back(a[i]);
            i++;
            j++;
        } else if(a[i]<b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return inte;
}