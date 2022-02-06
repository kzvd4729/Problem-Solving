/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/01/2021 21:35                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17 (64)                          
*  run_time: 311 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1523/problem/E
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
const int N=1e6,inf=1e9,mod=1000000007;
 int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
 int ml[N+2];
int mul(int l,int r)
{
  if(l<=0)return 0;
  return (1LL*ml[r]*big(ml[l-1],mod-2))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    ml[0]=1;
  for(int i=1;i<=N;i++)ml[i]=(1LL*ml[i-1]*i)%mod;
   int t;cin>>t;
  while(t--)
  {
     int n,k;cin>>n>>k;
    int cnt=1,now=n;
    int pr=1,ans=0;
     int tt,gd=1;
    for(int l=1;l<=n;l++)
    {
      int ret=1;
      if(now<=0)ret=0;
      else
      {
        ret=mul(now-cnt+1,now);
        now-=(k-1);cnt++;
      }
      tt=(1LL*gd*(n-l+1));gd=ret;
       //cout<<tt<<" "<<gd<<endl;
       int now=(1LL*(tt-gd)*big(tt,mod-2))%mod;
      now=(1LL*now*l)%mod;
      now=(1LL*now*pr)%mod;
       ans=(ans+now)%mod;
       now=(1LL*gd*big(tt,mod-2))%mod;
      pr=(1LL*pr*now)%mod;
       //cout<<tt<<" "<<gd<<endl;
       //tt=(1LL*gd*(n-l));gd=ret;
    }
    cout<<(ans+mod)%mod<<'\n';
  }
  return 0;
}