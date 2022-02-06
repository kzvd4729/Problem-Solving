/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/03/2018 21:49                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 639 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1003/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,q,cnt;
long arr[N+2],qm[N+2],x;
int _find(long x)
{
  int lo=1,hi=n;
  while(hi-lo>2)
  {
    int md=(lo+hi)/2;
    if(arr[md]>x)hi=md;
    else lo=md;
  }
  for(int md=hi;md>=lo;md--)
    if(arr[md]<=x)return md;
  return 0;
}
void balance(int lm)
{
  int lo=1,hi=lm,md;
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
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
   for(int i=1;i<=n;i++)
    qm[i]=qm[i-1]+arr[i];
   while(q--)
  {
    cin>>x;
    cnt=0;
    while(x)
    {
      int id=_find(x);
      if(id==0)break;
      balance(id);
    }
    if(x==0)cout<<cnt<<endl;
    else cout<<-1<<endl;
  }
  return 0;
}