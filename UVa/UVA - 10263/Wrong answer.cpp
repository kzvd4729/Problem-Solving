/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-27 09:39:37                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10263
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

#define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9;
const double pi=acos(-1.0);

int sgn(const double d)
{
  if(fabs(d)<=eps)return 0;
  return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(){};
  point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  point operator*(double d){return {x*d,y*d};}
  point operator/(double d){return {x/d,y/d};}
  double operator*(point p)
  {
    return x*p.x+y*p.y;
    //0 if vectors are perpendicular;
  }
  double operator^(point p)
  {
    return x*p.y-y*p.x;
    //area of the parallelogram by two vector
    //0 if two vectors are same
    //positive if p ccw to the point
  }
  bool operator<(const point &p)const{return x<p.x||(sgn(x-p.x)==0&&y<p.y);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
};
int orientation(point a,point b,point c)
{
  return sgn((b-a)^(c-a));
  //0 for straight line 1 for ccw -1 for cw
}
bool inRec(point s,point e,point p)
{
  double mxx=max(s.x,e.x),mnx=min(s.x,e.x);
  double mxy=max(s.y,e.y),mny=min(s.y,e.y);
  return p.x<=mxx+eps&&p.x>=mnx-eps&&p.y<=mxy+eps&&p.y>=mny-eps;
  //point p is inside(or on) the rectangle formed by the segment.
}
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;}
  line perpendicular(point p)
  {
    line l;l.v=point(-v.y,v.x);
    l.p=p;return l;
    //rotating the vector 90 degree
    //the line going through point p
  }
  bool isParallel(line l)
  {
    return sgn(v^l.v)==0;
    //have to be same vector,so area 0;
  }
  int whichSide(point p1)
  {
    return sgn(v^(p1-p));
    //0 if point belongs to the line
    //can return positive or negative
    //compare a known points sign to 
    //determine left or right
  }
  double pointDist(point p1){return (v^p1)-(v^p);}
  point intersection(line l)
  {
    //check for parallel;
    double t=(l.v^(p-l.p))/(v^l.v);
    return p+v*t;
  }
};
struct segment
{
  point s,e;
  segment(){}
  segment(point _s,point _e):s(_s),e(_e){}
  void in(){cin>>s.x>>s.y>>e.x>>e.y;}
  void out(){cout<<s.x<<" "<<s.y<<" --> "<<e.x<<" "<<e.y<<endl;}
};
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  point p;
  while(cin>>p.x)
  {
    cin>>p.y;
    int n;cin>>n;vector<point>v(n+1);
    for(int i=0;i<=n;i++)
      cin>>v[i].x>>v[i].y;
    point pr=v[0];double dis=v[0].dist(p);
    for(int i=1;i<=n;i++)
    {
      if(v[i].dist(p)<dis)
      {
        dis=v[i].dist(p);pr=v[i];
      }
      line l(v[i],v[i-1]);
      line k=l.perpendicular(p);
      point in=l.intersection(k);

      if(inRec(v[i],v[i-1],p))
      {
        if(in.dist(p)<dis)dis=in.dist(p),pr=in;
      }
    }
    setp(4);cout<<pr.x<<"\n"<<pr.y<<"\n";
  }
  return 0;
}