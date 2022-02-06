/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/03/2018 23:45                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 180800 KB                            
*  problem: https://codeforces.com/contest/478/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=2e5;
int a,b,hg;
long dp[3][N+2];
bool vis[N+2][900];
void height(int aa,int bb,int cc)
{
  if(aa<0||bb<0)return ;
  hg=max(hg,cc);
  if(vis[aa][cc])return ;
  if(aa>cc)height(aa-cc-1,bb,cc+1);
  if(bb>cc)height(aa,bb-cc-1,cc+1);
  vis[aa][cc]=1;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b;
  if(a>b)swap(a,b);
   height(a,b,0);
   dp[0][0]=1;
  for(int i=1;i<=hg;i++)
  {
    memset(dp[i%2],0,sizeof(dp[i%2]));
    for(int j=0;j<=a;j++)
    {
      if(j>=i)dp[i%2][j]=(dp[i%2][j]+dp[(i+1)%2][j-i])%mod;
      long tmp=(i*1LL*(i+1))/2;
      if(tmp-j<=b)dp[i%2][j]=(dp[i%2][j]+dp[(i+1)%2][j])%mod;
    }
  }
  long ans=0;
  for(int i=0;i<=a;i++)
    ans=(ans+dp[hg%2][i])%mod;
  cout<<ans<<endl;
  return 0;
}