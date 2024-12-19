#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k--){
            int tp=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            tp=tp*multi;
            pq.push({tp,idx});
        }

        vector<int> ans(nums.size());
        while(!pq.empty()){
            int val=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            ans[idx]=val;
        }

        return ans;
        
    }
};