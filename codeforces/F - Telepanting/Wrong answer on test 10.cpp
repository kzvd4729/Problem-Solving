/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2021 14:00                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++17 (64)                          
*  run_time: 124 ms                                          memory_used: 23800 KB                             
*  problem: https://codeforces.com/contest/1552/problem/F
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
 int dp[N+2],x[N+2],y[N+2],s[N+2],qm[N+2];
 int main()              
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>s[i];
   dp[1]=x[1]-y[1];qm[1]=dp[1];
  for(int i=2;i<=n;i++)
  {
    int id=upper_bound(x+1,x+i,y[i])-x;
    dp[i]=(x[i]-y[i]+qm[i-1]-qm[id-1])%mod;
    dp[i]=(dp[i]+mod)%mod;
    qm[i]=(qm[i-1]+dp[i])%mod;
  }
  int ans=x[n]+1;
  for(int i=1;i<=n;i++)
  {
    if(s[i])ans=(ans+dp[i])%mod;
  }
   cout<<ans<<endl;
   return 0;
}