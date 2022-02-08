/****************************************************************************************
*  @author: kzvd4729                                         created: 12-04-2019 18:49:13                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.34 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/problems/PRIME1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/******************* Fermet Test ****************/
long Bigmod(long b,long p,long mod)
{
  long ret=1;
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
  for(int tc=1;tc<=t;tc++)
  {
    if(tc>1)cout<<"\n";
    int lt,rt;cin>>lt>>rt;
    for(int i=lt;i<=rt;i++)
      if(Fermet(i,10))cout<<i<<"\n";
  }
  return 0;
}