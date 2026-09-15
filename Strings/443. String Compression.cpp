#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compress(vector<char>& chars){ // TC: O(n)
    vector<char> result;
    int i=0, j=0, n=chars.size();
    while(i<n){
        int count=0;
        char ch=chars[i];
        while(i<n && chars[i]==ch){
            count++;
            i++;
        }
        chars[j]=ch;
        j++;
        if(count>1){
            string cnt = to_string(count);
            for(char c: cnt){
                chars[j]=c;
                j++;
            }
        }
    }
    return j;
}


/* Apna College Code: // Same Approach diffrent looks:

    int idx=0;
    for(int i=0; i<n; i++){
        char ch = chars[i];
        int count=0;
        while(i<n && chars[i]==ch){
            count++;
            i++;
        }
        if(count==1){
            chars[idx++] = ch;
        } else {
            chars[idx++] = ch;
            string str = to_string(count);
            for(char dig : str){
                chars[idx++] = dig;
            }
        }
        i--; // yeh zaroori hai!
    }
    return idx;
*/