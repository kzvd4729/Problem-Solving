/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2020 17:53                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 12500 KB                             
*  problem: https://codeforces.com/contest/543/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<20),inf=1e9;
int c[20+2][20+2],cst[N+2],dp[N+2],mxm[N+2],sm[20+2];
string s[20+2];
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
  cout<<dp[(1<<n)-1]<<endl;
  return 0;
}