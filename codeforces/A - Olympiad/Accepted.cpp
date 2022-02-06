/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2018 22:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/937/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans,arr[1003],vis[1003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(long i=1;i<=n;i++)
    {
        if(arr[i]==0)continue;
        if(vis[arr[i]]==0)
        {
            ans++;
            vis[arr[i]]=1;
        }
     }
    cout<<ans<<endl;
    return 0;
}