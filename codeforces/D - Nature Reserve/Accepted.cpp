/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2018 22:47                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 405 ms                                          memory_used: 800 KB                               
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
struct equation
{
  double a,b,c;
};
equation make_equation(pair<double,double>x,pair<double,double>y)
{
  equation ret;
  ret.a=x.second-y.second;
  ret.b=y.first-x.first;
  ret.c=x.second*y.first-y.second*x.first;
  return ret;
}
pair<double,double>solve(equation on,equation tw,pair<double,double>md)
{
  double det=on.a*tw.b-tw.a*on.b;
  if(fabs(det)<=0.00000001)return md;
  double dx=on.c*tw.b-tw.c*on.b;
  double dy=on.a*tw.c-tw.a*on.c;
  return {fabs(dx/det),fabs(dy/det)};
}
double binary(double x)
{
  double ans=0;
  for(int i=1;i<=n;i++)
  {
    equation on=make_equation({x,0},pp[i]);
    pair<double,double>md={(x+pp[i].first)/2.0,pp[i].second/2.0};
    equation tw;tw.a=-on.b;tw.b=-on.a;
    tw.c=tw.a*md.first-tw.b*md.second;
    //cout<<md.first<<" "<<md.second<<endl;
    equation th=make_equation({x,0},{x,10});
     pair<double,double>cen=solve(tw,th,md);
     //cout<<cen.first<<" "<<cen.second<<endl;
     ans=max(ans,dis(cen.first,cen.second,pp[i].first,pp[i].second));
  }
  return ans;
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
  double lo=0,hi=mx,md1,md2;int ter=100;
  while(ter--)
  {
    md1=(lo+lo+hi)/3.0;md2=(lo+hi+hi)/3.0;
    if(binary(md1)<binary(md2))hi=md2;
    else lo=md1;
  }
  cout<<setprecision(10)<<fixed<<binary(md1)<<endl;
  return 0;
}