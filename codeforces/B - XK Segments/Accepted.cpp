/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/27/2017 13:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 9300 KB                              
*  problem: https://codeforces.com/contest/895/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,k,arr[100005],ans;
map<long,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>x>>k;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    if(k==0)
    {
        for(long i=n; i>=1; i--)
        {
            if(arr[i]%x==0)continue;
            mp[arr[i]/x]++;
            ans+=mp[arr[i]/x];
        }
        mp.clear();
        for(long i=n; i>=1; i--)
        {
            if(arr[i]%x==0)continue;
            ans+=mp[arr[i]];
            mp[arr[i]]++;
        }
        /*for(long i=1; i<=n; i++)
        {
            if(arr[i]%x==0)continue;
            ans+=mp[arr[i]/x];
            mp[arr[i]/x]++;
        }*/
        cout<<ans<<endl;
        return 0;
     }
    for(long i=n; i>=1; i--)
    {
        mp[arr[i]/x]++;
        ans+=mp[((arr[i]-1)/x)+k];
    }
    mp.clear();
    for(long i=1; i<=n; i++)
    {
        ans+=mp[((arr[i]-1)/x)+k];
        mp[arr[i]/x]++;
    }
    cout<<ans<<endl;
     return 0;
}