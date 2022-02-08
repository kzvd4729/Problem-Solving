/****************************************************************************************
*  @author: kzvd4729                                         created: 12-04-2019 18:52:26                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.92 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/problems/PRIME1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************* Miller Test ***********/
unsigned long Bigmod(unsigned long b,unsigned long p,unsigned long mod)
{
  unsigned long ret=1;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
bool Miller_Test(unsigned long n,int k=10)
{
  if(n<2)return false;if(n<4)return true;
  if(n%2==0)return false;
  unsigned long s=n-1;while(s%2==0)s/=2;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while(k--)
  {
    unsigned long a=2+rng()%(n-2),tmp=s;
    unsigned long md=Bigmod(a,tmp,n);
    if(md==1||md==n-1)continue;
    while(tmp!=n-1&&md!=1&&md!=n-1)
      md=(md*md)%n,tmp*=2;
    if(md!=n-1)return false;
  }
  return true;
}
///////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  for(int tc=1;tc<=t;tc++)
  {
    if(tc>1)cout<<"\n";
    int lt,rt;cin>>lt>>rt;
    for(int i=lt;i<=rt;i++)
      if(Miller_Test(i))cout<<i<<"\n";
  }
  return 0;
}