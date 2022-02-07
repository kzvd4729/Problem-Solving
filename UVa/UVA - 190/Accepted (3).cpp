/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-27 23:05:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-190
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
int f;
struct point
{
  double x,y;
};
struct equation
{
  double a,b,c;
};
equation make_equation(point a,point b)
{
  equation e;
  e.a=a.y-b.y;e.b=b.x-a.x;
  e.c=a.y*b.x-a.x*b.y;return e;
}
equation perpendicular(equation e,point a)
{
  equation rt;rt.a=e.b;rt.b=-e.a;
  rt.c=rt.a*a.x+rt.b*a.y;return rt;
}
point solve(equation e1,equation e2)
{
  double det=e1.a*e2.b-e1.b*e2.a;
  if(fabs(det)<=eps)
  {
    f=1;
    return {0,0};
  }
  double dx=e1.c*e2.b-e1.b*e2.c;
  double dy=e1.a*e2.c-e1.c*e2.a;
  return {dx/det,dy/det};
}
point _mid(point a,point b)
{
  return {(a.x+b.x)/2.0,(a.y+b.y)/2.0};
}
double dist(point p1,point p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
void print(point center,point a)
{
  cout<<setprecision(3)<<fixed;
  double r1=dist(center,a);
  if(r1<0)center.x*=-1,center.y*=-1;
  cout<<"(x";
  if(center.x>=0)cout<<" - ";
  else cout<<" + ";
  cout<<fabs(center.x);
  cout<<")^2 + (y";
  if(center.y>=0)cout<<" - ";
  else cout<<" + ";
  cout<<fabs(center.y);
  cout<<")^2 = ";
  cout<<fabs(r1);
  cout<<"^2"<<endl;


  double hx=-2*center.x;
  double yk=-2*center.y;
  double cns=center.x*center.x+center.y*center.y-r1*r1;
  cout<<"x^2 + y^2";

  if(hx>=0)cout<<" + ";
  else cout<<" - ";
  cout<<fabs(hx)<<"x";

  if(yk>=0)cout<<" + ";
  else cout<<" - ";
  cout<<fabs(yk)<<"y";

  if(cns>=0)cout<<" + ";
  else cout<<" - ";
  cout<<fabs(cns);
  cout<<" = 0"<<endl<<endl;

}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  point a,b,c;
  while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y)
  {
    equation ab=make_equation(a,b);
    equation bc=make_equation(b,c);

    point pab=_mid(a,b);
    point pbc=_mid(b,c);

    equation prab=perpendicular(ab,pab);
    equation prbc=perpendicular(bc,pbc);
    print(solve(prab,prbc),a);
  }
  return 0;
}