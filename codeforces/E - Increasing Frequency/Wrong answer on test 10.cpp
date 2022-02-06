/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/23/2020 13:04                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 15400 KB                             
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
int fr[N+2],mx[N+2],a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,c;cin>>n>>c;
  for(int i=1;i<=n;i++)cin>>a[i];
   int ans=0;
  for(int i=1;i<=n;i++)
  {
    fr[a[i]]++;mx[i]=max(mx[i-1],fr[a[i]]);
  }
  ans=mx[n];int cnt=0;
  for(int i=n;i>=1;i--)
  {
    cnt+=(a[i]==c);
    ans=max(ans,mx[i-1]+cnt);
  }
  memset(fr,0,sizeof fr);
  for(int i=n;i>=1;i--)
  {
    fr[a[i]]++;mx[i]=max(mx[i+1],fr[a[i]]);
  }
  cnt=0;
  for(int i=1;i<=n;i++)
  {
    cnt+=(a[i]==c);
    ans=max(ans,mx[i+1]+cnt);
  }
  cout<<ans<<endl;
  return 0;
}