#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Brute Force Approach
vector<int> unionArray1(vector<int>& nums1, vector<int>& nums2){// TC: O((n1+n2)logn) +O(n1+n2)
    set<int> st; // SC: O(n1+n2) + O(n1+n2)
    for(int val:nums1){ //O(n1logn)
        st.insert(val);
    }
    for(int val:nums2){ //O(n2logn)
        st.insert(val);
    }
    vector<int> un(st.size());
    int i=0;
    for(auto val: st){ //O(n1+n2)
        un[i]=val;
        i++;
    }
    return un;
}

//Optimal Approach
vector<int> unionArray2(vector<int>& nums1, vector<int>& nums2){// TC: O(n1+n2)
    int i=0,j=0;
    vector<int> un; // SC: O(n1+n2)
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]<=nums2[j]){
            if(un.size()==0 || un.back()!=nums1[i]) un.push_back(nums1[i]);
            i++;
        } else{
            if(un.size()==0 || un.back()!=nums2[j]) un.push_back(nums2[j]);
            j++;
        }
    }
    while(j<nums2.size()){
        if(un.size()==0 || un.back()!=nums2[j]) un.push_back(nums2[j]);
        j++; // un.size()==0 still needed because 1st while() will not run. 
    } // Why?? In case when any of the vector (nums1[] or nums2[]) is empty.
    while(i<nums1.size()){
        if(un.size()==0 || un.back()!=nums1[i]) un.push_back(nums1[i]);
        i++;
    }
    return un;
}