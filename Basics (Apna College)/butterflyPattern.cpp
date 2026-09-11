#include <iostream>
using namespace std;

// Butterfly Pattern Printing
int main() {
    int n;
    cin >> n;

    //upper-portion
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        if(i==n-1){}
        else{
            for(int j=0;j<2*(n-i-1)-1;j++){
                cout<<" ";
            }
            for(int j=0;j<i+1;j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }

    //lower-portion
    for(int i=0;i<n-1;i++){
        for(int j=n-i-1;j>0;j--){
            cout<<"*";
        }
        for(int j=(2*i)+1;j>0;j--){
            cout<<" ";
        }
        for(int j=n-i-1;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}