/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/06/2018 22:32                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/742/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int n,vis[N+2],ans=1e8;
vector<int>adj[N+2];
void dfs(int node,int lev)
{
  if(vis[lev])
  {
    int cycle=lev-vis[node];
    if(cycle==1)return ;
    if(cycle%2==0)cycle/=2;
    ans=min(ans,cycle);
    return ;
  }
  vis[node]=lev;
  for(auto xx:adj[node])
    dfs(xx,lev+1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    adj[i].push_back(x);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    dfs(i,1);
  }
  if(ans>1e4)ans=-1;
  cout<<ans<<endl;
  return 0;
}