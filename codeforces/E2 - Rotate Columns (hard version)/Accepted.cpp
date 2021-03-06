/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2019 21:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1716 ms                                         memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/1209/problem/E2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int mt[12][N+2],n,m,rl[12][12],sum[12][(1<<12)+2];
int dp[12][(1<<12)+2];
vector<int>sub[(1<<12)+2];
void rotate(int j)
{
  int tmp=rl[0][j];
  for(int i=0;i<n-1;i++)
    rl[i][j]=rl[i+1][j];
  rl[n-1][j]=tmp;
}
void choose(void)
{
  vector<pair<int,int> >v;
  for(int j=0;j<m;j++)
  {
    int mx=0;
    for(int i=0;i<n;i++)
      mx=max(mx,mt[i][j]);
    v.push_back({mx,j});
  }
  sort(v.begin(),v.end());reverse(v.begin(),v.end());
  memset(rl,0,sizeof(rl));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      rl[i][j]=mt[i][v[j].second];
  memset(sum,0,sizeof(sum));
  for(int j=0;j<n;j++)
  {
    for(int c=0;c<n;c++)
    {
      rotate(j);
      for(int msk=0;msk<(1<<n);msk++)
      {
        int sm=0;
        for(int i=0;i<n;i++)
          if(msk&(1<<i))sm+=rl[i][j];
        sum[j][msk]=max(sum[j][msk],sm);
      }
    }
  }
}
int dfs(int j,int msk)
{
  if(j==n)return 0;
  int rv=(1<<n)-1-msk;
  if(dp[j][msk]!=-1)return dp[j][msk];
  int now=0;
  for(auto x:sub[rv])
    now=max(now,sum[j][x]+dfs(j+1,msk|x));
  return dp[j][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<(1<<12);i++)
    for(int j=0;j<(1<<12);j++)
      if((i&j)==j)sub[i].push_back(j);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;memset(mt,0,sizeof(mt));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>mt[i][j];
    if(m<n)m=n;choose();
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,0)<<"\n";
  }
  return 0;
}