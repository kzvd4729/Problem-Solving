/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-27 15:19:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-378
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
  //ax+by=c;
  double a,b,c;
};
equation make_equation(point a,point b)
{
  equation eq;
  eq.a=a.y-b.y;eq.b=b.x-a.x;
  eq.c=a.y*b.x-b.y*a.x;return eq;
}
point solve(equation e1,equation e2)
{
  double det=e1.a*e2.b-e1.b*e2.a;
  if(fabs(det)<=0)
  {
    f=1;return {0,0};
  }
  double dx=e1.c*e2.b-e1.b*e2.c;
  double dy=e1.a*e2.c-e1.c*e2.a;
  return {dx/det,dy/det};
}
double evaluate(equation e,point p)
{
  return e.a*p.x+e.b*p.y-e.c;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;cout<<"INTERSECTING LINES OUTPUT"<<endl;
  while(t--)
  {
    point a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    equation e1=make_equation(a,b);
    equation e2=make_equation(c,d);
    f=0;point p=solve(e1,e2);
    cout<<setprecision(2)<<fixed;
    if(f)
    {
      double x=evaluate(e2,a);
      if(fabs(x)<=eps)cout<<"LINE"<<endl;
      else cout<<"NONE"<<endl;
    }
    else cout<<"POINT"<<" "<<p.x<<" "<<p.y<<endl;
  }
  cout<<"END OF OUTPUT"<<endl;
  return 0;
}