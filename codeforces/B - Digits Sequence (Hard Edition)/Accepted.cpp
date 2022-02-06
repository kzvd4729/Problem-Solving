/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2019 20:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1177/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dig(long x)
{
  int cnt=0;
  while(x){cnt++;x/=10;}
  return cnt;
}
long cal(long xx)
{
  if(xx<=0)return 0;
  int n=dig(xx);long ret=0;
  for(int i=1;i<=n;i++)
  {
    long lo=1,hi=0,x=i-1;
    while(x--)lo*=10;x=i;
    while(x--)hi=hi*10+9;
    hi=min(hi,xx);
    ret+=(hi-lo+1)*i;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  long lo=1,hi=1e12,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    long x=cal(md);
    if(x>=n)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(cal(md)>=n)break;
  n-=cal(md-1);
  int x=dig(md);x-=n;
  while(x--)md/=10;
  cout<<md%10<<endl;
  return 0;
}