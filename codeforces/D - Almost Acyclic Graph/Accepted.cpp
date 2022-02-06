/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2018 14:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/915/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,u,v,vis[502],tim[100005],ttm,root;
vector<long>adj[502];
vector<pair<long,long> >cycle;
pair<long,long>p;
bool cy=false,fn=false;
void dfs(long node)
{
    if(vis[node]==2||cy)
        return ;
    if(vis[node]==1)
    {
        cy=true;
        root=node;
        return ;
    }
    vis[node]=1;
    for(auto x:adj[node])
        dfs(x);
    if(!cy)
        vis[node]=2;
}
void dfs2(long node)
{
    if(vis[node]==2||cy)
        return ;
    if(vis[node]==1)
    {
        cy=true;
        root=node;
        return ;
    }
    vis[node]=1;
    for(auto x:adj[node])
    {
        pair<long,long>tmp={node,x};
        if(p==tmp)continue;
        dfs2(x);
    }
    if(!cy)
        vis[node]=2;
}
void print(long node)
{
    if(node==root&&cycle.size())
    {
        fn=true;
        return ;
    }
    for(auto x:adj[node])
    {
        if(fn)
            return ;
        if(vis[x]!=1)
            continue;
        cycle.push_back({node,x});
        if(fn)
            return ;
        print(x);
    }
}
bool check()
{
    memset(vis,0,sizeof(vis));
    cy=false;
    for(int i=1; i<=n; i++)if(!vis[i])dfs2(i);
    if(cy==false)return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(long i=1; i<=n; i++)
    {
        if(vis[i])
            continue;
        dfs(i);
        if(root!=0)
            break;
    }
    print(root);
    if(!cycle.size())
    {
        cout<<"YES"<<endl;
        return 0;
    }
//    cout<<root<<endl;
//    for(long i=1;i<=n;i++)cout<<vis[i];
//    cout<<endl;
//    cout<<cycle.size()<<endl;
//    for(auto x:cycle)cout<<x.first<<" "<<x.second<<endl;
//    cout<<endl;
    for(auto x:cycle)
    {
        p=x;
        if(check())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
     return 0;
}