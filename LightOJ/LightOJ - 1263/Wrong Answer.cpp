/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-26 21:45:52                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1263
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,n,m,u,v,mon[1002],tot,par,f,cost,sz,vis[1002];
vector<int>adj[1002];
void dfs(int node)
{
    for(int i=0;i<adj[node].size();i++)
    {
        int xx=adj[node][i];
        if(vis[xx])continue;
        vis[xx]=1;
        cost+=mon[xx];
        sz++;
        dfs(xx);
    }
}
int main()
{
    ///ofstream cout("out.txt");
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&n,&m);
        tot=0,f=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%ld",&mon[i]);
            tot+=mon[i];
        }
        if(tot%n)f=1;
        par=tot/n;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%ld%ld",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            vis[i]=1;
            cost=mon[i],sz=1;
            dfs(i);
            if(cost%sz)f=1;
            if((cost/sz)!=par)f=1;
        }
        if(f)cout<<"Case "<<++tc<<": No"<<endl;
        else cout<<"Case "<<++tc<<": Yes"<<endl;

    }
    return 0;
}