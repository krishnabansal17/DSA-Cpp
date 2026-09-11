#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Brute Force Approch
int majorityElement1(vector<int> v, int sz){ // TC: O(n2), SC: O(1)
    for(int i=0;i<sz;i++){
        int count = 1;
        for(int j=i+1;j<sz;j++){
            if(v[i]==v[j]){
                count++;
            }
            if(count>sz/2) return v[i];
        }
    }
    return v[0]; //Edge Case when Size of Vector(v) = 1;
}

// Use of Sorting- Better Approach
int majorityElement2(vector<int> v, int sz){ // TC: O(nlog(n)+n), SC: O(1)
    sort(v.begin(), v.end()); // O(NlogN)
    int count=1;
    for(int i=1;i<sz;i++){
        if(v[i]==v[i-1]){
            count++;
            if(count>sz/2) return v[i];
        } else count=1;
    }
    return v[0]; //Edge Case when Size of Vector(v) = 1;
}

// Hashing is another approach to solve this problem in TC: O(n) but it will have SC: O(1) as of hash array

// Moore's Voting Algortihm
int mooreVotingAlgo(vector<int> v, int sz){ // TC: O(n), SC: O(1)
    int freq = 0, ans=0;
    for(int i=0;i<sz;i++){
        if(freq==0) ans=v[i];
        if(ans==v[i]) freq++;
        else freq--;
    }
    return ans;
}