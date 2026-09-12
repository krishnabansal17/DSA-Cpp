#include<iostream>
#include<cstring>
using namespace std;

int main(){
    // Charecter Array
    char str[] = {'a', 'b', 'c', '\0'}; // ASCII Value of '\0' - 0 (char0)
    cout<<str<<endl; // return combining strings

    cout<<strlen(str)<<endl; // returns 3

    int arr[] = {1, 2, 3, 4, 5};
    cout<<arr<<endl; // returns address

    char str1[] = "hello"; // string literals
    cout<<strlen(str1)<<endl;
    cout<<str[2]<<endl;

    char str2[100]; // we have to give size
    cout<<"Enter the char array: ";
    cin>>str2;

    cout<<"The inputed string: "<<str2;

    char str3[100];
    cin.getline(str3, 100, '$'); // cin.getline(string, lenght, delimiter)

    cout<<str3<<endl;

    return 0;
}