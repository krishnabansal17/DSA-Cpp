#include<iostream>
#include<string>
using namespace std;

bool isAlphaNum(char c){
    if((c >= '0' && c <= '9') || 
    (tolower(c) >= 'a' && tolower(c) <= 'z')){
        return true;
    }

    return false;
}

// Two Pointer Approach
bool isPallindrome(string s){ // TC: O(n)
    int n=s.size(), st=0, end=n-1;
    while(st<end){
        if(!isAlphaNum(s[st])) { // isalnum( static_cast<unsigned char>(s[st]) ): checks for alpha-numeric character.
            st++;
            continue;
        }
        if(!isAlphaNum(s[end])) {
            end--;
            continue;
        }
        if(tolower(s[st])!=tolower(s[end])){
            return false;
        }
        st++;
        end--;
    }

    return true;
}

/*
Note:
     Always cast your char to unsigned char (using static_cast<unsigned char>(ch)) before passing it to std::isalnum(). 
     This prevents undefined behavior if your char type is signed and holds a negative character value.
*/