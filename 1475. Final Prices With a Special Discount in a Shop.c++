#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& price) {

        int n=price.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=price[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(price[i]>=price[j]){
                    ans[i]=price[i]-price[j];
                    break;
                }
            }
        }
        return ans;
    }
};