/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-26 19:43:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-920
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
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<point>p(n);
    for(int i=0;i<n;i++)
      cin>>p[i].x>>p[i].y;
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    double ans=0,mx=0;
    for(int i=1;i<p.size();i++)
    {
      if(p[i].y<=mx)continue;
      line one(point(0,mx),point(1,mx));
      line two(p[i],p[i-1]);
      point x=one.intersection(two);
      ans+=x.dist(p[i]);mx=p[i].y;
    }
    setp(2);cout<<ans<<"\n";
  }
  return 0;
}