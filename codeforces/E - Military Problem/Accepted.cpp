/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/16/2018 21:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 17400 KB                             
*  problem: https://codeforces.com/contest/1006/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,q,x;
int st[N+2],ed[N+2],tim,arr[N+2];
vector<int>adj[N+2];
void dfs(int node,int par)
{
  ++tim;
  st[node]=tim;
  arr[tim]=node;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
  }
  ed[node]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
  for(int i=2;i<=n;i++)
  {
    cin>>x;
    adj[x].push_back(i);
  }
  dfs(1,-1);
  while(q--)
  {
    int node,k;
    cin>>node>>k;
    if(ed[node]-st[node]+1<k)
    {
      cout<<-1<<"\n";
      continue;
    }
    cout<<arr[st[node]+k-1]<<"\n";
  }
  return 0;
}