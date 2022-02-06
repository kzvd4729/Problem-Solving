/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2021 21:38                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1499/problem/C
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
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     long mn1=a[1],mn2=inf,od=1,ev=0,odsm=a[1],evsm=0;
    long ans=1LL*inf*inf;
    for(int i=2;i<=n;i++)
    {
      if(i%2)mn1=min(mn1,1LL*a[i]),od++,odsm+=a[i];
      else mn2=min(mn2,1LL*a[i]),ev++,evsm+=a[i];
       long now=odsm-mn1+mn1*(n-od+1)+evsm-mn2+mn2*(n-ev+1);
      ans=min(ans,now);
    }
    cout<<ans<<'\n';
   }
  return 0;
}