/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2020 20:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1285/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e18;
long ml(long x,long cnt)
{
  long ret=1;
  while(cnt--)ret*=x;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long x;cin>>x;long sq=sqrt(x+2);
   vector<long>v;
  for(long i=2;i<=sq;i++)
  {
    if(x%i==0)
    {
      long cnt=0;
      while(x%i==0){cnt++;x/=i;}
      v.push_back(ml(i,cnt));
    }
  }
  if(x>1)v.push_back(x);
   long n=v.size();
  long aa=1,bb=1,c=inf;
  for(long i=1;i<(1<<n);i++)
  {
    long a=1,b=1;
    for(long j=0;j<n;j++)
    {
      if(i&(1<<j))a*=v[j];
      else b*=v[j];
    }
    if(max(a,b)<c)
    {
      c=max(a,b),aa=a,bb=b;
    }
  }
  cout<<aa<<" "<<bb<<endl;
  return 0;
}