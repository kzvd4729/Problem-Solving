/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-26 00:38:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12376
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,m,cost[102],u,v,tc,vis[102];
vector<long>adj[104];
bool cmp(long a,long b)
{
    return cost[a]>cost[b];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(long i=0;i<n;i++)cin>>cost[i];
        for(long i=0;i<n;i++)adj[i].clear();
        for(long i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(long i=0;i<n;i++)sort(adj[i].begin(),adj[i].end(),cmp);
        long ans=0,last=0;
        long now=0;
        while(true)
        {
            last=now;
            if(adj[now].size()==0)break;
            now=adj[now][0];
            ans+=cost[now];
        }
        cout<<"Case "<<++tc<<": "<<ans<<" "<<last<<endl;
    }
    return 0;
}