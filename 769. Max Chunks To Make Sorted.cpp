#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int last=-1;
        int count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            last=max(arr[i],last);
            if(last==i){
                count++;
            }
        }
        return count;   
    }
};