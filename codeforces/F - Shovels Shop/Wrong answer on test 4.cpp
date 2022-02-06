/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 21:48                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 31400 KB                             
*  problem: https://codeforces.com/contest/1154/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],qm[N+2],mx[N+2],k;
int dp[2002][2003];
vector<pair<int,int> >of;
int dfs(int i,int j)
{
  if(j>k)return 0;
  if(i>=of.size())return 1e9;
  if(dp[i][j]!=-1)return dp[i][j];
  int now=1e9;
  now=min(now,aa[j]+dfs(i,j+1));
  now=min(now,dfs(i+1,j));
   if(i<of.size())
  {
    int rm=k-j+1;
    if(of[i].first<=rm)
    {
      now=min(now,qm[j+of[i].first-of[i].second-1]-qm[j-1]+dfs(i,j+of[i].first));
    }
  }
  return dp[i][j]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++)bb[i]=aa[i];
  for(int i=1;i<=k;i++)
    aa[i]=bb[k-i+1];
   for(int i=1;i<=k;i++)
    qm[i]=qm[i-1]+aa[i];
   for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;mx[u]=max(mx[u],v);
  }
  for(int i=1;i<=k;i++)
    if(mx[i])of.push_back({i,mx[i]});
  memset(dp,-1,sizeof(dp));
  cout<<min(qm[k],dfs(0,1))<<endl;
  return 0;
}