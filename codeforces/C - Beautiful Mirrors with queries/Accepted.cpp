/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2020 21:16                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1200 ms                                         memory_used: 41400 KB                             
*  problem: https://codeforces.com/contest/1264/problem/C
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
const long N=1e6,mod=998244353;
long big(long b,long p)
{
  long r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
long a[N+2],ml[N+2],sm[N+2];
long cal(long i,long j)
{
  long up=(1LL*(sm[j-1]-sm[i-1])*big(ml[i-1],mod-2))%mod+1;
  long dw=(1LL*ml[j]*big(ml[i-1],mod-2))%mod;
  return (1LL*up*big(dw,mod-2))%mod;
}
long bit[N+2];
void upd(long x,long vl){vl%=mod;for( ;x<=N;x+=x&-x)bit[x]=(bit[x]+vl)%mod;}
void upd(long l,long r,long vl){upd(l,vl);upd(r+1,-vl);}
long get(long x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)ret=(ret+bit[x])%mod;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,q;cin>>n>>q;ml[0]=1;
  for(long i=1;i<=n;i++)
  {
    cin>>a[i];
    a[i]=(1LL*a[i]*big(100,mod-2))%mod;
    ml[i]=(1LL*ml[i-1]*a[i])%mod;
    sm[i]=(sm[i-1]+ml[i])%mod;
  }
  set<long>st;st.insert(1);st.insert(n+1);
  upd(1,1,cal(1,n));
  while(q--)
  {
    long x;cin>>x;
    if(st.find(x)==st.end())
    {
      auto it=st.upper_bound(x);
      long ex=get(*it);
       long now=get(x);upd(x,x,-now);
      long her=cal(x,*it-1)+ex;
      upd(x,x,her);
       it--;upd(1,*it,-get(*it));
      upd(1,*it,cal(*it,x-1)+her);
       st.insert(x);
    }
    else
    {
      auto it=st.upper_bound(x);
      long rt=*it;long ex=get(rt);
       it--;it--;
      upd(1,*it,-get(*it));
      long now=cal(*it,rt-1)+ex;
      upd(1,*it,now);
       long dl=get(x);upd(x,x,-dl);
      st.erase(x);
    }
    cout<<(get(1)+mod)%mod<<'\n';
  }
  return 0;
}