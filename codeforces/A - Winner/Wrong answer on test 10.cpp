/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2017 10:42                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/2/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s[1003];
int x[1003],ans,n;
map<string,int>mp;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>x[i];
        mp[s[i]]+=x[i];
        ans=max(ans,mp[s[i]]);
    }
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        mp[s[i]]+=x[i];
        if(mp[s[i]]==ans)
        {
            cout<<s[i]<<endl;
            return 0;
        }
    }
    return 0;
}