/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-08 19:12:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 268                                        memory_used (MB): 4                               
*  problem: https://vjudge.net/problem/LightOJ-1074
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 9999999999999999
using namespace std;
long t,dis[202],cost[202],tc,n,m,u,v,w,q,x;
struct data
{
    long s;
    long d;
    long c;
}arr[100000];
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=1; i<=n; i++)cin>>cost[i];
        cin>>m;
        for(long i=1; i<=m; i++)
        {
            cin>>u>>v;
            arr[i].s=u;
            arr[i].d=v;
            arr[i].c=(cost[v]-cost[u])*(cost[v]-cost[u])*(cost[v]-cost[u]);
        }
        dis[1]=0;
        for(long i=2; i<=n; i++)dis[i]=inf;
        for(long i=1; i<n; i++)
        {
            for(long j=1; j<=m; j++)
            {
                u=arr[j].s;
                v=arr[j].d;
                w=arr[j].c;
                if(dis[u]!=inf)
                {
                    if(dis[u]+w<dis[v])dis[v]=dis[u]+w;
                }
            }
        }
        for(long i=1; i<n; i++)
        {
            for(long j=1; j<=m; j++)
            {
                u=arr[j].s;
                v=arr[j].d;
                w=arr[j].c;
                if(dis[u]!=inf)
                {
                    if(dis[u]+w<dis[v])dis[v]=dis[u]+w;
                }
            }
        }
        long mark[202];
        memset(mark,0,sizeof(mark));
        for(long i=1; i<n; i++)
        {
            for(long j=1; j<=m; j++)
            {
                u=arr[j].s;
                v=arr[j].d;
                w=arr[j].c;
                if(dis[u]+w<dis[v])
                {
                    mark[v]=1;
                    dis[v]=dis[u]+w;
                }
            }
        }
        cin>>q;
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>x;
            if(mark[x]==1||dis[x]>=inf||dis[x]<3)cout<<"?"<<endl;
            else cout<<dis[x]<<endl;
        }
    }
    return 0;
}