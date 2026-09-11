#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int>> countFreq(vector<int>& arr){ // TC: O(n), SC: O(n)
    unordered_map<int, int> mp;
    vector<vector<int>> ans;
    int sz=arr.size();
    for(int i=0;i<sz;i++){
        mp[arr[i]]++;
    }
    for(auto &it : mp){
        ans.push_back({it.first, it.second});
    }
    return ans;
}