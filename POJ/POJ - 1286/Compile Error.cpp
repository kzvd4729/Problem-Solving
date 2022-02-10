/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-20 20:20:55                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1286
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#define long long long
using namespace std;
const int N=1e6;
long big(long b,long p)
{
  long r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b);
    b=(1LL*b*b);p/=2;
  }
  return r;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;
  while(cin>>n)
  {
    if(n==-1)break;
    long sm=0;k=3;
    for(long i=1;i<=n;i++)
      sm=(sm+big(k,__gcd(n,i)));
    if(n%2==0)
    {
      sm+=(n/2)*big(k,n/2);
      sm+=(n/2)*big(k,n/2+1);
      cout<<sm/(n*2)<<endl;
    }
    else
    {
      sm+=n*big(k,n/2+1);
      cout<<sm/(n*2)<<endl;
    }
  }
  return 0;
}