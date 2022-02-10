/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-11 15:48:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 424                                        memory_used (MB): 2.2                             
*  problem: https://vjudge.net/problem/LightOJ-1002
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,m,rt[505],dis[505],tc;
vector<pair<long,long> >adj[505];
struct data
{
    long s;
    long d;
    long c;
}a[16006];
bool cmp(data A,data B)
{
    return A.c<B.c;
}
void mem(void)
{
    for(long i=0;i<=500;i++)
    {
        rt[i]=i;
        adj[i].clear();
    }
}
long root(long x)
{
    while(true)
    {
        if(x==rt[x])return x;
        rt[x]=rt[rt[x]];
        x=rt[x];
    }
}
void dfs(long n,long p,long c)
{
    dis[n]=c;
    for(long i=0;i<adj[n].size();i++)
    {
        long x=adj[n][i].first;
        long w=adj[n][i].second;
        if(x==p)continue;
        dfs(x,n,max(c,w));
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
        mem();
        cin>>n>>m;
        for(long i=1;i<=m;i++)
        {
            cin>>a[i].s>>a[i].d>>a[i].c;
        }
        sort(a+1,a+m+1,cmp);
        long id=0;
        for(long i=1;i<=m;i++)
        {
            long u=a[i].s;
            long v=a[i].d;
            long w=a[i].c;
            long uu=root(u);
            long vv=root(v);
            if(uu!=vv)
            {
                id++;
                adj[u].push_back(make_pair(v,w));
                adj[v].push_back(make_pair(u,w));
                rt[uu]=rt[vv];
            }
        }
        long sou;
        cin>>sou;
        memset(dis,-1,sizeof(dis));
        dfs(sou,-1,0);
        cout<<"Case "<<++tc<<":"<<endl;
        for(long i=0;i<n;i++)
        {
            if(dis[i]==-1)cout<<"Impossible"<<endl;
            else cout<<dis[i]<<endl;
        }
    }
    return 0;
}