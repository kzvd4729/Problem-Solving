/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2019 20:17                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/622/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int ex[N+2],lnk[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >vv[N+2],u,v;
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
    u.clear();
    if(f==2)
    {
      int a=-1,b=-1;
      for(auto x:adj[node])
      {
        if(x==par)continue;
        if(a==-1)a=lnk[x];
        else b=lnk[x];
      }
      int i=0,j=0;
      while(i<vv[a].size()&&j<vv[b].size())
      {
        if(vv[a][i]<=vv[b][j])
          u.push_back(vv[a][i++]);
        else u.push_back(vv[b][j++]);
      }
      while(i<vv[a].size())
        u.push_back(vv[a][i++]);
      while(j<vv[b].size())
        u.push_back(vv[b][j++]);
    }
    else
    {
      for(auto x:adj[node])
      {
        if(x==par)continue;
        for(auto z:vv[lnk[x]])
          u.push_back({z.first+ex[x],z.second+ex[x]});
      }
      sort(u.begin(),u.end());
    }
    v.clear();int lo=-1,hi=-1;
    for(auto x:u)
    {
      if(lo==-1)
        lo=x.first+1,hi=x.second+1;
      else
      {
        if(x.first+1<=hi+1)
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