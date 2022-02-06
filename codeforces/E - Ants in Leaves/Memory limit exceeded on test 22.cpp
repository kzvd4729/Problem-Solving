/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2019 19:20                        
*  solution_verdict: Memory limit exceeded on test 22        language: GNU C++14                               
*  run_time: 1263 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/622/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
vector<int>adj[N+2];
vector<pair<int,int> >vv[N+2];
void dfs(int node,int par)
{
  int f=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);f=1;
  }
  if(!f)
    vv[node].push_back({0,0});
  else
  {
    for(auto x:adj[node])
    {
      if(x==par)continue;
      for(auto z:vv[x])
        vv[node].push_back(z);
    }
    sort(vv[node].begin(),vv[node].end());
    vector<pair<int,int> >v;int lo=-1,hi=-1;
    for(auto x:vv[node])
    {
      if(lo==-1)
      {
        lo=x.first+1,hi=x.second+1;
      }
      else
      {
        if(x.first+1<=hi)
          hi+=x.second-x.first+1;
        else
        {
          v.push_back({lo,hi});
          lo=x.first+1,hi=x.second+1;
        }
      }
    }
    if(lo!=-1)v.push_back({lo,hi});
    vv[node]=v;
  }
  /*cout<<node<<" ";
  for(auto x:vv[node])
  {
    cout<<x.first<<" "<<x.second<<" ";
  }
  cout<<endl;*/
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);int ans=0;
  for(auto x:adj[1])
    if(vv[x].size())ans=max(ans,vv[x].back().second+1);
  cout<<ans<<endl;
  return 0;
}