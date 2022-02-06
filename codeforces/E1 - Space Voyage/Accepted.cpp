/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2019 19:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/177/problem/E1
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const int N=1e6;
long sut[N+2],cit[N+2],n,c;
long days(long x)
{
  long day=0;
  for(int i=1;i<=n;i++)
  {
    long am=sut[i]*x;
    day+=(am/cit[i])+1;
  }
  return day;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>c;
  for(int i=1;i<=n;i++)
    cin>>sut[i]>>cit[i];
  long lo=1,hi=3e9,md,lt=-1,rt=-1;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    long day=days(md);
    if(day>=c)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    long day=days(md);
    if(day==c)
    {
      lt=md;break;
    }
  }
  lo=1,hi=3e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    long day=days(md);
    if(day>c)hi=md;
    else lo=md;
  }
  for(md=hi;md>=lo;md--)
  {
    long day=days(md);
    if(day==c)
    {
      rt=md;break;
    }
  }
  if(lt==3e9||hi==3e9)cout<<-1<<endl,exit(0);
  if(lt==-1||rt==-1)cout<<0<<endl,exit(0);
  cout<<rt-lt+1<<endl;
  return 0;
}