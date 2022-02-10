/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-20 22:51:05                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1002
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
#define inf 99999999
using namespace std;
long t,n,m,i,u,v,c,w,cost[505][505],vis[504],d,xx,cc,j,tc=0,k,x;
vector<long>adj[505];
queue<pair<long,long> >q;
void mem(void)
{
    for(i=0;i<=503;i++)adj[i].clear();
    for(i=0;i<504;i++)
    {
        for(j=0;j<504;j++)
        {
            cost[i][j]=inf;
        }
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        mem();
        cin>>n>>m;
        for(i=1;i<=m;i++)
        {
            cin>>u>>v>>w;
            if(cost[u][v])adj[u].push_back(v);
            if(cost[v][u])adj[v].push_back(u);
            cost[u][v]=min(cost[u][v],w);
            cost[v][u]=min(cost[v][u],w);
        }
        cin>>d;
        cout<<"Case "<<++tc<<":"<<endl;
        for(i=0;i<n;i++)
        {
            if(i==d)
            {
                cout<<0<<endl;
                continue;
            }
            while(!q.empty())q.pop();
            memset(vis,0,sizeof(vis));
            q.push(make_pair(i,0));
            long ans=inf;
            while(!q.empty())
            {
                xx=q.front().first;
                vis[xx]=1;
                cc=q.front().second;
                q.pop();
                for(k=0;k<adj[xx].size();k++)
                ///for(long x:adj[xx])
                {
                    x=adj[xx][k];
                    long ccc=max(cc,cost[xx][x]);
                    if(x==d)
                    {
                        ans=min(ans,ccc);
                    }
                    if(!vis[x])q.push(make_pair(x,ccc));
                }
            }
            if(ans==inf)
            {
                cout<<"Impossible"<<endl;
            }
            else cout<<ans<<endl;
        }

    }
    return 0;
}