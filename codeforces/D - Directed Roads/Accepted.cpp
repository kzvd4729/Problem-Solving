/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/06/2018 19:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 170 ms                                          memory_used: 17400 KB                             
*  problem: https://codeforces.com/contest/711/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=2e5;
int n,cycle,vis[N+2],cnt;
long pw[N+2];
vector<int>adj[N+2];
void dfs(int node,int par,int lev)
{
  if(vis[node])
  {
    cycle=max(cycle,lev-vis[node]);
    return ;
  }
  vis[node]=lev;
  cnt++;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    dfs(xx,node,lev+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   pw[0]=1;
  for(int i=1;i<=N;i++)
    pw[i]=(pw[i-1]*2LL)%mod;
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
   long ans=1;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    cycle=2,cnt=0;
    dfs(i,-1,1);
    ans=(ans*(pw[cnt]-pw[cnt-cycle+1]+mod)%mod)%mod;
  }
  cout<<ans<<endl;
  return 0;
}