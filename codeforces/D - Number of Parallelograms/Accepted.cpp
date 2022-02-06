/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/08/2017 10:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1918 ms                                         memory_used: 96100 KB                             
*  problem: https://codeforces.com/contest/660/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,u,v,ans;
map<pair<long,long>,long>mp;
struct data
{
    long u;
    long v;
}arr[2002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i].u>>arr[i].v;
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            mp[{arr[i].u+arr[j].u,arr[i].v+arr[j].v}]++;
        }
    }
    for(auto x:mp)
    {
        long z=x.second;
        ///cout<<z<<endl;
        ans+=((z*(z-1))/2);
    }
    cout<<ans<<endl;
    return 0;
}