/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 13:43:52                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1034
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,vis[10004],n,m,u,v;
vector<long>adj[10004];
void dfs(long node)
{
    vis[node]=1;
    for(long i=0;i<adj[node].size();i++)
    {
        long z=adj[node][i];
        if(vis[z]==0)dfs(z);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        for(long i=1;i<=10000;i++)adj[i].clear();

        cin>>n>>m;
        for(long i=1;i<=m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        long ans=0;
        for(long i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i);
            }
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}