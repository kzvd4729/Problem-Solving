/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/13/2017 14:49                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 13700 KB                             
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
    for(int x:adj[n])
    {
        if(x==p)continue;
        find_level(x,n,h+1);
        sz[n]+=sz[x];
    }
}
void sparse(void)
{
    for(int i=1;i<=n;i++)
    {
        sp[i][0]=par[i];
    }
    for(int j=1;j<=19;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(sp[i][j-1]!=-1)sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v)
{
    for(int i=19;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[v])
        {
            u=sp[u][i];
        }
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--)
    {
        if(sp[u][i]!=-1&&sp[u][i]!=sp[v][i])
        {
            u=sp[u][i];
            v=sp[v][i];
        }
    }
    return par[u];
}
int find_mid(int u,int dis)
{
    for(int i=19;i>=0;i--)
    {
        if((1<<i)<=dis&&sp[u][i]!=-1)
        {
            u=sp[u][i];
            dis-=(1<<i);
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
            int k=find_mid(u,dis);
            int ans;
            if(u==v)
            {
                cout<<n<<endl;
            }
            else if(lev[u]==lev[v])
            {
                ans=N-sz[find_mid(u,dis-1)]-sz[find_mid(v,dis-1)];
                cout<<ans<<endl;
            }
            else
            {
                ans=sz[find_mid(u,dis)]-sz[find_mid(u,dis-1)];
                cout<<ans<<endl;
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<sz[i]<<" ";
    }
    cout<<endl;*/
     return 0;
}