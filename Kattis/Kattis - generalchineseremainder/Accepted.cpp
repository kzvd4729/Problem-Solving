/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-26 16:20:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-generalchineseremainder
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long mm[N+2],aa[N+2];
long exgcd(long a,long b,long &x,long &y)
{
  if(!b)
  {
    x=1,y=0;return a;
  }
  long x1,y1;
  long g=exgcd(b,a%b,x1,y1);
  x=y1;
  y=x1-((long)(a/b))*y1;
  return g;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t,tc=0;cin>>t;
  while(t--)
  {
    long n;//cin>>n;
    n=2;
    for(long i=1;i<=n;i++)
      cin>>aa[i]>>mm[i];
    long a=aa[1],m=mm[1],f=0;
    for(long i=2;i<=n;i++)
    {
      long x,y,g;g=exgcd(m,mm[i],x,y);
      if((aa[i]-a)%g!=0)
      {
        cout<<"no solution"<<endl;
        f=1;break;
      }
      long md=(m/g)*mm[i];
      a=a+((((aa[i]-a)/g*x)%mm[i])*m)%md;
      a=(a+md)%md;m=md;
    }
    if(!f)cout<<a<<" "<<m<<endl;
  }
  return 0;
}