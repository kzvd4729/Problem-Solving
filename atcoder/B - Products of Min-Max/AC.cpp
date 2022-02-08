/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-09 20:09:05                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 45 ms                                           memory_used: 5172 KB                              
*  problem: https://atcoder.jp/contests/arc116/tasks/arc116_b
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
 int a[N+2],dp[N+2];
 int sm[N+2];
int cnt[100+2][100+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1);
  //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  dp[1]=a[1];
  for(int i=2;i<=n;i++)
  {
    dp[i]=(dp[i-1]*2LL-a[i-1]+a[i])%mod;
  }
   int ans=0;
  for(int i=1;i<=n;i++)
    ans=(ans+1LL*dp[i]*a[i])%mod;
   cout<<(ans+mod)%mod<<endl;
        return 0;
}