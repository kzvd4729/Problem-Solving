/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-27 18:19:44                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10242
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
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
  equation eq;
  eq.a=p1.y-p2.y;eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  return eq;
}
equation parallel_with(equation eq,point p)
{
  equation rt;rt.a=eq.a;rt.b=eq.b;
  rt.c=rt.a*p.x+rt.b*p.y;return rt;
}
point solve(equation e1,equation e2)
{
  point ret;
  double det=e1.a*e2.b-e1.b*e2.a;
  double dx=e1.c*e2.b-e1.b*e2.c;
  double dy=e1.a*e2.c-e1.c*e2.a;
  ret.x=dx/det;ret.y=dy/det;
  return ret;
}
bool isequal(point a,point b)
{
  if(fabs(a.x-b.x)<=eps&&fabs(a.y-b.y)<=eps)
    return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  point a,b,c,d;
  while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y)
  {
    point p;
    if(isequal(b,c))
    {
      equation e=parallel_with(make_equation(b,d),a);
      point md;md={(a.x+d.x)/2.0,(a.y+d.y)/2.0};
      equation e2=make_equation(b,md);
      p=solve(e,e2);
    }
    else
    {
      equation e=parallel_with(make_equation(a,d),b);
      point md;md={(b.x+d.x)/2.0,(b.y+d.y)/2.0};
      equation e2=make_equation(a,md);
      p=solve(e,e2);
    }
    if(fabs(p.x)<=eps)p.x=fabs(p.x);
    if(fabs(p.y)<=eps)p.y=fabs(p.y);
    cout<<setprecision(3)<<fixed<<p.x<<" "<<p.y<<endl;
  }
  return 0;
}