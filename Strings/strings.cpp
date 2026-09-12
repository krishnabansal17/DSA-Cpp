#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "hello"; // dynamic => runtime resize
    cout<<str<<endl;

    str = "krishna bansal";
    cout<<str<<endl;

    string str1 = "hello", str2 = "world";
    string str3 = str1 + str2; // concatenation
    cout<<str3<<endl;

    string arr;
    getline(cin, arr);
    cout<<"output: "<<arr<<endl;
}