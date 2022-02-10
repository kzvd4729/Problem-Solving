/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-22 20:38:36                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1808                                       memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-subset
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
const int N=1e6;
int aa[N+2],bb[N+2],a,b,fr[N+2],dp[N+2];
void cal()
{
  for(int i=1;i<=a;i++)fr[aa[i]]++;
  for(int i=1;i<=b;i++)fr[bb[i]]--;
  a=0,b=0;

  for(int i=0;i<(1<<16);i++)dp[i]=fr[i];
  for(int i=0;i<16;i++)
  {
    for(int msk=0;msk<(1<<16);msk++)
    {
      if(msk&(1<<i))
        dp[msk]+=dp[msk^(1<<i)];
    }
  }
}
const int magic=1000;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;int x;cin>>s>>x;
    if(s=="cnt")
    {
      int ans=dp[x];
      for(int i=1;i<=a;i++)if((x&aa[i])==aa[i])ans++;
      for(int i=1;i<=b;i++)if((x&bb[i])==bb[i])ans--;
      cout<<ans<<"\n";
    }
    else if(s=="add")aa[++a]=x;
    else bb[++b]=x;
    if(a+b>=magic)cal();
  }
  return 0;
}