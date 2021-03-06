/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 14:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 888 ms                                          memory_used: 22400 KB                             
*  problem: https://codeforces.com/contest/1184/problem/E1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int par[N+2],n;
vector<pair<int,pair<int,int> > >v;
pair<int,pair<int,int> >p;
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
bool ok(int md)
{
  for(int i=1;i<=n;i++)par[i]=i;
  for(auto x:v)
  {
    if(md<=x.first)
    {
      int r1=_find(p.second.first);
      int r2=_find(p.second.second);
      if(r1==r2)return false;
      else return true;
    }
    int r1=_find(x.second.first);
    int r2=_find(x.second.second);
    if(r1==r2)continue;
    par[r1]=r2;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  cin>>p.second.first>>p.second.second>>p.first;
  for(int i=2;i<=m;i++)
  {
    int a,b,c;cin>>a>>b>>c;
    v.push_back({c,{a,b}});
  }
  v.push_back({1e9,p.second});
  sort(v.begin(),v.end());
  int lo=0,hi=1e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(ok(md))cout<<md<<endl,exit(0);
  return 0;
}