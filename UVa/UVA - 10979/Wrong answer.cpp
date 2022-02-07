/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-29 00:09:28                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10979
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20;
const double eps=1e-4;
int f;
struct point
{
  double x,y;
}aa[N+2],bb[N+2];
struct equation
{
  double a,b,c;
}eq[N+2];
equation make_equation(point p1,point p2)
{
  equation eq;//ax+by=c;
  eq.a=p1.y-p2.y;eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  return eq;
}
point solve(equation e1,equation e2)
{
  point ret;//Special care for det=0
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
  return a.x+eps>=mnx&&a.x-eps<=mxx&&a.y+eps>=mny&&a.y-eps<=mxy;
}
bool equal(point a,point b)
{
  return fabs(a.x-b.x)<=eps&&fabs(a.y-b.y)<=eps;
}
double dist(point p1,point p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double Area(double dX0, double dY0, double dX1, double dY1, double dX2, double dY2)
{
    double dArea = ((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0))/2.0;
    return (dArea > 0.0) ? dArea : -dArea;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i].x>>aa[i].y>>bb[i].x>>bb[i].y;
      eq[i]=make_equation(aa[i],bb[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      if(equal(aa[i],bb[i]))continue;
      for(int j=i+1;j<=n;j++)
      {
        if(equal(aa[j],bb[j]))continue;
        for(int k=j+1;k<=n;k++)
        {
          if(equal(aa[k],bb[k]))continue;
          vector<point>v;
          f=0;point p1=solve(eq[i],eq[j]);
          if(f)continue;
          if(in_rec(p1,aa[i],bb[i])&&in_rec(p1,aa[j],bb[j]))
            v.push_back(p1);

          f=0;point p2=solve(eq[i],eq[k]);
          if(f)continue;
          if(in_rec(p2,aa[i],bb[i])&&in_rec(p2,aa[k],bb[k]))
            v.push_back(p2);

          f=0;point p3=solve(eq[j],eq[k]);
          if(f)continue;
          if(in_rec(p3,aa[j],bb[j])&&in_rec(p3,aa[k],bb[k]))
            v.push_back(p3);
          if(v.size()!=3)continue;
          double ar=Area(v[0].x,v[0].y,v[1].x,v[1].y,v[2].x,v[2].y);
          if(fabs(ar)>0.0001)ans++;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}