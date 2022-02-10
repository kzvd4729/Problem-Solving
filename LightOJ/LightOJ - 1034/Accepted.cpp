/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 15:16:53                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 108                                        memory_used (MB): 4                               
*  problem: https://vjudge.net/problem/LightOJ-1034
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>adj[10002];
priority_queue<pair<long,long> >pq;
long n,m,t,tc,u,v,vis[10004],cnt[10004];
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
        memset(cnt,0,sizeof(cnt));

        cin>>n>>m;
        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            cnt[v]++;
        }
        for(long i=1;i<=n;i++)
        {
            pq.push({-cnt[i],i});
        }
        long ans=0;
        while(pq.size())
        {
            long x=pq.top().second;
            pq.pop();
            if(vis[x]==0)
            {
                ans++;
                dfs(x);
            }
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}