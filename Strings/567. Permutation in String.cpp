#include<iostream>
#include<string>
using namespace std;

bool isFreqSame(int arr1[26], int arr2[26]) { //O(1)
    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26]={0}, n1=(int)s1.length(), n2=(int)s2.length();
    if(n1 > n2) return false;

    for(int i=0;i<n1;i++){ //O(n1)
        freq[s1[i]-'a']++;
    }

    int windSize=n1;
    for(int i=0;i<=n2-windSize;i++) { //O(n2)
        int idx=i, windFreq[26]={0};
        while(idx<i+windSize){ // both lowerBound(idx) & upperBound(i+windSize) should slide; O(n1)
            windFreq[s2[idx]-'a']++;
            idx++;
        }
        if(isFreqSame(freq, windFreq)){ //found
            return true;
        }
    }
    return false;
}