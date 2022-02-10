/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-11 10:14:29                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-LCA
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n;
int sp[1003][20],lev[1003];
vector<int>adj[1002];
void dfs(int n,int p,int h)
{
    sp[n][0]=p;
    lev[n]=h;
    for(int i=0;i<adj[n].size();i++)
    {
        if(adj[n][i]!=p)
        {
            dfs(adj[n][i],n,h+1);
        }
    }
}
void sparse(void)
{
    for(int j=1;j<=16;j++)
    {
        for(int i=1;i<=n;i++)
        {
            sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v)
{
    if(lev[u]<lev[v])
    {
        swap(u,v);
    }
    for(int i=16;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[v])
        {
            u=sp[u][i];
        }
    }
    if(u==v)return u;
    for(int i=16;i>=0;i--)
    {
        if(sp[u][i]!=sp[v][i])
        {
            u=sp[u][i];
            v=sp[v][i];
        }
    }
    return sp[u][0];
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=0;
    memset(sp,-1,sizeof(sp));
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            while(x--)
            {
                int u;
                cin>>u;
                adj[i].push_back(u);
                adj[u].push_back(i);
            }
        }
        dfs(1,-1,0);
        sparse();
        int q,u,v;
        for(int i=1;i<=n;i++)
        {
            cout<<lev[i]<<" ";
        }
        cin>>q;
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>u>>v;
            cout<<lca(u,v)<<endl;
        }
    }

    return 0;
}