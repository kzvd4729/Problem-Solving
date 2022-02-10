/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-20 09:06:30                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1330
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#define long long long
using namespace std;
vector<long>adj[100005],parr[100005];
long t,n,u,v,lev[100005],cnt[100005],sp[100005][22],root;
void find_level(long node,long par,long lv)
{
    lev[node]=lv;
    parr[node].push_back(par);
    for(long i=0; i<adj[node].size(); i++)
    {
        long x=adj[node][i];
        if(x==par)continue;
        find_level(x,node,lv+1);
    }
}
void sparse_table(void)
{
    for(long i=1; i<=n; i++)sp[i][0]=parr[i][0];
    for(long j=1; j<=20; j++)
    {
        for(long i=1; i<=n; i++)
        {
            if(sp[i][j-1]!=-1)sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }
}
long find_lca(void)
{
    for(long i=20; i>=0; i--)
    {
        if((lev[u]-(1<<i))>=lev[v])
        {
            u=sp[u][i];
        }
    }
    if(u==v)return u;
    ///cout<<u<<" "<<v<<endl;
    for(long i=20;i>=0;i--)
    {
        if(sp[u][i]!=sp[v][i])
        {
            u=sp[u][i];
            v=sp[v][i];
            ///cout<<i<<" "<<u<<" "<<v<<endl;
        }
    }
    return parr[u][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        memset(sp,-1,sizeof(sp));
        cin>>n;
        for(long i=1; i<n; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            cnt[v]++;
        }
        for(long i=1; i<=n; i++)
        {
            if(cnt[i]==0)root=i;
        }
        find_level(root,-1,0);
        sparse_table();
        cin>>u>>v;
        if(lev[u]<lev[v])swap(u,v);
        ///cout<<lev[u]<<" "<<lev[v]<<endl;
        cout<<find_lca()<<endl;

        for(long i=1; i<=100000; i++)
        {
            adj[i].clear();
            parr[i].clear();
            lev[i]=0;
            cnt[i]=0;
        }
    }
    return 0;
}