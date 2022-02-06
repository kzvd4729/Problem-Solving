/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2018 23:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 18400 KB                             
*  problem: https://codeforces.com/contest/931/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,cnt[100005],mx,x,ans,xr,sum;
vector<long>adj[100005],lev[100005];
long dfs(long node,long par,long hg)
{
    ///cout<<hg<<endl;
    lev[hg].push_back(node);
    for(auto x:adj[node])
    {
        if(x==par)continue;
        dfs(x,node,hg+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=2;i<=n;i++)
    {
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
     dfs(1,-1,0);
     ans=1;
    for(long i=0;i<=n;i++)
    {
        sum=0;
        for(auto x:lev[i])sum+=adj[x].size();
        xr+=sum;
        xr%=2;
        ans+=xr;
    }
    cout<<ans<<endl;
  //    for(long i=0;i<n;i++)cnt[i]=1;
//    dfs(1,-1,0);
//    for(long i=0;i<=mx;i++)ans+=cnt[i];
//    cout<<ans<<endl;
    return 0;
}