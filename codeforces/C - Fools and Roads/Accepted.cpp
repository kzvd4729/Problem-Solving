/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/13/2017 22:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 25400 KB                             
*  problem: https://codeforces.com/contest/191/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
int lev[100005],par[100005],sp[100005][20],cnt[100005],ans[100005],n,u,v,q;
map<pair<int,int>,int>mp;
void level(int n,int p,int h)
{
    par[n]=p;
    lev[n]=h;
    for(auto x:adj[n])
    {
        if(x==p)continue;
        level(x,n,h+1);
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
            u=sp[u][i];
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
void dfs(int n,int p)
{
    for(auto x:adj[n])
    {
        if(x==p)continue;
        dfs(x,n);
        cnt[n]+=cnt[x];
        int k=mp[make_pair(min(n,x),max(n,x))];
        ans[k]=cnt[x];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[make_pair(min(u,v),max(u,v))]=i;
     }
    level(1,-1,0);
    sparse();
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        if(lev[u]<lev[v])swap(u,v);
        int lc=lca(u,v);
        cnt[u]++;
        cnt[lc]--;
        cnt[v]++;
        cnt[lc]--;
     }
    dfs(1,-1);
    for(int i=1;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}