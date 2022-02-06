/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2017 21:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 11900 KB                             
*  problem: https://codeforces.com/contest/893/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,cost[100005],vis[100005],uu,vv;
vector<long>adj[100005],v;
void dfs(long node)
{
    if(vis[node]==0)
    {
        v.push_back(node);
        vis[node]=1;
    }
    for(long i=0; i<adj[node].size(); i++)
    {
        long z=adj[node][i];
        if(vis[z]==1)continue;
        dfs(z);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1; i<=n; i++)
    {
        cin>>cost[i];
    }
    for(long i=1; i<=m; i++)
    {
        cin>>uu>>vv;
        adj[uu].push_back(vv);
        adj[vv].push_back(uu);
    }
    long ans=0;
    for(long i=1; i<=n; i++)
    {
        v.clear();
        if(vis[i]==0)
        {
            dfs(i);
            long mn=999999999999;
            for(long j=0; j<v.size(); j++)
            {
                if(cost[v[j]]<mn)mn=cost[v[j]];
            }
            ans+=mn;
        }
    }
    cout<<ans<<endl;
    return 0;
}