/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/05/2020 16:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/446/problem/A
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
int a[N+2],f[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  int ans=2;
  b[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(a[i]>a[i-1])b[i]=b[i-1]+1;
    else b[i]=1;
  }
  f[n]=1;
  for(int i=n-1;i>=1;i--)
  {
    if(a[i]<a[i+1])f[i]=f[i+1]+1;
    else f[i]=1;
    ans=max(ans,f[i]+1);
  }
  for(int i=1;i<=n;i++)
  {
    if(a[i-1]+1<a[i+1])ans=max(ans,b[i-1]+f[i+1]+1);
  }
  ans=min(ans,n);cout<<ans<<endl;
  return 0;
}