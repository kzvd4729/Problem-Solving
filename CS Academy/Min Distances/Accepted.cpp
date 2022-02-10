/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 119 ms                                          memory_used: 724 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=9999999999999;
long dis[102],node,dist,vis[102],f,n,m,u,v,w,uu,mat[102][102],cc;
vector<pair<long,long> >adj[102];
priority_queue<pair<long,long> >q;
long bfs(long sr,long ds)
{
    for(long i=0;i<=n;i++)dis[i]=inf,vis[i]=0;
    q.push({0,sr});
    dis[sr]=0;
    vis[sr]=1;
    if(vis[ds])return dis[ds];
    while(q.size())
    {
        node=q.top().second;
        vis[node]=1;
        q.pop();
        for(auto x:adj[node])
        {
            if(vis[x.first])continue;
            if(dis[node]+x.second<dis[x.first])
            {
                dis[x.first]=dis[node]+x.second;
                q.push({-dis[x.first],x.first});
            }
        }
    }
    return dis[ds];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        uu=min(u,v);
        v=max(u,v);
        u=uu;
        if(u==v)f=1;
        if(mat[u][v])if(mat[u][v]!=w)f=1;
        mat[u][v]=w;
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            if(mat[i][j])
            {
                cc=bfs(i,j);
                if(cc==inf)continue;
                if(cc!=mat[i][j])f=1;
            }
        }
    }
    if(f)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(long i=1;i<=n;i++)
    {
        if(bfs(1,i)==inf)
        {
            adj[1].push_back({i,1});
            adj[i].push_back({1,1});
            mat[1][i]=1;
        }
    }
    long ans=0;
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            if(mat[i][j])ans++;
        }
    }
    cout<<ans<<endl;
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            if(mat[i][j])
            {
                cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
            }
        }
    }
    return 0;
}