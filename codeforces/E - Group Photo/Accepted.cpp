/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2021 00:16                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 233 ms                                          memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/1517/problem/E
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
const int N=1e6,inf=1e9,mod=998244353;
 int a[N+2];long tt,sm[2][N+2];
int ck(long x)
{
  return x<tt-x;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;tt=0;
    for(int i=1;i<=n;i++)cin>>a[i],tt+=a[i];
     //all suffix
    long ans=0,now=0;
    for(int i=0;i<n;i++)
    {
      now+=a[i];
      ans+=ck(tt-now);
    }
    //cout<<ans<<endl;
     //all prefix
    now=0;
    for(int i=1;i<n;i++)
    {
      now+=a[i];
      ans+=ck(now);
    }
    //cout<<ans-2<<endl;
      for(int i=1;i<=n;i++)
    {
      sm[0][i]=sm[0][i-1];
      sm[1][i]=sm[1][i-1];
       sm[i%2][i]+=a[i];
    }
     now=0;
    for(int i=1;i<=n-2;i++)
    {
      now+=a[i];
      now+=a[n];
      ans+=ck(now);
       now-=a[n];
        int lo=i+2,hi=n-1,md;
       while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(ck(now+sm[i%2][md]-sm[i%2][i]))lo=md;
        else hi=md;
      }
      for(md=hi;md>=lo;md--)
      {
        if(ck(now+sm[i%2][md]-sm[i%2][i]))break;
      }
      ans+=(md-i)/2;
         lo=i+2,hi=n-2,md;
       while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(ck(now+sm[i%2][md]-sm[i%2][i]+a[n]))lo=md;
        else hi=md;
      }
      for(md=hi;md>=lo;md--)
      {
        if(ck(now+sm[i%2][md]-sm[i%2][i]+a[n]))break;
      }
      ans+=(md-i)/2;
    }
      now=0;
    for(int i=2;i<=n-2;i++)
    {
      now+=a[i];
      now+=a[n];
      ans+=ck(now);
       now-=a[n];
        int lo=i+2,hi=n-1,md;
       while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(ck(now+sm[i%2][md]-sm[i%2][i]))lo=md;
        else hi=md;
      }
      for(md=hi;md>=lo;md--)
      {
        if(ck(now+sm[i%2][md]-sm[i%2][i]))break;
      }
      ans+=(md-i)/2;
         lo=i+2,hi=n-2,md;
       while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(ck(now+sm[i%2][md]-sm[i%2][i]+a[n]))lo=md;
        else hi=md;
      }
      for(md=hi;md>=lo;md--)
      {
        if(ck(now+sm[i%2][md]-sm[i%2][i]+a[n]))break;
      }
      ans+=(md-i)/2;
    }
     //cout<<ans<<endl;
     now=0;
    for(int i=2;i<n;i++)
    {
      now+=a[i];
      ans+=ck(now);
    }
    //cout<<ans<<endl;
    ans=(ans+1)%mod;
    cout<<ans<<endl;
  }
    return 0;
}