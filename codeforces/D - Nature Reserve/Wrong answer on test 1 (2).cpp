/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2018 20:41                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1059/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>pp[N+2];
int n;
double dis(double x1,double y1,double x2,double y2)
{
  double xx=(x1-x2)*(x1-x2);
  double yy=(y1-y2)*(y1-y2);
  return sqrt(xx+yy);
}
double binary(double x)
{
  double lo=0,hi=1e14,md;int bin=65;
  while(bin--)
  {
    md=(lo+hi)/2.0;int f=0;
    for(int i=1;i<=n;i++)
    {
      if(dis(x,md,pp[i].first*1.0,pp[i].second*1.0)>md)
      {
        f=1;lo=md;break;
      }
    }
    if(!f)hi=md;
  }
  return md;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;int ng=0,ps=0,mn=0,mx=0;
  for(int i=1;i<=n;i++)
  {
    cin>>pp[i].first>>pp[i].second;
    mn=min(mn,pp[i].first);
    if(pp[i].second<0)ng=1;
    else if(pp[i].second>0)ps=1;
  }
  if(ps&&ng)cout<<-1<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    pp[i].second=abs(pp[i].second);
    pp[i].first-=mn;mx=max(mx,pp[i].first);
  }
  double lo=0,hi=mx,md1,md2;int ter=34;
  while(ter--)
  {
    md1=(lo+lo+hi)/3.0;md2=(lo+hi+hi)/3.0;
    if(binary(md1)<binary(md2))hi=md2;
    else lo=md1;
  }
  cout<<setprecision(10)<<fixed<<binary(md1)<<endl;
  return 0;
}