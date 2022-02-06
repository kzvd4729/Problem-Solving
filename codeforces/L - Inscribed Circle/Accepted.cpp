/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2019 23:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/gym/102215/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
 //..............................................................................
#define setp(a) cout<<setprecision(a)<<fixed
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
  double value(){return sqrt(x*x+y*y);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  point unit()
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
    //sigbed area of the parallelogram by two vector
    //positive if p is ccw to the point
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
    return (v^(p1-p))/v.value();
  }
};
struct circle
{
  double x,y,r;
  circle(){};circle(double _x,double _y,double _r):x(_x),y(_y),r(_r){}
  bool pointInCircle(point p)//in or on
  {
    return p.dist(point(x,y))<=r;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   double x,y,z;cin>>x>>y>>z; point p(x,y);
  circle a(x,y,z);cin>>x>>y>>z;circle b(x,y,z); point q(x,y);
   double d=1e6;
   int loop=1000;double lo=0,hi=d,md;
  while(loop--)
  {
    md=(lo+hi)/2.0;
     point v=(((q-p).unit()*md)+p);
     if(a.pointInCircle(v))lo=md;
    else hi=md;
  }
  point A=(((q-p).unit()*md)+p);
   loop=1000;lo=0,hi=d,md;
  while(loop--)
  {
    md=(lo+hi)/2.0;
     point v=(((p-q).unit()*md)+q);
     if(b.pointInCircle(v))lo=md;
    else hi=md;
  }
  point B=(((p-q).unit()*md)+q);
   setp(15);
   point C=point((A.x+B.x)/2.0,(A.y+B.y)/2.0);
  cout<<C.x<<" "<<C.y<<" "<<A.dist(C)<<endl;
    return 0;
}