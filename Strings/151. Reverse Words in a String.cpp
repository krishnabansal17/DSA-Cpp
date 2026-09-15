#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseWords(string s) { // TC: O(n), SC:O(1)
    string ans = "";
    int n=s.length();
    reverse(s.begin(), s.end());

    for(int i=0;i<n;i++){ 
        string word = "";

        while(i<n && s[i]!=' '){ //Spaces are already skipped.
        word += s[i];
        i++;
        }

        reverse(word.begin(), word.end());
        if(word.length() > 0) 
            ans += " " + word;
    }
    return ans.substr(1);
}