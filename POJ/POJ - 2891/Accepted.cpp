/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-04 23:40:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 47                                         memory_used (MB): 0.7                             
*  problem: https://vjudge.net/problem/POJ-2891
****************************************************************************************/
#include<iostream>
#include<vector>
#define long long long
using namespace std;
const long N=1e6;

/*
solves the congruence equations
  x=r1(mod m1)
  x=r2(mod m3)
  x=r3(mod m3)
  x=r3(mod m2)
finds minimum x
rr is the remainder array
mm is the modulo array
*/
long exgcd(long a,long b,long &x,long &y)
{
  if(!b){x=1,y=0;return a;}
  long x1,y1;
  long g=exgcd(b,a%b,x1,y1);
  x=y1;
  y=x1-((long)(a/b))*y1;
  return g;
}
long crt(vector<long>rr,vector<long>mm)
{
  long r=rr[0],m=mm[0],f=0,n=rr.size();
  for(long i=1;i<n;i++)
  {
    long x,y,g;g=exgcd(m,mm[i],x,y);
    if((rr[i]-r)%g!=0)return -1;
    long md=(m/g)*mm[i];
    r=r+((((rr[i]-r)/g*x)%mm[i])*m)%md;
    r=(r+md)%md;m=md;
  }
  return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,t,tc=0;//cin>>t;
  while(cin>>n)
  {
    //long n;cin>>n;
    vector<long>rr(n),mm(n);
    for(long i=0;i<n;i++)
      cin>>mm[i]>>rr[i];
    cout<<crt(rr,mm)<<"\n";
  }
  return 0;
}