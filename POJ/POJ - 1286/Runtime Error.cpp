/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-20 20:27:28                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1286
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e6;
long long int big(long long int b,long long int p)
{
  long long int r=1;
  for(long long int i=1;i<=p;i++)
    r*=b;
  return r;
}
long long int gcd(long long int a,long long int b)
{
  if(a==0)return b;if(b==0)return a;
  return gcd(b,a%b);
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  long long int n,k;
  while(cin>>n)
  {
    if(n==-1)break;
    long long int sm=0;k=3;
    for(long long int i=1;i<=n;i++)
      sm=(sm+big(k,gcd(n,i)));
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