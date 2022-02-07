/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-02 15:47:31                      
*  solution_verdict: Compilation error                       language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11178
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

const double eps=1e-9,pi=acos(-1.0);
int sgn(double d)
{
  if(fabs(d)<eps)return 0;return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(){};point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(double d){return point(x*d,y*d);}
  point operator/(double d){return point(x/d,y/d);}
  bool operator==(point p){return x==p.x&&y==p.y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  double value(){return sqrt(x*x+y*y);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  point unitVector()
  {
    //invalid if vector is (0,0)
    double v=value();return point(x/v,y/v);
  }
  double operator*(point p)
  {
    return x*p.x+y*p.y;//0 if vectors are perpendicular;
  }
  double operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
  point rotateCCW(double a)//radian
  {
    return point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
  }
  point rotateCCW90(){return point(-y,x);}
  point rotateCCW180(){return point(-x,-y);}
  point rotateCCW270(){return point(y,-x);}
};
double radToDeg(double r){return r*180.0/pi;}
double degToRed(double d){return d*pi/180.0;}
double modifiedatan2(point p)//clockwise full angle with positive x axis
{
  double ang=atan2(p.y,p.x);if(ang<0)ang+=pi+pi;//carefull
  return ang;//rad return
}
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point _p,point _v):p(_p),v(_v){}
  void makeLine(point p1,point p2){p=p1,v=p2-p1;}
  point intersection(line l)
  {
    //no solution for parallel line.
    return p+v*((l.v^(p-l.p))/(v^l.v));
  }
};
double retAng(point a,point b,point c)//angle between C to A
{
  a=a-b,c=c-b;
  double ang=modifiedatan2(a)-modifiedatan2(c);
  if(ang<0)ang+=pi+pi;
  return ang;
}
point ret(point a,point b,double ang)//rotate b wrt a
{
  point v=b-a;v=rotateCCW(ang);
  return v+a;
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    point a,b,c;cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;

    double ang1=retAng(a,b,c);
    double ang2=retAng(b,c,a);
    double ang3=retAng(c,a,b);

    line l1,l2;
    l1.makeLine(b,ret(b,c,ang1/3.0));
    l2.makeLine(c,ret(c,a,(ang2/3.0)*2.0));
    point d=l1.intersection(l2);
    
    l1.makeLine(c,ret(c,a,ang2/3.0));
    l2.makeLine(a,ret(a,b,ang2/3.0));

    double ang=retAng(a,b,c);line l;
    l.makeLine(b,ret(b,c,ang/3.0));

    double ang2=retAng(b,c,a);line l2;
    l2.makeLine(c,ret(c,a,(ang2/3.0)*2.0));

    point d=l.intersection(l2);
  }
  return 0;
}