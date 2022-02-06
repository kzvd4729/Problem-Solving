/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/01/2018 22:38                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/761/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=30;
int dg[N+2];
vector<int>adj[N+2];
pair<int,int>ans[N+2];
map<pair<int,int>,int>mp;
void dfs(int node,int par)
{
  int cnt=0;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    cnt++;dfs(xx,node);
  }
  if(cnt>=3)cout<<"NO"<<endl,exit(0);
}
void print(int node,int par,int r,int c)
{
  ans[node]={r,c};int f=0;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    if(f==0)
    {
      if(!mp[{r+1,c}])
      {
        print(xx,node,r+1,c);
        mp[{r+1,c}]=1;
      }
      else
      {
        print(xx,node,r-1,c);
        mp[{r-1,c}]=1;
      }
      f=1;
    }
    else
    {
      if(!mp[{r,c+1}])
      {
        print(xx,node,r,c+1);
        mp[{r,c+1}]=1;
      }
      else
      {
        print(xx,node,r,c-1);
        mp[{r,c-1}]=1;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    dg[u]++;dg[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int rt=1;
  for(int i=1;i<=n;i++)if(dg[i]<3)rt=i;
  dfs(rt,-1);print(rt,-1,0,0);
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  return 0;
}