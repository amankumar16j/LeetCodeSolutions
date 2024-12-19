#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        long long count=0;
        int n=nums.size();
        map<int,int> mp;
        int i=0;

        for(int j=0;j<n;j++){
            if(!mp.empty()){
                while(!mp.empty() && (abs((mp.begin()->first)-nums[j])>2 || abs((mp.rbegin()->first)-nums[j])>2)){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
                mp[nums[j]]++;
            }
            else{
                mp[nums[j]]++;
            }

            cout<<i<<" "<<j<<endl;
            count+=(j-i+1);
            
        }

        return count;
        
    }
};