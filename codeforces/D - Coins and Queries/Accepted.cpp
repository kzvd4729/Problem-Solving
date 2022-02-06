/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/03/2018 22:12                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1591 ms                                         memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/1003/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,q,cnt;
long arr[N+2],qm[N+2],x,rt;
long _find(long xx,long hi)
{
  long lo=1;
  while(hi-lo>2)
  {
    long md=(lo+hi)/2;
    if(arr[md]>xx)hi=md;
    else lo=md;
  }
  for(long md=hi;md>=lo;md--)
    if(arr[md]<=xx)return md;
  return 0;
}
void balance(long lm)
{
  long lo=1,hi=lm,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(qm[lm]-qm[md-1]>x)lo=md;
    else hi=md;
  }
  for(md=lo;md<=hi;md++)
  {
    if(qm[lm]-qm[md-1]<=x)
    {
      x-=(qm[lm]-qm[md-1]);
      cnt+=lm-md+1;
      rt=md-1;
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
   for(long i=1;i<=n;i++)
    qm[i]=qm[i-1]+arr[i];
   while(q--)
  {
    cin>>x;
    cnt=0;
    rt=n;
    while(x)
    {
      long id=_find(x,rt);
      if(id==0)break;
      balance(id);
    }
    if(x==0)cout<<cnt<<endl;
    else cout<<-1<<endl;
  }
  return 0;
}