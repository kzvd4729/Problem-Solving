/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time: 1095 ms                                         memory_used: 2444 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=9999999999999;
long dis[102],node,dist,vis[102],f,n,m,u,v,w,uu;
vector<pair<long,long> >adj[102];
map<pair<long,long>,long>mp;
long bfs(long sr,long ds)
{
    for(long i=0;i<=100;i++)dis[i]=inf,vis[i]=0;
    priority_queue<pair<long,long> >q;
    q.push({0,sr});
    dis[sr]=0;
    vis[sr]=1;
    while(q.size())
    {
        node=q.top().second;
        vis[node]=1;
        q.pop();
        for(auto x:adj[node])
        {
            if(vis[x.first])continue;
            dis[x.first]=min(dis[x.first],dis[node]+x.second);
            q.push({-dis[x.first],x.first});
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
        if(mp[{u,v}])if(mp[{u,v}]!=w)f=1;
        mp[{u,v}]=w;
    }
    ///cout<<f<<endl;
    for(auto x:mp)
    {
        long cc=bfs(x.first.first,x.first.second);
        ///cout<<x.first.first<<" "<<x.first.second<<" "<<cc<<endl;
        ///cout<<cc<<endl;
        if(cc==inf)continue;
        if(cc!=x.second)f=1;
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
            mp[{1,i}]=1;
        }
    }
    cout<<mp.size()<<endl;
    for(auto x:mp)
    {
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    }
    return 0;
}