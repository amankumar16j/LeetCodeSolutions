#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool possible(vector<int> &vec,int mid,int op){
        int n=vec.size();
        int numop=0;
        for(int i=0;i<n;i++){
            if(vec[i]>mid)
                numop=numop+ceil((double)vec[i]/mid)-1;
            if(numop>op) return false;
        }
        return true;
    }


    int minimumSize(vector<int>& nums, int op) {

        int maxi=*max_element(nums.begin(),nums.end());
        // cout<<maxi;
        int l=1;
        int h=maxi;
        int ans;
        int mid;

        while(l<=h){
            mid=(l+h)/2;
            if(possible(nums,mid,op)){
                cout<<mid<<endl;
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;   
    }
};