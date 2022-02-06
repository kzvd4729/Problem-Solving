/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2017 10:59                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/2/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s[1003];
int x[1003],ans=-99999999,n;
map<string,int>mp,mp2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>x[i];
        mp[s[i]]+=x[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,mp[s[i]]);
    }
     /*for(int i=1;i<=n;i++)
    {
        cout<<mp[s[i]]<<endl;
    }*/
    ///cout<<ans<<endl;
     for(int i=1;i<=n;i++)
    {
        if(mp[s[i]]==ans)
        {
            mp2[s[i]]=1;
        }
    }
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        mp[s[i]]+=x[i];
        if(mp[s[i]]==ans&&mp2[s[i]]==1)
        {
            cout<<s[i]<<endl;
            return 0;
        }
    }
    return 0;
}