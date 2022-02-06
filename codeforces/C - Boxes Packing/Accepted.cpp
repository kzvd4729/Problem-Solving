/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/14/2017 11:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/903/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,n,x;
map<long,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    while(n--)
    {
        cin>>x;
        mp[x]++;
    }
    for(map<long,long>::iterator it=mp.begin();it!=mp.end();it++)
    {
        ans=max(ans,it->second);
    }
    cout<<ans<<endl;;
     return 0;
}