/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2021 19:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1475/problem/G
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
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=998244353;
 int cnt[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
        memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      cnt[x]++;
    }
     int mx=0;
    memset(dp,0,sizeof dp);
    for(int i=N;i>=1;i--)
    {
      for(int j=i+i;j<=N;j+=i)
        dp[i]=max(dp[i],dp[j]);
       dp[i]+=cnt[i];
      mx=max(mx,dp[i]);
    }
    cout<<n-mx<<endl;
  }
  return 0;
}