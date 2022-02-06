/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2017 10:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/802/problem/J
****************************************************************************************/
/*
4
0 1 4
0 2 2
2 3 3
*/
#include<bits/stdc++.h>
using namespace std;
int n,x,y,c,u,v,mark[110],ans;
vector<int>adj[110],cost[110];
void dfs(int p,int cc)
{
    mark[p]=1;
    for(int i=0; i<adj[p].size(); i++)
    {
        if(mark[adj[p][i]]==0)
        {
            dfs(adj[p][i],cc+cost[p][i]);
        }
    }
    if(cc>ans)ans=cc;
}
int main()
{
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cin>>u>>v>>c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    dfs(0,0);
    cout<<ans<<endl;
     return 0;
}