/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-20 01:18:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 176                                        memory_used (MB): 7.2                             
*  problem: https://vjudge.net/problem/LightOJ-1094
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 30003
using namespace std;
long t,tc,n,mx,id,node,u,v,w;
vector<pair<long,long> >adj[N];
long dfs(long n,long p,long c)
{
    for(int i=0;i<adj[n].size();i++)
    {
        if(adj[n][i].first==p)continue;
        long cc=c+adj[n][i].second;
        if(cc>mx)
        {
            mx=cc;
            node=adj[n][i].first;
        }
        dfs(adj[n][i].first,n,cc);
    }
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=0;i<n;i++)
        {
            adj[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        mx=0;
        dfs(0,-1,0);
        mx=0;
        dfs(node,-1,0);
        cout<<"Case "<<++tc<<": "<<mx<<endl;
    }
    return 0;
}