/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-24 15:08:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-PON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

/******************* Fermet Test ****************/
long Bigmod(__int128 b,long p,__int128 mod)
{
  __int128 ret=1;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
bool Fermet(long n,int k)
{
  if(n<=1||n==4)return false;
  if(n<=3)return true;
  while(k--)
  {
    long a=2+rand()%(n-4);
    if(Bigmod(a,n-1,n)!=1)
      return false;
  }
  return true;
}
/////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    if(Fermet(n,10))
      cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}