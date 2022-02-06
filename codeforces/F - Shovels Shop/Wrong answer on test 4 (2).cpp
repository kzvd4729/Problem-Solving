/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 22:03                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 170 ms                                          memory_used: 62900 KB                             
*  problem: https://codeforces.com/contest/1154/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long inf=1e14;
long aa[N+2],bb[N+2],qm[N+2],mx[N+2],k;
long dp[2004][2004];
vector<pair<long,long> >of;
long dfs(long i,long j)
{
  if(j>k)return 0;if(i>=of.size())return inf;
  if(dp[i][j]!=-1)return dp[i][j];
  long now=inf;
  now=min(now,aa[j]+dfs(i,j+1));
  now=min(now,dfs(i+1,j));
   if(i<of.size())
  {
    long rm=k-j+1;
    if(of[i].first<=rm)
    {
      now=min(now,qm[j+of[i].first-1]-qm[j+of[i].second-1]+dfs(i,j+of[i].first));
    }
  }
  return dp[i][j]=now;
}
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
  return p1.first-p1.second>p2.first-p2.second;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m>>k;
  for(long i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
   for(long i=1;i<=k;i++)
    qm[i]=qm[i-1]+aa[i];
   for(long i=1;i<=m;i++)
  {
    long u,v;cin>>u>>v;mx[u]=max(mx[u],v);
  }
  for(long i=1;i<=k;i++)
    if(mx[i])of.push_back({i,mx[i]});
  if(of.size()==0)cout<<qm[k]<<endl,exit(0);
  sort(of.begin(),of.end(),cmp);
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,1)<<endl;
  return 0;
}