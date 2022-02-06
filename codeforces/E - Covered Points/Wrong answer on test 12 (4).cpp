/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/22/2020 22:28                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1036/problem/E
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
const int N=1e6;
#define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-2,pi=acos(-1.0);
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
  point a,b;
  segment(){}
  segment(point _a,point _b):a(_a),b(_b){}
  //onLine and onSegment
  bool onLine(point p)
  {
    line l;l.makeLine(a,b);
    if(!l.onLine(p))return false;
    if(p.x>=min(a.x,b.x)&&p.x<=max(a.x,b.x)&&p.y>=min(a.y,b.y)&&p.y<=max(a.y,b.y))
      return true;//precision 
    return false;
  }
  int segmentIntersect(segment sg)
  {
    int s1,s2,s3,s4;
    int d1=sgn(s1=(b-a)^(sg.a-a)),d2=sgn(s2=(b-a)^(sg.b-a));
    int d3=sgn(s3=(sg.b-sg.a)^(a-sg.a)),d4=sgn(s4=(sg.b-sg.a)^(b-sg.a));
    if((d1^d2)==-2&&(d3^d4)==-2)return 1;
    else if(d1==0&&sgn((a-sg.a)*(b-sg.a))<=0)return 2;
    else if(d2==0&&sgn((a-sg.b)*(b-sg.b))<=0)return 2;
    else if(d3==0&&sgn((sg.a-a)*(sg.b-a))<=0)return 2;
    else if(d4==0&&sgn((sg.a-b)*(sg.b-b))<=0)return 2;
    return 0;
  }
  //this is a very bad way to do this
  double segmentToPointDist(point p)
  {
    line l,r;l.makeLine(a,b);r=l.perpendicular(p);
    double ret=min(a.dist(p),b.dist(p));
    if(onLine(l.intersection(r)))ret=l.pointDist(p);
    return ret;
  }
  double segmentSegmentDist(segment sg)
  {
    if(segmentIntersect(sg))return 0;
    double ret=segmentToPointDist(sg.a);
    ret=min(ret,segmentToPointDist(sg.b));
    ret=min(ret,sg.segmentToPointDist(a));
    ret=min(ret,sg.segmentToPointDist(b));
    return ret;
  }
};
bool isInt(double x)
{
  double z=round(x);
  return fabs(x-z)<=eps;
}
int a[N+2],b[N+2],c[N+2],d[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int ans=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i]>>b[i]>>c[i]>>d[i];
    ans+=__gcd(abs(c[i]-a[i]),abs(d[i]-b[i]))+1;
  }
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      segment s1(point(a[i],b[i]),point(c[i],d[i]));
      segment s2(point(a[j],b[j]),point(c[j],d[j]));
       int in=s1.segmentIntersect(s2);if(in==0)continue;
      //if(in==2)cout<<i<<" --> "<<j<<endl;
       line l1(point(a[i],b[i]),point(c[i]-a[i],d[i]-b[i]));
      line l2(point(a[j],b[j]),point(c[j]-a[j],d[j]-b[j]));
       point p=l1.intersection(l2);
      if(isInt(p.x)&&isInt(p.y))
        st.insert({round(p.x),round(p.y)});
    }
  }
  cout<<ans-st.size()<<endl;
  return 0;
}