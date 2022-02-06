/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/20/2018 19:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/106/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,m,c0,d0,aa[N+2],bb[N+2],cc[N+2],dd[N+2],rm[N+2];
int dp[N+1][11][101];
int dfs(int nn,int mm,int rr)
{
  if(nn<0)return -1e9;
  if(mm>m)return (int(nn/c0))*d0;
  if(dp[nn][mm][rr]!=-1)return dp[nn][mm][rr];
  int now=0;
  now=max(now,dfs(nn,mm+1,0));
  if(rr<rm[mm])
    now=max(now,dd[mm]+dfs(nn-cc[mm],mm,rr+1));
  return dp[nn][mm][rr]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>c0>>d0;
  for(int i=1;i<=m;i++)
  {
    cin>>aa[i]>>bb[i]>>cc[i]>>dd[i];
    rm[i]=aa[i]/bb[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(n,1,0)<<endl;
  return 0;
}