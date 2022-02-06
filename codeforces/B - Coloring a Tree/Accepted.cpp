/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2017 21:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/902/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long color[100005],ans,n,x;
vector<long>adj[100005];
void dfs(long node,long par,long cl)
{
    if(cl!=color[node])ans++;
    for(auto x:adj[node])
    {
        if(x==par)continue;
        dfs(x,node,color[node]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=2;i<=n;i++)
    {
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    for(long i=1;i<=n;i++)cin>>color[i];
     dfs(1,-1,0);
    cout<<ans<<endl;
     return 0;
}