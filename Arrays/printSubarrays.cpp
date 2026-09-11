#include<iostream>
#include<vector>
using namespace std;
void printSubarrays(vector<int> v, int n){ // Time Complexity - O(n3)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<v[k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> v = {1,2,3,4,5};
    int n = v.size();
    printSubarrays(v,n);
    return 0;
}