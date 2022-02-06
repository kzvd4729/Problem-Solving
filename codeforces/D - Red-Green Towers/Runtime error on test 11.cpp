/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/03/2018 19:47                        
*  solution_verdict: Runtime error on test 11                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 250500 KB                            
*  problem: https://codeforces.com/contest/478/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=1e5;
int a,b,hg,dp[N+2][640];
void height(int aa,int bb,int cc)
{
  if(aa<0||bb<0)return ;
  hg=max(hg,cc);
  if(dp[aa][cc])return ;
  if(aa>cc)height(aa-cc-1,bb,cc+1);
  if(bb>cc)height(aa,bb-cc-1,cc+1);
  dp[aa][cc]=1;
}
long dfs(int aa,int bb,int cc)
{
  if(aa<0||bb<0)return 0LL;
  if(cc==hg)return 1LL;
  if(dp[aa][cc])return dp[aa][cc];
  long here=0;
  if(aa>cc)here=(here+dfs(aa-cc-1,bb,cc+1))%mod;
  if(bb>cc)here=(here+dfs(aa,bb-cc-1,cc+1))%mod;
  return dp[aa][cc]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b;
  if(a>b)swap(a,b);
   height(a,b,0);
   memset(dp,0,sizeof(dp));
   cout<<dfs(a,b,0)<<endl;
   return 0;
}