/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-23 22:30:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10991
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double eps=1e-9;
const double pi=acos(-1.0);
int sgn(const double &d)
{
  if(fabs(d)<=eps)return 0;
  return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(double _x=0,double _y=0){x=_x,y=_y;}
  void input(){cin>>x>>y;}
  void output(){cout<<x<<" -- "<<y<<endl;}
  point operator+(const point &p)const{return {x+p.x,y+p.y};}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  double operator*(const point &p){return x*p.x+y*p.y;}
  double operator^(const point &p)const{return x*p.y-y*p.x;}
  double valSquerd()const{return x*x+y*y;}
  double distSqure(const point &p)const{return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);}
  point unitPerpendicularDown()const{double d=sqrt(valSquerd());return {-y/d,x/d};}
};
struct line
{
  point p,v;double ang;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;ang=atan2(v.y,v.x);}
  bool operator<(const line &l)const{return ang<l.ang;}
  point intersection(line l)
  {
    point u=p-l.p;
    double t=(l.v^u)/(v^l.v);
    return p+v*t;
  }
};
struct segment
{
  point s,e;
  segment(){}
  segment(point _s,point _e){s=_s,e=_e;}
  void input(){s.input(),e.input();}
  void output(){s.output();cout<<" ---> ";e.output();}
  int segmentIntersect(segment sg,point &r)
  {
    double s1,s2,s3,s4;
    int d1=sgn(s1=(e-s)^(sg.s-s));
    int d2=sgn(s2=(e-s)^(sg.e-s));
    int d3=sgn(s3=(sg.e-sg.s)^(s-sg.s));
    int d4=sgn(s4=(sg.e-sg.s)^(e-sg.s));
    if((d1^d2)==-2&&(d3^d4)==-2)
    {
      r.x=sg.s.x*s2-sg.e.x*s1/(s2-s1);
      r.y=sg.s.y*s2-sg.e.y*s1/(s2-s1);
      return 1;
    }
    else if(d1==0&&sgn((s-sg.s)*(e-sg.s))<=0){r=sg.s;return 2;}
    else if(d2==0&&sgn((s-sg.e)*(e-sg.e))<=0){r=sg.e;return 2;}
    else if(d3==0&&sgn((sg.s-s)*(sg.e-s))<=0){r=s;return 2;}
    else if(d4==0&&sgn((sg.s-e)*(sg.e-e))<=0){r=e;return 2;}
    return 0;
  }
};
double triangleArea(double &a,double &b,double &c)
{
  double s=(a+b+c)/2.0;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
double circleArea(double r){return pi*r*r;}
double radToDeg(double &r){return r*180.0/pi;}
double degToRad(double &d){return d*pi/180.0;}
double atan2_360(point &p)
{
  double ang=atan2(p.y,p.x);
  if(ang<0)ang+=pi+pi;
  return radToDeg(ang);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    double a,b,c;cin>>a>>b>>c;
    cout<<setprecision(6)<<fixed;
    double ab=a+b,bc=b+c,ca=c+a;

    double area=triangleArea(ab,bc,ca);
    double A=acos((ab*ab+ca*ca-bc*bc)/(2.0*ab*ca));
    double B=acos((ab*ab+bc*bc-ca*ca)/(2.0*ab*bc));
    double C=acos((bc*bc+ca*ca-ab*ab)/(2.0*bc*ca));

    area-=circleArea(a)*(A/(2.0*pi));
    area-=circleArea(b)*(B/(2.0*pi));
    area-=circleArea(c)*(C/(2.0*pi));

    cout<<area<<endl;
  }
  return 0;
}