/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-19 20:48:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 94                                         memory_used (MB): 0.7                             
*  problem: https://vjudge.net/problem/POJ-3525
****************************************************************************************/
//https://vjudge.net/problem/POJ-3335
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
const double eps=1e-7;
struct point
{
  double x,y;
  point(double _x=0,double _y=0){x=_x,y=_y;}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  point operator*(double d){return {x*d,y*d};}
  double operator^(const point &p){return x*p.y-y*p.x;}
  double vlen(){return sqrt(x*x+y*y);}
  point perpendicularDown(){double d=vlen();return {-y/d,x/d};}

};
struct line
{
  point p,v;double ang;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;ang=atan2(v.y,v.x);}
  line(point p1,point p2,int ov){p=p1,v=p2;ang=atan2(v.y,v.x);}
  void _move(point u){p=p+u;}
  bool operator<(const line &l)const{return ang<l.ang;}
  point intersection(line l)
  {
    point u=p-l.p;
    double t=(l.v^u)/(v^l.v);
    return p+v*t;
  }
};
int sgn(double x)
{
  if(fabs(x)<=eps)return 0;
  return x>0?1:-1;
}
void halfPlaneIntersection(vector<line>&l,vector<point>&poly)
{
  //points are expected to be anti-clockwise
  //Valid for polygoan edge
  int n=l.size();sort(l.begin(),l.end());
  int first=0,last=0;
  vector<point>p(n);vector<line>q(n);
  q[first]=l[0];
  for(int i=1;i<n;i++)
  {
    while(first<last&&(l[i].v^(p[last-1]-l[i].p))<=-eps)last--;
    while(first<last&&(l[i].v^(p[first]-l[i].p))<=-eps)first++;
    q[++last]=l[i];
    if(sgn(q[last].v^q[last-1].v)==0)
    {
      last--;
      if((q[last].v^(l[i].p-q[last].p))>=-eps)q[last]=l[i];
    }
    if(first<last)p[last-1]=q[last-1].intersection(q[last]);
  }
  while(first<last&&(q[first].v^(p[last-1]-q[first].p))<=-eps)
    last--;
  if(last-first<=1)return ;
  p[last]=q[last].intersection(q[first]);
  for(int i=first;i<=last;i++)poly.push_back(p[i]);
}
double largestCircleInPolygoan(vector<point>&p)
{
  double lo=0,hi=1e9,md;int n=p.size();
  vector<line>l(n);
  while(hi-lo>eps)
  {
    md=(lo+hi)/2.0;
    for(int i=0;i<n;i++)
    {
      point v=p[(i+1)%n]-p[i];
      point pt=p[i]+v.perpendicularDown()*md;
      l[i]=line(pt,v,1);
    }
    vector<point>poly;
    halfPlaneIntersection(l,poly);
    if(poly.size()>0)lo=md;else hi=md;
  }
  return md;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    if(!n)break;
    vector<point>p(n);
    for(int i=0;i<n;i++)
      cin>>p[i].x>>p[i].y;
    cout<<setprecision(6)<<fixed<<largestCircleInPolygoan(p)<<endl;
  }
  return 0;
}