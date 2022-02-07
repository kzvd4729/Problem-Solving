/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 15:45:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11518
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>adj[10004];
long vis[10004],n,m,l,u,v,t,x;
void dfs(long node)
{
    vis[node]=1;
    for(long i=0;i<adj[node].size();i++)
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

    cin>>t;
    while(t--)
    {
        for(long i=0;i<=10000;i++)adj[i].clear();
        memset(vis,0,sizeof(vis));

        cin>>n>>m>>l;
        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        while(l--)
        {
            cin>>x;
            if(vis[x]==1)continue;
            dfs(x);
        }
        long ans=0;
        for(long i=1;i<=n;i++)if(vis[i])ans++;
        cout<<ans<<endl;
    }


    return 0;
}