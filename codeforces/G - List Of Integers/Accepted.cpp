/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/29/2020 00:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 779 ms                                          memory_used: 42800 KB                             
*  problem: https://codeforces.com/contest/920/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int vis[N+2];
vector<int>pr[N+2];
void factorise()
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vis[j]=1;pr[j].push_back(i);
    }
  }
}
int ret(vector<pair<int,int> >&v,int r)
{
  int ret=r;
  for(auto x:v)
    ret+=(r/x.first)*x.second;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  factorise();
   int t;cin>>t;
  while(t--)
  {
    int l,p,k;cin>>l>>p>>k;
    int n=pr[p].size();vector<pair<int,int> >v;
    for(int i=1;i<(1<<n);i++)
    {
      int ml=1,sgn=1;
      for(int j=0;j<n;j++)
      {
        if(i&(1<<j))ml*=pr[p][j],sgn*=-1;
      }
      v.push_back({ml,sgn});
    }
    int mn=ret(v,l);
    int lo=l,hi=1e9,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ret(v,md)-mn>=k)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
      if(ret(v,md)-mn==k)break;
    cout<<md<<"\n";
  }
  return 0;
}