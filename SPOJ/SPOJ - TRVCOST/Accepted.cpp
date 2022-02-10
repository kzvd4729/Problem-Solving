/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-01 21:44:59                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-TRVCOST
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=9999999999999;
long dis[505],n,u,v,w,s,node,vis[505],q;
vector<pair<long,long> >adj[505];
priority_queue<pair<long,long> >pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(long i=0;i<=500;i++)dis[i]=inf;
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin>>s;
    dis[s]=0;
    pq.push({0,s});
    while(pq.size())
    {
        node=pq.top().second;
        vis[node]=1;
        pq.pop();
        for(auto x:adj[node])
        {
            if(vis[x.first])continue;
            dis[x.first]=min(dis[x.first],dis[node]+x.second);
            pq.push({-dis[x.first],x.first});
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>v;
        if(dis[v]>=inf)cout<<"NO PATH"<<endl;
        else cout<<dis[v]<<endl;
    }
    return 0;
}