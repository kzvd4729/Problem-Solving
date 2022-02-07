/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-14 22:19:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10004
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>adj[402];
long n,e,u,v,vis[402],f;
void dfs(long node,long par)
{
    for(long i=0; i<adj[node].size(); i++)
    {
        long z=adj[node][i];
        ///if(z==par)continue;
        if(vis[node]==1)
        {
            if(vis[z]==0)
            {
                vis[z]=2;
                dfs(z,node);
            }
            else if(vis[z]==1)f=1;
        }
        else if(vis[node]==2)
        {
            if(vis[z]==0)
            {
                vis[z]=1;
                dfs(z,node);
            }
            else if(vis[z]==2)f=1;
        }
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
        for(long i=0; i<=400; i++)adj[i].clear();
        memset(vis,0,sizeof(vis));
        f=0;

        cin>>e;
        while(e--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis[0]=1;
        dfs(0,-1);

        if(f==1)cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;

    }
    return 0;
}