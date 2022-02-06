/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/23/2020 13:17                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 15400 KB                             
*  problem: https://codeforces.com/contest/1082/problem/E
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
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a[N+2],pr[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,c;cin>>n>>c;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)pr[i]=pr[i-1]+(a[i]==c);
  int ans=pr[n],cnt=0;
  for(int i=n;i>=1;i--)
  {
    if(a[i]==c)cnt++;
    else
    {
      dp[a[i]]=max(dp[a[i]],cnt);
      dp[a[i]]++;ans=max(ans,dp[a[i]]+pr[i-1]);
    }
  }
  cout<<ans<<endl;
  return 0;
}