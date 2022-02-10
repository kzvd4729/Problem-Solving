/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-22 17:47:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 0.7                             
*  problem: https://vjudge.net/problem/POJ-1269
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
  point operator*(const double &d)const{return {x*d,y*d};}
  point operator/(const double &d)const{return {x/d,y/d};}
  double operator*(const point &p)const{return x*p.x+y*p.y;}
  double operator^(const point &p)const{return x*p.y-y*p.x;}
  double valSquerd()const{return x*x+y*y;}
  double distSqure(const point &p)const{return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);}
  point unitPerpendicularDown()const{double d=sqrt(valSquerd());return {-y/d,x/d};}
};
struct line
{
  point p,v;double ang,c;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;ang=atan2(v.y,v.x),c=v^p;}
  bool isParallel(const line &l){return sgn(v^l.v)==0;}
  bool operator<(const line &l)const{return ang<l.ang;}
  double pointDist(const point &p1)const{return double(v^p1)-double(v^p);}
  point intersection(const line &l)
  {
    point u=p-l.p;
    double t=(l.v^u)/(v^l.v);
    return p+v*t;
  }
  /*point intersection(const line &l)
  {
    double d=v^l.v;point p=l.p;
    return (l.v*c-v*l.c)/d;
  }*/
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
  int t;cin>>t;cout<<"INTERSECTING LINES OUTPUT"<<endl;
  while(t--)
  {
    point a,b,c,d,o;
    a.input();b.input();c.input();d.input();
    line l1(a,b),l2(c,d);


    if(l1.isParallel(l2))
    {
      if(sgn(l1.pointDist(c))==0)
        cout<<"LINE"<<endl;
      else cout<<"NONE"<<endl;
    }
    else
    {
      o=l1.intersection(l2);
      cout<<setprecision(2)<<fixed<<"POINT "<<o.x<<" "<<o.y<<endl;
    }
  }
  cout<<"END OF OUTPUT"<<endl;
  
  return 0;
}