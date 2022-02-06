/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2018 23:54                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++17                               
*  run_time: 61 ms                                           memory_used: 12700 KB                             
*  problem: https://codeforces.com/contest/1059/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long inf=2e18;
int n,l,aa[N+2],ans;
long s;
pair<long,long>pp[N+2];
vector<int>adj[N+2];
void dfs(int node)
{
  pp[node]={inf,inf};
  for(auto x:adj[node])
  {
    dfs(x);
    if(pp[x].first<pp[node].first)
      pp[node]=pp[x];
  }
  if(pp[node].first==inf)pp[node]={0,0};
  if(adj[node].size())ans+=adj[node].size()-1;
  pp[node].first+=aa[node];pp[node].second++;
  if(pp[node].first>s||pp[node].second>l)
  {
    ans++;
    pp[node]={aa[node],1};
  }
  if(pp[node].first>s)cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>l>>s;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    adj[x].push_back(i);
  }
  dfs(1);cout<<ans+1<<endl;
  return 0;
}