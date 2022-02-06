/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2020 19:51                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 22200 KB                             
*  problem: https://codeforces.com/contest/543/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<20),inf=1e9;
int c[20+2][20+2],cst[N+2],dp[N+2],mxm[N+2],sm[20+2],rem[N+2];
string s[20+2];
vector<int>trn[20+2];
int dfs(int i,int msk)
{
  if(i<0)return 0;
  if(rem[msk]!=-1)return rem[msk];
  if(msk&(1<<i))return rem[msk]=dfs(i-1,msk);
   int now=1e9;
  for(auto x:trn[i])
    now=min(now,dp[x]+dfs(i-1,msk|x));
  return rem[msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)cin>>c[i][j];
  }
  for(int i=1;i<(1<<n);i++)dp[i]=inf;
   for(int j=0;j<m;j++)
  {
    vector<pair<char,int> >v;
    for(int i=0;i<n;i++)v.push_back({s[i][j],i});
    sort(v.begin(),v.end());
     int msk=(1<<v[0].second),id=0;
    for(int i=1;i<n;i++)
    {
      if(v[i].first==v[i-1].first)msk|=(1<<v[i].second);
      else
      {
        if(__builtin_popcount(msk)>1)sm[++id]=msk;
        msk=(1<<v[i].second);
      }
    }
    if(__builtin_popcount(msk)>1)sm[++id]=msk;
      for(int i=1;i<(1<<n);i++)
    {
      int id=31-__builtin_clz(i);
      cst[i]=cst[i^(1<<id)]+c[id][j];
      mxm[i]=max(mxm[i^(1<<id)],c[id][j]);
    }
    for(int i=1;i<(1<<n);i++)
    {
      int now=0;
      for(int k=1;k<=id;k++)
      {
        int tmp=sm[k]&i;
        now+=min(cst[tmp],cst[sm[k]]-mxm[tmp]);
      }
      dp[i]=min(dp[i],now);
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int msk=1;msk<(1<<n);msk++)
    {
      if(31-__builtin_clz(msk)==i)
        trn[i].push_back(msk);
    }
  }
  memset(rem,-1,sizeof(rem));
  cout<<dfs(n-1,0)<<endl;
  return 0;
}