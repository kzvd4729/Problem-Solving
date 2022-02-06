/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/15/2017 20:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/890/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[200005],cnt,vis[200005],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=n;i>=1;i--)
    {
        if(vis[i])continue;
        cnt++;
        vis[i]=1;
        long x=i;
        while(arr[x]!=0)
        {
            x=arr[x];
            vis[x]=1;
        }
    }
    cout<<cnt<<endl;
     return 0;
}