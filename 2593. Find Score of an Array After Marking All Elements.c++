#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long findScore(vector<int>& nums) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> mark(nums.size(),0);
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        long long sum=0;
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            if(!mark[tp.second]){
                sum+=tp.first;
                mark[tp.second]=1;
                if(tp.second+1<n)
                    mark[tp.second+1]=1;
                if(tp.second-1>=0)
                    mark[tp.second-1]=1;
            }
        }

        return sum;
        
    }
};