/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-04 23:08:46                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2891
****************************************************************************************/
#include<iostream>
#include<vector>
#define long long long
using namespace std;
const int N=1e6;

int exgcd(int a,int b,int &x,int &y)
{
  if(!b){x=1,y=0;return a;}
  int x1,y1;
  int g=exgcd(b,a%b,x1,y1);
  x=y1;
  y=x1-((int)(a/b))*y1;
  return g;
}
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
int crt(vector<int>rr,vector<int>mm)
{
  int r=rr[0],m=mm[0],f=0,n=rr.size();
  for(int i=1;i<n;i++)
  {
    int x,y,g;g=exgcd(m,mm[i],x,y);
    if((rr[i]-r)%g!=0)return -1;
    int md=(m/g)*mm[i];
    r=r+((((rr[i]-r)/g*x)%mm[i])*m)%md;
    r=(r+md)%md;m=md;
  }
  return r;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    vector<int>rr(n),mm(n);
    for(int i=0;i<n;i++)
      cin>>mm[i]>>rr[i];
    cout<<crt(rr,mm)<<"\n";
  }
  return 0;
}