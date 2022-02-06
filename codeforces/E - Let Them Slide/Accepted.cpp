/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 15:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 872 ms                                          memory_used: 39400 KB                             
*  problem: https://codeforces.com/contest/1208/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int inf=2e9;
vector<int>v[N+2];
long ans[N+2];int tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,w;cin>>n>>w;
  for(int i=0;i<n;i++)
  {
    int x;cin>>x;v[i].resize(x);
    for(int j=0;j<x;j++)cin>>v[i][j];
  }
  for(int i=0;i<w;i++)tmp[i]=-inf;
  deque<pair<int,int> >dq;
  for(int i=0;i<n;i++)
  {
    int x=v[i].size();
    int window=w-x+1;
    dq.push_back({-1,0});
    for(int j=0;j<x;j++)
    {
      if(j-dq.front().first==window)dq.pop_front();
      while(dq.size())
      {
        if(dq.back().second>v[i][j])break;
        dq.pop_back();
      }
      dq.push_back({j,v[i][j]});
      tmp[j]=dq.front().second;
    }
    while(dq.size())dq.pop_front();
     dq.push_back({x,0});
    for(int j=x-1;j>=0;j--)
    {
      if(dq.front().first-j==window)dq.pop_front();
      while(dq.size())
      {
        if(dq.back().second>v[i][j])break;
        dq.pop_back();
      }
      dq.push_back({j,v[i][j]});
      //cout<<i<<" ** "<<w-x+j<<" "<<dq.front().second<<endl;
      tmp[w-x+j]=max(tmp[w-x+j],dq.front().second);
    }
    while(dq.size())dq.pop_front();
    for(int j=0;j<x;j++)
    {
      ans[j]+=tmp[j];ans[j+1]-=tmp[j];
      tmp[j]=-inf;
    }
    for(int j=w-x;j<w;j++)
    {
      if(tmp[j]==-inf)continue;
      ans[j]+=tmp[j];ans[j+1]-=tmp[j];
      tmp[j]=-inf;
    }
    if(w>x+x)
    {
      int mx=0;
      for(auto x:v[i])mx=max(mx,x);
      ans[x]+=mx;ans[w-x]-=mx;
    }
  }
  for(int i=1;i<w;i++)
    ans[i]+=ans[i-1];
  for(int i=0;i<w;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}