/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 13:53                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 8500 KB                              
*  problem: https://codeforces.com/contest/1388/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
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
double modifiedatan2(point p)//ccw full angle with positive x axis
{
  double ang=atan2(p.y,p.x);if(ang<0)ang+=pi+pi;//carefull
  return radToDeg(ang);//deg return 
}
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point _p,point _v):p(_p),v(_v){}
  void makeLine(point p1,point p2){p=p1,v=p2-p1;}
  bool onLine(point p1)
  {
    if(sgn(v^(p1-p))!=0)return false;//area of triangle has to be 0
    return true;
  }
  double pointDist(point p1)
  {
    //area of triangle/base of triangle
    return abs((v^(p1-p))/v.value());//signed based on cw ans ccw
  }
  line perpendicular(point p1){return line(p1,v.rotateCCW90());}
  point intersection(line l)
  {
    //no solution for parallel line.
    return p+v*((l.v^(p-l.p))/(v^l.v));
  }
};
struct segment
{
  double x1,x2,y;
}a[N+2];
int n;
double ck(point p)
{
  vector<pair<double,double> >v;
  line l;l.makeLine(point(0,0),point(100,0));
  line l2;l2.v=p;
  for(int i=1;i<=n;i++)
  {
    l2.p=point(a[i].x1,a[i].y);
    point one=l.intersection(l2);
     l2.p=point(a[i].x2,a[i].y);
    point two=l.intersection(l2);
     v.push_back({one.x,two.x});
  }
  sort(v.begin(),v.end());
  double inf=1e16;
  for(int i=1;i<v.size();i++)
  {
    if(v[i].first+eps<v[i-1].second)return inf;
  }
  return v.back().second-v[0].first;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i].x1>>a[i].x2>>a[i].y;
  double ans=1e16;
  vector<point>v;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(a[j].y>=a[i].y)continue;
      v.push_back(point(a[j].x2,a[j].y)-point(a[i].x1,a[i].y));
      v.push_back(point(a[j].x1,a[j].y)-point(a[i].x2,a[i].y));
    }
  }
  v.push_back(point(0,-100));
  sort(v.begin(),v.end(),[&](point a,point b){
    return fabs(modifiedatan2(a)-270)<fabs(modifiedatan2(b)-270);
  });
  setp(10);
  for(auto x:v)
    if(ck(x)<1e10)cout<<ck(x)<<endl,exit(0);
  //assert(ans<1e10);
  //setp(10);cout<<ans<<endl;
  return 0;
}