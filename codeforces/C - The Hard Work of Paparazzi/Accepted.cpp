/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2020 21:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/1427/problem/C
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
const int N=1e6,inf=1e9;
int t[N+2],a[N+2],b[N+2],dp[N+2],mx[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int r,n;cin>>r>>n;
  for(int i=1;i<=n;i++)cin>>t[i]>>a[i]>>b[i];
  a[0]=1,b[0]=1;
   for(int i=1;i<=n;i++)dp[i]=-inf;
  for(int i=1;i<=n;i++)
  {
    int l=max(0,i-1010);
    if(l)dp[i]=mx[l-1]+1;
     for(int j=l;j<i;j++)
    {
      if(abs(a[i]-a[j])+abs(b[i]-b[j])<=t[i]-t[j])
        dp[i]=max(dp[i],dp[j]+1);
    }
    mx[i]=max(mx[i-1],dp[i]);
  }
  cout<<mx[n]<<endl;
  return 0;
}