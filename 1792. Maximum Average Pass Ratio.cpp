#include<bits/stdc++.h>
using namespace std;
#define d double

class Solution {
public:
    double gain(d a,d b){
        return ((a+1)/(b+1))-(a/b);
    }
    double maxAverageRatio(vector<vector<int>>& cls, int es) {

        priority_queue<tuple<d,d,d>> pq;

        for(auto i:cls){
            pq.push({gain(double(i[0]),double(i[1])),double(i[0]),double(i[1])});
        }

        while(es){
            auto [_,a,b]=pq.top();
            pq.pop();
            a++;
            b++;
            pq.push({gain(a,b),a,b});
            es--;
        }

        double avgsum=0.0;
        while(!pq.empty()){
            auto [_,a,b]=pq.top();
            pq.pop();
            double avg=a/b;
            avgsum+=avg;
        }
        double ans=avgsum/(double)cls.size();

        return ans;
    }
};