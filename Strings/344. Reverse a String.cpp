#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// Reverse a Charecter Array
void reverseString(vector<char>& s){
    int n = s.size(), st=0, end=n-1;
    while(st<end){
        swap(s[st++], s[end--]);
    }
}

// Reverse a String
void reverseString(string str){
    reverse(str.begin(), str.end()); //iterators
}