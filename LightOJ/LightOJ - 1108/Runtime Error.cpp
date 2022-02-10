/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-08 21:29:57                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1108
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 9999999999999999
using namespace std;
long t,dis[2002],cost[2002],tc,n,m,u,v,w,q,x,vis[2002],rt;
vector<long>adj[2002],vc;
struct data
{
    long s;
    long d;
    long c;
} arr[2002];
void dfs(long rt)
{
    vc.push_back(rt);
    vis[rt]=1;
    for(long i=0; i<adj[rt].size(); i++)
    {
        if(vis[adj[rt][i]]==0)dfs(adj[rt][i]);
    }
}
int main()
{
    ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(long i=1; i<=m; i++)
        {
            cin>>u>>v>>w;
            arr[i].s=u;
            arr[i].d=v;
            arr[i].c=w;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dis[0]=0;
        for(long i=1; i<n; i++)dis[i]=inf;
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
        long f=0;
        for(long j=1; j<=m; j++)
        {
            u=arr[j].s;
            v=arr[j].d;
            w=arr[j].c;
            if(dis[u]+w<dis[v])
            {
                f=1;
                rt=v;
                dis[v]=dis[u]+w;
                break;
            }
        }
        if(f==0)cout<<"Case "<<++tc<<": impossible"<<endl;
        else
        {
            memset(vis,0,sizeof(vis));
            dfs(rt);
            sort(vc.begin(),vc.end());
            cout<<"Case "<<++tc<<": ";
            for(long i=0; i<vc.size(); i++)
            {
                cout<<vc[i];
                if(i!=vc.size()-1)cout<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}