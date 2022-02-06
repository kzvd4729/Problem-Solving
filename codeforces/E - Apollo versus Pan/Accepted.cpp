/****************************************************************************************
*  @author: kzvd4729#                                        created: May/02/2021 14:12                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 639 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1466/problem/E
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
const int N=5e5,inf=1e9,mod=1e9+7;
 long a[N+2],cnt[60+2],bit[60+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     memset(cnt,0,sizeof cnt);
    memset(bit,0,sizeof bit);
     for(int i=1;i<=n;i++)
    {
      for(long l=0;l<=60;l++)
      {
        if(a[i]&(1LL<<l))cnt[l]++;
      }
    }
     for(int i=1;i<=n;i++)
    {
      long tt=0;
      for(long l=0;l<=60;l++)
      {
        if(a[i]&(1LL<<l))
        {
          tt=(tt+((1LL<<l)%mod)*n)%mod;
        }
        else
        {
          tt=(tt+((1LL<<l)%mod)*cnt[l])%mod;
        }
      }
      for(long l=0;l<=60;l++)
      {
        if(a[i]&(1LL<<l))
        {
          bit[l]=(bit[l]+tt)%mod;
        }
      }
    }
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      for(long l=0;l<=60;l++)
      {
        if(a[i]&(1LL<<l))
        {
          ans=(ans+((1LL<<l)%mod)*bit[l])%mod;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}