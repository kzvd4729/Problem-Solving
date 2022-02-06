/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/13/2017 14:56                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 13800 KB                             
*  problem: https://codeforces.com/contest/519/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int lev[100005],sz[100005],sp[100005][20],par[10005];
vector<int>adj[100005];
int n,u,v,q,lc;
void find_level(int n,int p,int h)
{
    lev[n]=h;
    par[n]=p;
    sz[n]=1;
    for(int i=0;i<adj[n].size();i++)
    {
        if(adj[n][i]==p)continue;
        find_level(adj[n][i],n,h+1);
        sz[n]+=sz[adj[n][i]];
    }
}
void sparse(void)
{
    for(int i=1;i<=n;i++)
    {
        sp[i][0]=par[i];
    }
    for(int j=1;j<=18;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(sp[i][j-1]!=-1)sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v)
{
    for(int i=18;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[v])
        {
            if(sp[u][i]!=-1)u=sp[u][i];
        }
    }
    if(u==v)return u;
    for(int i=18;i>=0;i--)
    {
        if(sp[u][i]!=-1&&sp[u][i]!=sp[v][i])
        {
            u=sp[u][i];
            v=sp[v][i];
        }
    }
    return par[u];
}
int raise(int u,int d)
{
    for(int i=18;i>=0;i--)
    {
        if((1<<i)<=d&&sp[u][i]!=-1)
        {
            u=sp[u][i];
            d=d-(1<<i);
        }
    }
    return u;
}
int main()
{
    cin>>n;
    int N=n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_level(1,-1,0);
    sparse();
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        if(lev[u]<lev[v])swap(u,v);
        lc=lca(u,v);
        ///cout<<lc<<endl;
        int dis=lev[u]+lev[v]-lev[lc]*2;
        if(dis%2==1)
        {
            cout<<0<<endl;
        }
        else
        {
            dis=dis/2;
            int ans;
            if(u==v)
            {
                cout<<n<<endl;
            }
            else if(lev[u]==lev[v])
            {
                ans=N-sz[raise(u,dis-1)]-sz[raise(v,dis-1)];
                cout<<ans<<endl;
            }
            else
            {
                ans=sz[raise(u,dis)]-sz[raise(u,dis-1)];
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}