/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/18/2020 22:44                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 18000 KB                             
*  problem: https://codeforces.com/contest/1368/problem/D
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
const int N=2e5;
int aa[N+2],dp[20+2][N+2],cnt[20+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=n;i>=1;i--)
  {
    for(int j=0;j<20;j++)
      dp[j][i]=dp[j][i+1]+(bool)(aa[i]&(1<<j));
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    int now=0;
    for(int j=0;j<20;j++)
    {
      if((aa[i]&(1<<j))==0&&cnt[j])cnt[j]--,aa[i]|=(1<<j);
    }
    for(int j=0;j<20;j++)
    {
      if((aa[i]&(1<<j))==0)continue;
      if(dp[j][i+1]+cnt[j]==n-i)now|=(1<<j);
      else cnt[j]++;
    }
    ans+=1LL*now*now;
  }
  cout<<ans<<endl;
  return 0;
}