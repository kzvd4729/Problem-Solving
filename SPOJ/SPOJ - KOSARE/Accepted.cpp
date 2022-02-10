/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-22 17:59:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 420                                        memory_used (MB): 8.2                             
*  problem: https://vjudge.net/problem/SPOJ-KOSARE
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6,mod=1e9+7;
int dp[(1<<20)+2],p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;int msk=0;
    while(x--)
    {
      int a;cin>>a;msk|=(1<<(a-1));
    }
    dp[msk]++;
  }
  for(int i=0;i<m;i++)
  {
    for(int msk=0;msk<(1<<m);msk++)
    {
      if(msk&(1<<i))
        dp[msk]+=dp[msk^(1<<i)];
    }
  }
  p[0]=1;
  for(int i=1;i<=n;i++)p[i]=(p[i-1]+p[i-1])%mod;

  int ans=0;
  for(int i=0;i<(1<<m);i++)
  {
    int s=m-__builtin_popcount(i);
    if(s%2==0)ans+=(p[dp[i]]-1);
    else ans-=(p[dp[i]]-1);

    ans%=mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}