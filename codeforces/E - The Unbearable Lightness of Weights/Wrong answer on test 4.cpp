/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2018 02:01                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 23900 KB                             
*  problem: https://codeforces.com/contest/1079/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
const long mod=70000006660000007;
int aa[N+2],fr[N+2],bb[N+2];
long dp[3][101][N+1],ncr[102][102];
long NCR(int n,int r)
{
   if(n==r)return 1;
   if(r==1)return n;
   if(ncr[n][r]!=-1)return ncr[n][r];
   return ncr[n][r]=(NCR(n-1,r)+NCR(n-1,r-1))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(ncr,-1,sizeof(ncr));
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]++;
  }
  for(int i=0;i<=n;i++)dp[i%2][0][0]=1;
  for(int st=1;st<=n;st++)
  {
    for(int tk=1;tk<=n;tk++)
    {
      for(int vl=1;vl<=N;vl++)
      {
        dp[st%2][tk][vl]=dp[(st+1)%2][tk][vl];
        if(vl-aa[st]>=0)
          dp[st%2][tk][vl]+=dp[(st+1)%2][tk-1][vl-aa[st]];
      }
    }
  }
  int ans=0;
  for(int i=1;i<=100;i++)
  {
    for(int j=1;j<=fr[i];j++)
    {
      long xx=dp[n%2][j][i*j];
      long yy=NCR(fr[i],j);
      if(xx==yy)ans=max(ans,j);
    }
  }
  cout<<ans<<endl;
  return 0;
}