/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 08:44:28                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.37 sec                                        memory_used: 3.5M                                 
*  problem: https://www.codechef.com/JULY17/problems/CHEFSIGN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,x,i,ans;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        x=100000;
        ans=0;
        cin>>s;
        map<int,int>mp;
        for(i=0;i<s.size();i++)
        {
            if(mp[x]==0)
            {
                mp[x]=1;
                ans++;
            }
            if(s[i]=='<')x++;
            if(s[i]=='>')x--;
            if(mp[x]==0)
            {
                mp[x]=1;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}