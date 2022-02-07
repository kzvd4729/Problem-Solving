/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-27 22:23:58                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10709
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
int f=0;
struct point
{
  double x,y;
};
struct equation
{
  double a,b,c;
};
point sub(point a,point b)
{
  a.x-=b.x;a.y-=b.y;
  return a;
}
point add(point a,point b)
{
  a.x+=b.x;a.y+=b.y;
  return a;
}
double dist(point a)
{
  return sqrt(a.x*a.x+a.y*a.y);
}
equation make_equation(point p1,point p2)
{
  equation eq;//ax+by=c;
  eq.a=p1.y-p2.y;eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  return eq;
}
equation perpendicular(equation eq,point p)
{
  equation rt;rt.a=eq.b;rt.b=-eq.a;
  rt.c=rt.a*p.x+rt.b*p.y;return rt;
}
point solve(equation e1,equation e2)
{
  point ret;
  double det=e1.a*e2.b-e1.b*e2.a;
  if(fabs(det)<=eps)
  {
    f=1;return {0,0};
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
double _search(point a,point b,point c)
{
  double ds=dist(sub(c,b));point cc=sub(c,b);
  double lo=0,hi=ds,md1,md2,ret;int lop=1000;
  while(lop--)
  {
    md1=(lo+lo+hi)/3.0,md2=(lo+hi+hi)/3.0;
    double r1=md1/ds,r2=md2/ds;
    point p1={cc.x*r1,cc.y*r1};
    point p2={cc.x*r2,cc.y*r2};
    p1=add(p1,b);p2=add(p2,b);

    double d1=dist(sub(a,p1));
    double d2=dist(sub(a,p2));

    if(d1<d2)hi=md2,ret=d1;
    else lo=md1,ret=d2;
  }
  return ret;
}
double eqtopoint(equation e,point p)
{
  equation ee=perpendicular(e,p);
  point pp=solve(e,ee);
  return dist(sub(pp,p));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(true)
  {
    point a,b;cin>>a.x>>a.y>>b.x>>b.y;
    string s1;cin>>s1;
    point c,d;cin>>c.x>>c.y>>d.x>>d.y;
    string s2;cin>>s2;
    if(s1=="END")break;
    double ans=1e8;f=0;
    equation e1=make_equation(a,b);
    equation e2=make_equation(c,d);

    point p=solve(e1,e2);
    cout<<setprecision(5)<<fixed;

    if(s1=="L"&&s2=="L")
    {
      if(!f)ans=0;
      else ans=eqtopoint(e1,c);
    }
    else if(s1=="L"&&s2=="LS")
    {
      if(!f&&in_rec(p,c,d))
        ans=0;
      else 
        ans=min(eqtopoint(e1,c),eqtopoint(e1,d));
    }
    else if(s1=="LS"&&s2=="L")
    {
      if(!f&&in_rec(p,a,b))
        ans=0;
      ans=min(eqtopoint(e2,a),eqtopoint(e2,b));
    }
    else
    {
      if(!f&&in_rec(p,a,b)&&in_rec(p,c,d))
        ans=0;
      else
      {
        ans=min(ans,_search(c,a,b));
        ans=min(ans,_search(d,a,b));
        ans=min(ans,_search(a,c,d));
        ans=min(ans,_search(b,c,d));
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}