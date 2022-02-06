/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/24/2019 01:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 545 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101972/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
/*************** Basic Geometry **************/
const double pi=acos(-1.0);
const double eps=1e-9;
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
Equation Parallel_With(Equation eq,point p)
{
  Equation rt;rt.a=eq.a;rt.b=eq.b;
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
inline double Dist(point p1,point p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int Orientation(point p1,point p2,point p3)
{
  double val=(p2.y-p1.y)*(p3.x-p2.x)-(p2.x-p1.x)*(p3.y-p2.y);
  if(fabs(val)<=eps)return 0;
  return (val>0)?1:-1;//clock or counterclock
}
bool In_Rectangle(point a,point b,point c)
{
  double mnx=min(b.x,c.x),mxx=max(b.x,c.x);
  double mny=min(b.y,c.y),mxy=max(b.y,c.y);
  return a.x>=mnx&&a.x<=mxx&&a.y>=mny&&a.y<=mxy;
}
bool Segment_Intersect(point p1,point q1,point p2,point q2)
{
  int o1=Orientation(p1,q1,p2);
  int o2=Orientation(p1,q1,q2);
  int o3=Orientation(p2,q2,p1);
  int o4=Orientation(p2,q2,q1);
  if(o1!=o2&&o3!=o4)
    return true;
  if(o1==0&&In_Rectangle(p2,p1,q1))return true;
  if(o2==0&&In_Rectangle(q2,p1,q1))return true;
  if(o3==0&&In_Rectangle(p1,p2,q2))return true;
  if(o4==0&&In_Rectangle(q1,p2,q2))return true;
  return false;
}
////////////////////////////////////////////////////
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t;//cin>>t;
  scanf("%d",&t);
  point ogr1,ogr2,o={0,0},pp;
  double ans,a,b,c,x;
  while(t--)
  {
    //cin>>a>>b>>c>>x;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&x);
    point rv={0,c},gr={a,-b};
    double lo=0,hi=a,md1,md2,d1,d2;int lop=50;
    while(lop--)
    {
      md1=(lo+lo+hi)/3.0;md2=(lo+hi+hi)/3.0;
      ogr1={md1,c};ogr2={md2,c};
      d1=Dist(o,ogr1)+Dist(ogr1,gr);
      d2=Dist(o,ogr2)+Dist(ogr2,gr);
      if(d1<d2)hi=md2;
      else lo=md1;
      if(md2-md1<=eps)break;
    }
    ans=d1;
    double ds=Dist(gr,o);
    pp.x=gr.x+(x/100.0)*(o.x-gr.x);
    pp.y=gr.y+(x/100.0)*(o.y-gr.y);
     lo=0,hi=pp.x,md1,md2,d1,d2;lop=50;
    while(lop--)
    {
      md1=(lo+lo+hi)/3.0;md2=(lo+hi+hi)/3.0;
      ogr1={md1,c};ogr2={md2,c};
      d1=Dist(o,ogr1)+Dist(ogr1,pp);
      d2=Dist(o,ogr2)+Dist(ogr2,pp);
      if(d1<d2)hi=md2;
      else lo=md1;
      if(md2-md1<=eps)break;
    }
    ans+=Dist(gr,pp);
    ans+=d1;
     //cout<<setprecision(9)<<fixed<<ans<<"\n";
    printf("%0.9lf\n",ans);
  }
  return 0;
}