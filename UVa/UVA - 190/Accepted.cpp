/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-22 18:11:26                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-190
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
  void set(const double &a,const double &b){x=a,y=b;}
  double valSqure()const{return x*x+y*y;}
  double distSqure(const point &p)const{return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);}
  point unitPerpendicularDown()const{double d=sqrt(valSqure());return {-y/d,x/d};}
};
struct line
{
  point p,v;double ang,c;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;ang=atan2(v.y,v.x),c=v^p;}
  line perpendicular(const point &p1)
  {
    line ret;ret.v.set(-v.y,v.x);ret.p=p1;
    return ret;
  }
  bool isParallel(const line &l){return sgn(v^l.v)==0;}
  bool operator<(const line &l)const{return ang<l.ang;}
  double pointDist(const point &p1)const{return double(v^p1)-double(v^p);}
  point intersection(const line &l)
  {
    point u=p-l.p;//assert(0) for parallel;
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
double radToDeg(double &r){return r*180.0/pi;}
double degToRad(double &d){return d*pi/180.0;}
double atan2_360(point &p)
{
  double ang=atan2(p.y,p.x);
  if(ang<0)ang+=pi+pi;
  return radToDeg(ang);
}
void print(point center,point a)
{
  cout<<setprecision(3)<<fixed;
  double r1=sqrt((center-a).valSqure());
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
    line l1(a,b),l2(b,c);
    point pab=(a+b)/2.0;
    point pbc=(b+c)/2.0;

    line prl1=l1.perpendicular(pab);
    line prl2=l2.perpendicular(pbc);

    point o=prl1.intersection(prl2);
    print(o,a);
  }
  return 0;
}