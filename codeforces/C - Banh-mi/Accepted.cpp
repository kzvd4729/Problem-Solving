/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2018 22:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1062/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int qm[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  string s;cin>>s;
  for(int i=1;i<=n;i++)
  {
    qm[i]=qm[i-1];
    if(s[i-1]=='1')qm[i]++;
  }
  while(q--)
  {
    long ans=0;
    int lt,rt;cin>>lt>>rt;
    int on=qm[rt]-qm[lt-1];
    int zr=rt-lt+1-on;
     //cout<<on<<" "<<zr<<endl;
     ans=bigmod(2LL,on,mod);
    ans=(ans-1)%mod;
     long tw=bigmod(2LL,zr,mod);
    tw=(tw-1)%mod;
     //long ml=bigmod(2LL,on,mod);
    //ml=(ml-1)%mod;
     ans=ans+(ans*tw)%mod;
     cout<<ans%mod<<"\n";
   }
  return 0;
}