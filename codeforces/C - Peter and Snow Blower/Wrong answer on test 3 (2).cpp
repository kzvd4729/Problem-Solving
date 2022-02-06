/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2020 21:31                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/614/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
 #define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9,pi=acos(-1.0);
 int sgn(double d)
{
  if(fabs(d)<eps)return 0;return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(){};
  point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(double d){return point(x*d,y*d);}
  point operator/(double d){return point(x/d,y/d);}
  double value(){return sqrt(x*x+y*y);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  point unitVector()
  {
    //invalid if point is (0,0)
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
};
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point _p,point _v):p(_p),v(_v){}
  void makeLine(point p1,point p2){p=p1,v=p2-p1;}
  double pointDist(point p1)
  {
    //area of triangle/base of triangle
    return (v^(p1-p))/v.value();//signed based on cw ans ccw
  }
};
struct segment
{
  point a,b;
  segment(){};
  segment(point _a,point _b):a(_a),b(_b){}
  bool onSegment(point p)//in or on the rectangle formed by the segment
  {
    if(p.x>=min(a.x,b.x)&&p.x<=max(a.x,b.x)&&p.y>=min(a.y,b.y)&&p.y<=max(a.y,b.y))
      return true;
    return false;
  }
  double segmentToPointDist(point p)
  {
    double ret=min(p.dist(a),p.dist(b));
    if(onSegment(p))
    {
      line l;l.makeLine(a,b);ret=l.pointDist(p);
    }
    return ret;
  }
};
struct circle
{
  double x,y,r;
  circle(){};
  circle(double _x,double _y,double _r):x(_x),y(_y),r(_r){}
};
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;point p;cin>>n>>p.x>>p.y;
  vector<point>v(n);
  for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
   double mx=0,mn=1e9;
  for(int i=0;i<n;i++)
  {
    mx=max(mx,p.dist(v[i]));
    mn=min(mn,segment(v[i],v[(i+1)%n]).segmentToPointDist(p));
  }
  setp(10);
  cout<<(mx*mx-mn*mn)*pi<<endl;
  return 0;
}