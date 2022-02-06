/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2017 22:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/514/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long x0,y0,vis[10004],ans,n;
struct ponit
{
    long x;
    long y;
}p[10004];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>x0>>y0;
    for(long i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
    for(long i=1;i<=n;i++)
    {
        if(vis[i])continue;
        ans++;
        vis[i]=1;
        for(long j=1;j<=n;j++)
        {
            if((p[i].y-y0)*(p[j].x-x0)==(p[i].x-x0)*(p[j].y-y0))vis[j]=1;
        }
    }
    cout<<ans<<endl;
     return 0;
}
 