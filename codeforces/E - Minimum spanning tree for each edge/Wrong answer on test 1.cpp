/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 23:57                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 116900 KB                            
*  problem: https://codeforces.com/contest/609/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,mst,root[200005],sp[22][200005][3],level[200005];
vector<pair<long,long> >adj[200005];
map<pair<long,long>,long>mp;
struct edge
{
    long u,v,w,id;
} ed[200005];
bool cmp(edge A,edge B)
{
    return A.w<B.w;
}
long find_root(long node)
{
    while(node!=root[node])
    {
        root[node]=root[root[node]];
        node=root[node];
    }
    return node;
}
void dfs(long node,long par,long cost,long lev)
{
    level[node]=lev;
    sp[0][node][0]=par;
    sp[0][node][1]=cost;
    for(auto x:adj[node])
    {
        if(x.first==par)continue;
        dfs(x.first,node,x.second,lev+1);
    }
}
void sparse_table(void)
{
    for(long i=1; i<=20; i++)
    {
        for(long j=1; j<=n; j++)
        {
            sp[i][j][0]=sp[i-1][j+(1<<(i-1))][0];
            sp[i][j][1]=max(sp[i-1][j][1],sp[i-1][j+(1<<(i-1))][1]);
        }
    }
}
long lca(long u,long v)
{
    if(level[u]<level[v])swap(u,v);
    long ans=0;
    for(long i=20; i>=0; i--)
    {
        if(level[sp[i][u][0]]>=level[v])
        {
            u=sp[i][u][0];
            ans=max(ans,sp[i][u][1]);
        }
    }
    if(u==v)return ans;
    for(long i=20; i>=0; i--)
    {
        if(sp[i][u][0]!=sp[i][v][0])
        {
            u=sp[i][u][0];
            v=sp[i][v][0];
            ans=max(ans,sp[i][u][0]);
            ans=max(ans,sp[i][v][0]);
        }
    }
    ans=max(ans,sp[0][u][1]);
    ans=max(ans,sp[0][v][1]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1; i<=m; i++)
    {
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
        ed[i].id=i;
    }
    sort(ed+1,ed+m+1,cmp);
    for(long i=1; i<=n; i++)root[i]=i;
    for(long i=1; i<=m; i++)
    {
        long uu=find_root(ed[i].u);
        long vv=find_root(ed[i].v);
        if(uu==vv)continue;
        adj[ed[i].u].push_back({ed[i].v,ed[i].w});
        adj[ed[i].v].push_back({ed[i].u,ed[i].w});
        mp[{min(ed[i].u,ed[i].v),max(ed[i].u,ed[i].v)}]=1;
        root[uu]=vv;
        mst+=ed[i].w;
    }
    dfs(1,-1,0,0);
//    for(long i=1;i<=n;i++)
//    {
//        cout<<i<<": ";
//        for(auto x:adj[i])
//        {
//            cout<<x.first<<" ";
//        }
//        cout<<endl;
//    }
//    for(long i=1;i<=n;i++)
//    {
//        cout<<sp[0][i][0]<<" "<<sp[0][i][1]<<endl;
//    }
    sparse_table();
    for(long j=1;j<=n;j++)
    {
        for(long i=1;i<=5;i++)
        {
            cout<<sp[i][j][0]<<" ";
        }
        cout<<endl;
    }
    long ans[200005];
    for(long i=1; i<=m; i++)
    {
        if(mp[{min(ed[i].u,ed[i].v),max(ed[i].u,ed[i].v)}]==1)ans[ed[i].id]=mst;
        else
        {
            //cout<<"yes"<<endl;
            ///cout<<lca(ed[i].u,ed[i].v)<<endl;
            cout<<ed[i].u<<" "<<ed[i].v<<" "<<lca(ed[i].u,ed[i].v)<<endl;
            ans[ed[i].id]=mst-lca(ed[i].u,ed[i].v)+ed[i].w;
        }
    }
    ///for(long i=1; i<=m; i++)cout<<ans[i]<<endl;
    return 0;
}