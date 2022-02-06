/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2017 21:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 12900 KB                             
*  problem: https://codeforces.com/contest/862/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long u,v,n,cnt;
vector<long>adj[100005];
void dfs(long node,long p,long h)
{
    if(h%2==0)cnt++;
    for(long i=0;i<adj[node].size();i++)
    {
        long xx=adj[node][i];
        if(xx==p)continue;
        dfs(xx,node,h+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,0);
     cout<<(cnt*(n-cnt))-n+1<<endl;
     return 0;
}