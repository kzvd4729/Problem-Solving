/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-27 12:36:32                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6981
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,vis[20004],arr[20004],n,m,u,v,w;
vector<pair<long,long> >adj[20004];
priority_queue<pair<long,long> >pq;
struct data
{
    long uu,vv,ww;
} edge[40004];
bool cmp(data A,data B)
{
    return A.ww<B.ww;
}
void dfs(long node)
{
    vis[node]=1;
    for(long i=0;i<adj[node].size();i++)
    {
        long zz=adj[node][i].first;
        if(vis[zz]==0)dfs(zz);
    }
}
long root(long node)
{
    while(node!=arr[node])
    {
        arr[node]=arr[arr[node]];
        node=arr[node];
    }
    return node;
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
        for(long i=0; i<=n; i++)
        {
            adj[i].clear();
            vis[i]=0;
            arr[i]=i;
        }
        for(long i=1; i<=m; i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            edge[i].uu=u;
            edge[i].vv=v;
            edge[i].ww=w;
        }
        dfs(0);
        long f=0,sum=0,cost=0;
        for(long i=0; i<n; i++)
        {
            if(vis[i]==0)f=1;
            vis[i]=0;
        }

        sort(edge+1,edge+m+1,cmp);

        for(long i=1;i<=m;i++)
        {
            long xx=root(edge[i].uu);
            long yy=root(edge[i].vv);
            if(xx==yy)continue;
            arr[xx]=yy;
            cost+=edge[i].ww;
        }
        pq.push({0,0});
        while(pq.size())
        {
            ///cout<<pq.size()<<endl;
            long xx=pq.top().second;
            long ww=-pq.top().first;
            pq.pop();
            if(vis[xx]==1)continue;
            vis[xx]=1;
            sum+=ww;
            for(long i=0;i<adj[xx].size();i++)
            {
                long zz=adj[xx][i].first;
                if(vis[zz]==1)continue;
                pq.push({-(ww+adj[xx][i].second),zz});
            }
        }

        ///cout<<f<<" "<<cost<<" "<<sum<<endl;
        if(f==0&&cost==sum)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}