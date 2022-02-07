/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-14 22:04:52                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10004
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>adj[202];
long n,e,u,v,vis[202],f;
void dfs(long node,long par)
{
    vis[node]=1;
    for(long i=0;i<adj[node].size();i++)
    {
        long z=adj[node][i];
        if(z==par)continue;
        if(vis[z])
        {
            f=1;
            continue;
        }
        dfs(z,node);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        if(n==0)break;
        for(long i=0;i<=200;i++)adj[i].clear();
        memset(vis,0,sizeof(vis));
        f=0;

        cin>>e;
        while(e--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);

        if(f==1)cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;
    }

    return 0;
}