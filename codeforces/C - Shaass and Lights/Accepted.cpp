/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/23/2018 23:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/294/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long mod=1e9+7;
int aa[N+2],ncr[N+2][N+2],pw[N+2];
long _ncr(void)
{
  for(int i=0;i<=N;i++)ncr[i][0]=1;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
    }
  }
  pw[0]=1;
  for(int i=1;i<=N;i++)
    pw[i]=(pw[i-1]+pw[i-1])%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  _ncr();
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>aa[i];
  sort(aa+1,aa+m+1);
  long ans=1;
  for(int i=2;i<=m;i++)
  {
    ans=(ans*ncr[aa[i]-i][aa[i]-aa[i-1]-1])%mod;
    if(aa[i]-aa[i-1]>2)ans=(ans*pw[aa[i]-aa[i-1]-2])%mod;
  }
  ans=(ans*ncr[n-m][n-aa[m]])%mod;
  cout<<ans<<endl;
  return 0;
}