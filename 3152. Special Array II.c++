#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {

        int n=nums.size();
        vector<bool> pre(n,true);
        vector<int> pre2(n);
        pre2[0]=1;

        for(int i=0;i<n;i++){
            if(i==n-1){
                if(i-1>=0 && (nums[i]%2==0)==(nums[i-1]%2==0))
                    pre[i]=false;
            }
            else{
                if(i-1>=0 && (nums[i]%2==0)==(nums[i-1]%2==0))
                    pre[i]=false;
            }

            if(i!=0)
            pre2[i]=pre2[i-1]+pre[i];

        }

        // for(int i=1;i<n;i++){
        //     pre2[i]=pre2[i-1]+pre[i];
        // }

        vector<bool> vec(q.size(),true);
        int f=0;
        for(auto i:q){
            if((i[1]-i[0])!=(pre2[i[1]]-pre2[i[0]])){
                vec[f]=false;
            }
            f++;
        }

        return vec;
    }
};