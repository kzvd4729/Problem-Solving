/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-05 21:04:30                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2242
****************************************************************************************/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const double pi=acos(-1.0);
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
  eq.a=p1.y-p2.y;
  eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p1.x*p2.y;
  return eq;
}
equation perpendicular(equation eq,point p)
{
  equation ret;
  ret.a=eq.b;
  ret.b=-eq.a;
  ret.c=(ret.a*p.x+ret.b*p.y);
  return ret;
}
double dis(point a,point b)
{
  double t1=(a.x-b.x)*(a.x-b.x);
  double t2=(a.y-b.y)*(a.y-b.y);
  return sqrt(t1+t2);
}
point intersection(equation e1,equation e2)
{
  double det=e1.a*e2.b-e1.b*e2.a;
  double dx=e1.c*e2.b-e1.b*e2.c;
  double dy=e1.a*e2.c-e1.c*e2.a;

//  cout<<e1.a<<" "<<e1.b<<" "<<e1.c<<endl;
//  cout<<e2.a<<" "<<e2.b<<" "<<e2.c<<endl;

  //cout<<det<<" "<<dx<<" "<<dy<<endl;

  return {dx/det,dy/det};
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  point p1,p2,p3;
  while(cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y)
  {
    equation e1=make_equation(p1,p2);
    point m1={(p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0};
    equation e2=make_equation(p2,p3);
    point m2={(p2.x+p3.x)/2.0,(p2.y+p3.y)/2.0};

    point cc=intersection(perpendicular(e1,m1),perpendicular(e2,m2));

    cout<<setprecision(2)<<fixed<<2*pi*dis(cc,p1)<<endl;

  }
  return 0;
}