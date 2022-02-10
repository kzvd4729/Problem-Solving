/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-28 15:13:30                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1063
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,tim,n,m,u,v,vis[10004],disc[10004],parent[10004],ans,low[10004],art[10004];
vector<int>adj[10004];
void dfs(int node)
{
    disc[node]=low[node]=++tim;
    vis[node]=1;
    int child=0;
    for(int i=0;i<adj[node].size();i++)
    {
        int x=adj[node][i];
        if(vis[x])low[node]=min(low[node],disc[x]);
        else
        {
            child++;
            parent[x]=node;
            dfs(x);
            low[node]=min(low[node],low[x]);
            if(parent[node]!=-1&&low[x]>=disc[node])art[node]=1;
            if(parent[node]==-1&&child>1)art[node]=1;
        }
    }

}
int main()
{
    ///ofstream cout("out.txt");
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&n,&m);
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%ld%ld",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tim=0,ans=0;
        memset(vis,0,sizeof(vis));
        memset(art,0,sizeof(art));
        memset(parent,-1,sizeof(parent));
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
        for(int i=1;i<=n;i++)if(art[i])ans++;
        ///printf("Case %ld: %ld\n",++tc,ans);
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}