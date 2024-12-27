class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {

        int n=val.size();
        int maxi=INT_MIN;
        int a=val[0];
        for(int i=1;i<n;i++){
            a--;
            maxi=max(a+val[i],maxi);
            a=max(a,val[i]);
        }  
        return maxi;
    }
};