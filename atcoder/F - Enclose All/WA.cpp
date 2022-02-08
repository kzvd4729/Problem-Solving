/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-12 19:07:49                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc151/tasks/abc151_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
  //..............................................................................
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
  void inp(){cin>>x>>y;}
  void out(){cout<<x<<" -- "<<y<<endl;}
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
  point pt[N+2];int n;double ans=1e9;
void ck(point c,double r)
{
  for(int i=1;i<=n;i++)
    if(c.dist(pt[i])-eps>r)return ;
  ans=min(ans,r);
}
bool circumCircle(point a,point b,point c,point &p)
{
  if(sgn((b-a)^(c-a))==0)return false;
  line l1(a,b),l2(b,c),l3(c,a);
   point md1=(a+b)/2,md2=(b+c)/2,md3=(c+a)/2;
   l1=l1.perpendicular(md1);
  l2=l2.perpendicular(md2);
  l3=l3.perpendicular(md3);
   p=l1.intersection(l2);
 }
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)pt[i].inp();
   //for(int i=1;i<=n;i++)cout<<pt[i].x<<" "<<pt[i].y<<endl;
   for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      point md=(pt[i]+pt[j])/2;
      ck(md,md.dist(pt[i]));
    }
  }
   for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      for(int k=j+1;k<=n;k++)
      {
        point p;
        if(circumCircle(pt[i],pt[j],pt[k],p))
          ck(p,p.dist(pt[i]));
      }
    }
  }
  setp(10);cout<<ans<<endl;
    return 0;
}