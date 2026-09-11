#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Brute Force Approch
int singleNumber1(vector<int>& nums){ //TC: O(n2), SC: O(1)
    int sz=nums.size();
    for(int i=0;i<sz;i++){
        int num=nums[i], count=0;
        for(int j=0;j<sz;j++){
            if(nums[j]==num) count++;
        }
        if(count!=2) return num;
    }
    return -1; // Always add a fallback return.
}

//Better Approach - Using Hashing
int singleNumber2(vector<int>& nums){
    int sz=nums.size(), max_elem=*(max_element(nums.begin(), nums.end()));
    vector<int> hash(max_elem+1, 0);
    for(int i=0;i<sz;i++){
        hash[nums[i]] = hash[nums[i]] + 1;
    }
    for(int i=1;i<hash.size();i++){
        if(hash[i]==1) return i;
    }
    return -1;
}

//Optimal Approach - Use XOR opr
int singleNumber(vector<int> v, int n){ //TC: O(n), SC:O(1)
    int ans=0;
    for(int val : v){
        ans ^= val; // 0^0=0, 1^1=0, 0^1=1 & 1^0=1; so on a^a=0. Duplicate no.s get cancelled.
    }
    return ans;
}
int main(){
    vector<int> v = {4, 1, 2, 1, 2};
    int ans = singleNumber(v, 5);
    cout<<ans<<endl;

}