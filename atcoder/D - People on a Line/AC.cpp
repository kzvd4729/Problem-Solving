/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-28 19:08:18                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 70 ms                                           memory_used: 11648 KB                             
*  problem: https://atcoder.jp/contests/arc090/tasks/arc090_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,u,v,w,dis[100005],f,vis[100005],dd[100005];
vector<pair<int,int> >adj[100005];
void dfs(int node,int d)
{
    if(vis[node]==0)
    {
        vis[node]=1;
        dis[node]=d;
    }
    else
    {
        if(dis[node]!=d)f=1;
        return ;
    }
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i].first;
        int w=adj[node][i].second;
        dfs(v,d+w);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        dd[v]++;
     }
    for(int i=1;i<=n;i++)
    {
        if(!dd[i])dfs(i,0);
    }
    for(int i=1;i<=n;i++)if(!vis[i])f=1;
    if(f)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}