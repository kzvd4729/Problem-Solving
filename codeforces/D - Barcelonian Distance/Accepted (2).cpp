/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2018 02:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1079/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
double a,b,c,a1,a2,b1,b2;
double _findy(double x)
{
  if(b==0)return 1e15;
  return (-a*x-c)/b;
}
double _findx(double y)
{
  if(a==0)return 1e15;
  return (-b*y-c)/a;
}
double dis(pair<double,double>p1,pair<double,double>p2)
{
  return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>c;
  cin>>a1>>b1>>a2>>b2;
   double ans=abs(a1-a2)+abs(b1-b2);
   //if(!a||!b)cout<<ans<<endl,exit(0);
  pair<double,double>p1;
  p1.first=a1;
  p1.second=_findy(p1.first);
   pair<double,double>p2;
  p2.first=a2;
  p2.second=_findy(p2.first);
   ans=min(ans,dis(p1,p2)+abs(a1-p1.first)+abs(b1-p1.second)+abs(a2-p2.first)+abs(b2-p2.second));
   p2.second=b2;
  p2.first=_findx(p2.second);
   ans=min(ans,dis(p1,p2)+abs(a1-p1.first)+abs(b1-p1.second)+abs(a2-p2.first)+abs(b2-p2.second));
   p1.second=b1;
  p1.first=_findx(p1.second);
   p2.first=a2;
  p2.second=_findy(p2.first);
   ans=min(ans,dis(p1,p2)+abs(a1-p1.first)+abs(b1-p1.second)+abs(a2-p2.first)+abs(b2-p2.second));
   p2.second=b2;
  p2.first=_findx(p2.second);
   ans=min(ans,dis(p1,p2)+abs(a1-p1.first)+abs(b1-p1.second)+abs(a2-p2.first)+abs(b2-p2.second));
   cout<<setprecision(10)<<fixed<<ans<<endl;
   return 0;
}