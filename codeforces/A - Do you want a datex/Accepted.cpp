/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2020 23:58                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 186 ms                                          memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/809/problem/A
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
const long N=1e6,mod=1e9+7;
int p[N+2],a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  p[0]=1;
  for(int i=1;i<=N;i++)p[i]=(p[i-1]+p[i-1])%mod;
   int ans=0;int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)
  {
    ans=(ans+1LL*a[i]*p[i-1])%mod;
    ans=(ans-1LL*a[i]*p[n-i])%mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}