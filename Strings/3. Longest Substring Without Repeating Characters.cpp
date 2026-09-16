#include<iostream>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) { // TC: O(n)
        unordered_map<char,int> lastSeen;
    int left=0, maxLen=0;

    for(int right=0; right<s.length(); right++){
        char ch=s[right];
        if(lastSeen.count(ch) && lastSeen[ch] >= left){
            left = lastSeen[ch] + 1;
        }
        lastSeen[ch] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}