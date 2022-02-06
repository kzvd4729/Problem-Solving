/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2019 19:37                        
*  solution_verdict: Memory limit exceeded on test 22        language: GNU C++14                               
*  run_time: 1793 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/622/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int ex[N+2],lnk[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >vv[N+2],v;
void dfs(int node,int par)
{
  int f=0,nx;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);f++;nx=x;
  }
  if(!f)
  {
    vv[node].push_back({0,0});
    lnk[node]=node;ex[node]=0;
  }
  else if(f==1&&par!=1)
  {
    lnk[node]=lnk[nx];
    ex[node]=ex[nx]+1;
  }
  else
  {
    for(auto x:adj[node])
    {
      if(x==par)continue;
      for(auto z:vv[lnk[x]])
        vv[node].push_back({z.first+ex[x],z.second+ex[x]});
    }
    sort(vv[node].begin(),vv[node].end());
    v.clear();int lo=-1,hi=-1;
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
    vv[node]=v;lnk[node]=node;ex[node]=0;
  }
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