/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-22 14:49:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-920
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
/*************** Basic Geometry **************/
const double pi=acos(-1.0);
struct point
{
  double x,y;
};
struct Equation
{
  double a,b,c;
};
double DegreetoRadian(double x)
{
  return x*(pi/180.0);
}
double RadiantoDegree(double x)
{
  return x*(180.0/pi);
}
double Vector_Angle_With_X_Axis(point a)
{
  double ang=atan2(a.y,a.x);
  ang=RadiantoDegree(ang);
  if(ang<0)ang+=360.0;
  return ang;
}
double Angle_Between_Two_Vector_Unsigned(point a,point b)
{
  double a1=Vector_Angle_With_X_Axis(a);
  double b1=Vector_Angle_With_X_Axis(b);
  double mn=fabs(a1-b1);mn=min(mn,a1+360-b1);
  mn=min(mn,b1+360-a1);return mn;
}
double Triangle_Area_From_Three_Sides(double a,double b,double c)
{
  double s=(a+b+c)/2.0;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
double Circum_Radius_of_Triangle_From_Three_Sides(double a,double b,double c)
{
  double dn=Triangle_Area_From_Three_Sides(a,b,c);
  return (a*b*c)/(4*dn);
}
double Incircle_Radius_of_Triangle_From_Three_Sides(double a,double b,double c)
{
  double ar=Triangle_Area_From_Three_Sides(a,b,c);
  return (2*ar)/(a+b+c);
}
Equation Make_Equation(point p1,point p2)
{
  Equation eq;//ax+by=c;
  eq.a=p1.y-p2.y;eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  return eq;
}
Equation Perpendicular_On(Equation eq,point p)
{
  Equation rt;rt.a=eq.b;rt.b=-eq.a;
  rt.c=rt.a*p.x+rt.b*p.y;return rt;
}
point Intersection(Equation e1,Equation e2)
{
  point ret;//Special care for det=0
  double det=e1.a*e2.b-e1.b*e2.a;
  double dx=e1.c*e2.b-e1.b*e2.c;
  double dy=e1.a*e2.c-e1.c*e2.a;
  ret.x=dx/det;ret.y=dy/det;
  return ret;
}
double Dist(point p1,point p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int Orientation(point p1,point p2,point p3)
{
  double val=(p2.y-p1.y)*(p3.x-p2.x)-(p2.x-p1.x)*(p3.y-p2.y); 
  if(fabs(val)<=0.000000000001)return 0;
  return (val>0)?1:-1;//clock or counterclock
}
Equation Parallel_With(Equation eq,point p)
{
  Equation rt;rt.a=eq.a;rt.b=eq.b;
  rt.c=rt.a*p.x+rt.b*p.y;return rt;
}
////////////////////////////////////////////////////
bool cmp(point A,point B)
{
  return A.x<B.x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    point pp[N+2];int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>pp[i].x>>pp[i].y;
    sort(pp+1,pp+n+1,cmp);

    Equation eq=Make_Equation({0,0},{1,0});
    double ans=0;
    for(int i=n-1;i>=1;i--)
    {
      Equation qe=Make_Equation(pp[i],pp[i+1]);
      point p=Intersection(eq,qe);
      if(pp[i].y>p.y)
      {
        ans+=Dist(p,pp[i]);
        eq=Parallel_With(eq,pp[i]);
      }
    }
    cout<<setprecision(2)<<fixed<<ans<<endl;
  }
  return 0;
}