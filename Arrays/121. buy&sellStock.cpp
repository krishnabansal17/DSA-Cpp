#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Single-Pass/Greedy Approch
int buyAndSellStock(vector<int>& v, int sz){ // Time-Complexity - O(n)
    if(v.empty()) return 0; // if vector v is empty
    int maxProfit = 0, bestBuy=v[0];
    for(int i=1;i<sz;i++){
        if(bestBuy>v[i]) bestBuy=v[i]; //best Day to buy stock
        if(v[i]>bestBuy) maxProfit=max(maxProfit, v[i]-bestBuy); //check for best selling day
    }
    return maxProfit;
}