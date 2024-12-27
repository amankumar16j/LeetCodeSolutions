#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& po) {

        int m=po.size();
        int n=po[0].size();

        vector<long long> prev(po[0].begin(),po[0].end());
        for(int k=1;k<m;k++){
            vector<long long> left(n),right(n),curr(n);

            left[0]=prev[0];
            for(int i=1;i<n;i++){
                left[i]=max(left[i-1]-1,prev[i]);
            }

            right[n-1]=prev[n-1];
            for(int i=n-2;i>=0;i--){
                right[i]=max(right[i+1]-1,prev[i]);
            }

            for(int i=0;i<n;i++){
                curr[i]=po[k][i]+max(right[i],left[i]);
            }
            prev=curr;

        }

        return *max_element(prev.begin(),prev.end());
        
    }
};