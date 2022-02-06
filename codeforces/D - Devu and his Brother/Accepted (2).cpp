/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 31600 KB                             
*  problem: https://codeforces.com/contest/439/problem/D
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
#define long long long
using namespace std;
const long N=1e6;
long a[N+2],b[N+2],aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)cin>>a[i];
  for(long i=1;i<=m;i++)cin>>b[i];
   sort(a+1,a+n+1);sort(b+1,b+m+1);
  for(long i=1;i<=n;i++)aa[i]=aa[i-1]+a[i];
  for(long i=m;i>=1;i--)bb[i]=bb[i+1]+b[i];
   long ans=1e18;
  for(long i=1;i<=n;i++)
  {
    long now=1LL*a[i]*i-aa[i];
    long id=upper_bound(b+1,b+m+1,a[i])-b;
     now+=bb[id]-1LL*a[i]*(m-id+1);
    ans=min(ans,now);
  }
  for(long i=1;i<=m;i++)
  {
    long now=bb[i]-1LL*b[i]*(m-i+1);
    long id=upper_bound(a+1,a+n+1,b[i])-a;id--;
     now+=1LL*b[i]*id-aa[id];
    ans=min(ans,now);
  }
  cout<<ans<<endl;
   return 0;
}