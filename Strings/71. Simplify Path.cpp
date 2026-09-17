#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue; // skip empty (double slashes) and current dir
            } else if(token == ".."){
                if(!stack.empty()) stack.pop_back(); // go to parent
            } else {
                stack.push_back(token); // valid directory/file name
            }
        }

        string result = "";
        for(string& dir : stack){
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};