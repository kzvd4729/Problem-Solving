/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2018 19:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1169 ms                                         memory_used: 117300 KB                            
*  problem: https://codeforces.com/contest/609/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e16;
long n,m,u,v,w,mst,uu,vv,root[200005],par[200005],sp[200005][20][2],mx,level[200005];
vector<pair<long,long> >adj[200005];
map<pair<long,long>,long>mp;
struct data
{
    long u,v,w;
} arr[200005],st[200005];
bool cmp(data A,data B)
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
long find_mst(void)
{
    sort(arr+1,arr+m+1,cmp);
    for(long i=1; i<=n; i++)
        root[i]=i;
    for(long i=1; i<=m; i++)
    {
        u=arr[i].u;
        v=arr[i].v;
        w=arr[i].w;
        uu=find_root(u);
        vv=find_root(v);
        if(uu!=vv)
        {
            ///cout<<u<<" "<<v<<" "<<w<<endl;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            mp[ {min(u,v),max(u,v)}]=w;
            root[uu]=vv;
            mst+=arr[i].w;
        }
    }
}
void find_level(long node,long pr,long hh)
{
    par[node]=pr;
    level[node]=hh;
    for(auto x:adj[node])
    {
        if(x.first==pr)continue;
        find_level(x.first,node,hh+1);
    }
}
void make_sparse(void)
{
    long tmp;
    for(long i=1; i<=n; i++)
    {
        sp[i][0][0]=par[i];
        sp[i][0][1]=mp[ {min(i,par[i]),max(i,par[i])}];
    }
    for(long j=1; j<=17; j++)
    {
        for(long i=1; i<=n; i++)
        {
            tmp=sp[i][j-1][0];
            if(tmp==-1)
            {
                sp[i][j][0]=-1;
                sp[i][j][1]=sp[i][j-1][1];
            }
            else
            {
                sp[i][j][0]=sp[tmp][j-1][0];
                sp[i][j][1]=max(sp[i][j-1][1],sp[tmp][j-1][1]);
            }
        }
    }
    ///for(long i=0;i<=17;i++)cout<<sp[2][i][0]<<endl;
//    for(long i=1; i<=n; i++)
//    {
//        for(long j=0; j<=17; j++)
//            cout<<sp[i][j][0]<<" ";
//        cout<<endl;
//    }
}
void find_lca(long u,long v)
{
    mx=0;
    if(level[u]<level[v])swap(u,v);
    ///cout<<u<<" "<<v<<endl;
    ///cout<<sp[u][10][0]<<endl;
    for(long i=17; i>=0; i--)
    {
//        cout<<u<<endl;
//        cout<<sp[u][i][0]<<endl;
        if(sp[u][i][0]==-1)continue;
        if(level[sp[u][i][0]]>=level[v])
        {
            mx=max(mx,sp[u][i][1]);
            ///cout<<u<<" "<<sp[u][i][1]<<endl;
            u=sp[u][i][0];
        }
    }
    ///cout<<u<<" "<<v<<endl;
    if(u==v)
        return ;
        ///cout<<"Here"<<endl;
    for(long i=17; i>=0; i--)
    {
        if(sp[u][i][0]!=sp[v][i][0])
        {
            mx=max(mx,sp[u][i][1]);
            mx=max(mx,sp[v][i][1]);
            u=sp[u][i][0];
            v=sp[v][i][0];
        }
    }
    mx=max(mx,mp[ {min(u,par[u]),max(u,par[u])}]);
    mx=max(mx,mp[ {min(v,par[v]),max(v,par[v])}]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>m;
    for(long i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        arr[i]= {u,v,w};
        st[i]=arr[i];
    }
    ///cout<<endl<<endl;
    find_mst();
    find_level(1,-1,0);
    make_sparse();
//    while(cin>>u>>v)
//    {
//        find_lca(u,v);
//        cout<<mx<<endl;
//    }
 //    find_lca(7,5);
//    cout<<mx<<endl;
     for(long i=1; i<=m; i++)
    {
//        if(mp[{min(st[i].u,st[i].v),max(st[i].u,st[i].v)}])cout<<mst<<endl;
//        else
//        {
//            find_lca(st[i].u,st[i].v);
//            ///cout<<st[i].u<<" "<<st[i].v<<" "<<mx<<endl;
//            cout<<mst-mx+st[i].w<<endl;
//        }
            find_lca(st[i].u,st[i].v);
            ///cout<<st[i].u<<" "<<st[i].v<<" "<<mx<<endl;
            cout<<mst-mx+st[i].w<<endl;
    }
    return 0;
}