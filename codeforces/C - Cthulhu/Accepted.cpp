/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2018 16:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 21600 KB                             
*  problem: https://codeforces.com/contest/104/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[1000006],u,v,n,m;
vector<long>adj[1000000];
void dfs(long node)
{
    vis[node]=1;
    for(auto x:adj[node])
    {
        if(vis[x])continue;
        dfs(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    if(m!=n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(long i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(long i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<"NO"<<endl;
        return 0;
        }
    }
    cout<<"FHTAGN!"<<endl;
    return 0;
}