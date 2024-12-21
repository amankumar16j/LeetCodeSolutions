#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(string s) {

        int n=s.size();
        map<string,int> mp;
        for(int i=0;i<n;i++){
            string st="";
            int flag=0;
            st=+s[i];
            while(i<n && s[i+1]==s[i]){
                st=st+s[i+1];
                i++;
                flag=1;
            }

            if(!flag)
                mp[st]++;
            else{
                for(int j=1;j<=st.size();j++){
                    string sin=st.substr(0,j);
                    mp[sin]+=(st.size()-(j-1));
                }
            }
        }


        int maxi=-1;
        // for(auto i:mp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }


        for(auto i:mp){
            if(i.first.size()<3){
                if(i.second>=3){
                    int si=(i.first.size());
                    maxi=max(maxi,si);
                }
            }
            else{
                if(i.second>=3){
                    int si=(i.first.size());
                    maxi=max(si,maxi);
                }
                else{
                    int si=((i.first.size())-2);
                    maxi=max(si,maxi);
                }
            }

        }

        return maxi;
    }
};