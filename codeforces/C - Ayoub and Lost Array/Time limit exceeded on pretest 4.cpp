/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 18:51                        
*  solution_verdict: Time limit exceeded on pretest 4        language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 31400 KB                             
*  problem: https://codeforces.com/contest/1105/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
long n,l,r,a,b,c;
long dp[N+2][4];
long dfs(int st,int md)
{
  if(st>n)
  {
    if(md==0)return 1;
    else return 0;
  }
  if(dp[st][md]!=-1)return dp[st][md];
  long now=0;
  now=(now+a*dfs(st+1,md))%mod;
  now=(now+b*dfs(st+1,(md+1)%3))%mod;
  now=(now+c*dfs(st+1,(md+2)%3))%mod;
   return now;
 }
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    n,l,r;cin>>n>>l>>r;long x,y;
  a=r/3-(l-1)/3;x=r/3;
  if((r%3)>=1)x++;y=(l-1)/3;
  if((l-1)%3>=1)y++;b=x-y;
   x=r/3;if(r%3>=2)x++;
  y=(l-1)/3;if((l-1)%3>=2)y++;
  c=x-y;
  //cout<<a<<" "<<b<<" "<<c<<endl;
   memset(dp,-1,sizeof(dp));
   cout<<dfs(1,0)<<endl;
   return 0;
}