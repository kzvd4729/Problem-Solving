/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 19:16                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 24100 KB                             
*  problem: https://codeforces.com/contest/868/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
 int fr[N+2],aa[N+2];
long dp[20+2][N+2];
void dfs(int i,int lo,int hi,int lt,int rt)
{
  //cout<<i<<" "<<lo<<" "<<hi<<" "<<lt<<" "<<rt<<endl;
  if(lo>hi)return ;
  int j=(lo+hi)>>1;long &mn=dp[i][j],op;
  vector<long>v;long ls=0;
  for(int k=j;k>=lt;k--)
  {
    ls+=fr[aa[k]];
    fr[aa[k]]++;v.push_back(ls);
  }
  for(int k=j;k>=lt;k--)fr[aa[k]]--;
   for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    long now=v.back()+dp[i-1][k-1];v.pop_back();
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=0;i<=k;i++)
    for(int j=1;j<=n;j++)dp[i][j]=1e15;
   for(int i=1;i<=k;i++)dfs(i,1,n,1,n);
  cout<<dp[k][n]<<endl;
   return 0;
}