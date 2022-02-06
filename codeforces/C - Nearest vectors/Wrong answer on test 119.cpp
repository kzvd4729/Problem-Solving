/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2019 19:33                        
*  solution_verdict: Wrong answer on test 119                language: GNU C++14                               
*  run_time: 795 ms                                          memory_used: 23700 KB                             
*  problem: https://codeforces.com/contest/598/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  double x,y;
};
 /*************** Basic Geometry **************/
const double pi=acos(-1.0);
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
   double mn=fabs(a1-b1);
  mn=min(mn,a1+360-b1);
  mn=min(mn,b1+360-a1);
  return mn;
  /*double ab=a.x*b.y+b.x*a.y;
  double aa=sqrt(a.x*a.x+a.y*a.y);
  double bb=sqrt(b.x*b.x+b.y*b.y);
  return acos(ab/(aa*bb));*/
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
////////////////////////////////////////////////////
struct data
{
  double x,y;
  int id;
}aa[N+2];
bool cmp(data A,data B)
{
  return Vector_Angle_With_X_Axis({A.x,A.y})<Vector_Angle_With_X_Axis({B.x,B.y});
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i].x>>aa[i].y,aa[i].id=i;
  sort(aa+1,aa+n+1,cmp);
   /*for(int i=1;i<=n;i++)
    cout<<aa[i].x<<" "<<aa[i].y<<endl;*/
   double mx=1e9;
   int a,b;
  for(int i=2;i<=n;i++)
  {
    point c={aa[i].x,aa[i].y};
    point d={aa[i-1].x,aa[i-1].y};
    //cout<<Angle_Between_Two_Vector_Unsigned(c,d)<<endl;
    if(Angle_Between_Two_Vector_Unsigned(c,d)<mx)
    {
      mx=Angle_Between_Two_Vector_Unsigned(c,d);
      a=aa[i].id;b=aa[i-1].id;
    }
  }
  point c={aa[1].x,aa[1].y};
  point d={aa[n].x,aa[n].y};
  if(Angle_Between_Two_Vector_Unsigned(c,d)<mx)
  {
    mx=Angle_Between_Two_Vector_Unsigned(c,d);
    a=aa[1].id;b=aa[n].id;
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}