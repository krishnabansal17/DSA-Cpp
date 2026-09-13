#include<iostream>
using namespace std;

string removeOccurrences(string s, string part) { // Time Complexity: O(n2), Space Complexity: O(1)
        while(s.length()>0 && s.find(part)<s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }

// S.find() & s.erase() takes O(n) per call.