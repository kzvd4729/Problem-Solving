/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-15 00:42:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 783                                        memory_used (MB): 4.1                             
*  problem: https://vjudge.net/problem/LightOJ-1298
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
const long mod=1000000007;
long dp[502][502];
bool isPrime(int x)
{
  int sq=sqrt(x+1);
  for(int i=2;i<=sq;i++)
    if(x%i==0)return false;
  return true;
}
vector<int>prime;
long dfs(int pi,int mt)
{
  if(pi<0)return mt?0:1;
  if(dp[pi][mt]!=-1)return dp[pi][mt];
  long now=0,ml=1;
  for(int i=1;i<=mt;i++)
  {
    now=(now+((ml*(prime[pi]-1))%mod)*dfs(pi-1,mt-i))%mod;
    ml=(ml*prime[pi])%mod;
  }
  return dp[pi][mt]=now;
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  for(int i=2;  ;i++)
  {
    if(prime.size()>500)break;
    if(isPrime(i))
      prime.push_back(i);
  }
  memset(dp,-1,sizeof(dp));
  while(t--)
  {
    long ans=0;
    int n,p;cin>>n>>p;
    cout<<"Case "<<++tc<<": "<<dfs(p-1,n)<<"\n";
  }
  return 0;
}