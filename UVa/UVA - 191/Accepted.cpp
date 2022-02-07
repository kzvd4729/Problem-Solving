/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-27 23:38:28                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-191
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
int g;
struct point
{
  double x,y;
};
struct equation
{
  double a,b,c;
};
equation make_equation(point p1,point p2)
{
  equation eq;//ax+by=c;
  eq.a=p1.y-p2.y;eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  return eq;
}
point solve(equation e1,equation e2)
{
  point ret;
  double det=e1.a*e2.b-e1.b*e2.a;
  if(fabs(det)<=eps)
  {
    g=1;return {0,0};
  }
  double dx=e1.c*e2.b-e1.b*e2.c;
  double dy=e1.a*e2.c-e1.c*e2.a;
  ret.x=dx/det;ret.y=dy/det;
  return ret;
}
bool in_rec(point a,point b,point c)
{
  double mnx=min(b.x,c.x),mxx=max(b.x,c.x);
  double mny=min(b.y,c.y),mxy=max(b.y,c.y);
  return a.x>=mnx&&a.x<=mxx&&a.y>=mny&&a.y<=mxy;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    point p,p1,p2,a,b,c,d;
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>a.x>>a.y>>b.x>>b.y;
    c={a.x,b.y},d={b.x,a.y};int f=0;
    f|=in_rec(p1,a,b)|in_rec(p2,a,b);
    f|=in_rec(p1,a,c)|in_rec(p2,a,d);
    f|=in_rec(p1,b,c)|in_rec(p2,b,d);
    f|=in_rec(p1,c,d);

    equation pp=make_equation(p1,p2);

    g=0;p=solve(pp,make_equation(a,b));
    if(!g&&in_rec(p,p1,p2)&&in_rec(p,a,b))f=1;

    g=0;p=solve(pp,make_equation(a,c));
    if(!g&&in_rec(p,p1,p2)&&in_rec(p,a,c))f=1;

    g=0;p=solve(pp,make_equation(a,d));
    if(!g&&in_rec(p,p1,p2)&&in_rec(p,a,d))f=1;

    g=0;p=solve(pp,make_equation(b,c));
    if(!g&&in_rec(p,p1,p2)&&in_rec(p,b,c))f=1;

    g=0;p=solve(pp,make_equation(b,d));
    if(!g&&in_rec(p,p1,p2)&&in_rec(p,b,d))f=1;

    g=0;p=solve(pp,make_equation(c,d));
    if(!g&&in_rec(p,p1,p2)&&in_rec(p,c,d))f=1;

    if(f)cout<<"T"<<endl;
    else cout<<"F"<<endl;
  }
  return 0;
}