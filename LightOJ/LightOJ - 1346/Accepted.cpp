/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-26 22:32:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 240                                        memory_used (MB): 2.8                             
*  problem: https://vjudge.net/problem/LightOJ-1346
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

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
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;}
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
  point intersection(line l)
  {
    //check for parallel;
    double t=(l.v^(p-l.p))/(v^l.v);
    return p+v*t;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;double x;cin>>n>>x;vector<point>v(n);
    for(int i=0;i<n;i++)
      cin>>v[i].x>>v[i].y;
    double ans=0;point a(x,0),b=v[0];
    for(int i=1;i<n;i++)
    {
      if(orientation(a,b,v[i])==1)
      {
        line one(a,b),two(v[i],v[i-1]);
        ans+=v[i].dist(one.intersection(two));
        b=v[i];
      }
    }
    setp(3);cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}