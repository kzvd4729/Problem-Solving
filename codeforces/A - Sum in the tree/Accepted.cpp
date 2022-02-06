/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2019 15:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 9500 KB                              
*  problem: https://codeforces.com/contest/1098/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
vector<int>adj[N+2];
void dfs(int node,int h,int sm)
{
  if(h%2==0)
  {
    if(adj[node].size()==0)
    {
      aa[node]=0;return ;
    }
    int mn=2e9;
    for(auto x:adj[node])
      mn=min(mn,aa[x]);
    if(mn<sm)cout<<-1<<endl,exit(0);
    aa[node]=mn-sm;
  }
  else aa[node]-=sm;
  for(auto x:adj[node])
    dfs(x,h+1,sm+aa[node]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    adj[x].push_back(i);
  }
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  dfs(1,1,0);
  long sm=0;
  for(int i=1;i<=n;i++)
    sm+=aa[i]*1LL;
  cout<<sm<<endl;
  return 0;
}