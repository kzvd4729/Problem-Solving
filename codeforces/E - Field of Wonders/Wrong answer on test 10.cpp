/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 09:42                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/883/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,cnt,ans;
string s,ss[1003];
map<long,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>s>>m;
    for(long i=0; i<n; i++)
    {
        if(s[i]=='*')
        {
            cnt++;
            continue;
        }
        mp[s[i]]=1;
    }
    for(long i=1;i<=m;i++)
    {
        cin>>ss[i];
        for(long j=0;j<n;j++)
        {
            if(mp[ss[i][j]]==0)ans++;
            mp[ss[i][j]]=1;
        }
    }
    if(ans>cnt)cout<<0<<endl;
    else cout<<ans<<endl;
     return 0;
}