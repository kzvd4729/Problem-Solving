/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-18 22:55:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 110                                        memory_used (MB): 0.9                             
*  problem: https://vjudge.net/problem/POJ-1279
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
const double eps=1e-9;
struct point
{
  double x,y;
  point(double _x=0,double _y=0){x=_x,y=_y;}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  point operator*(double d){return {x*d,y*d};}
  double operator^(const point &p){return x*p.y-y*p.x;}
};
struct line
{
  point p,v;double ang;
  line(){}
  line(point p1,point p2){p=p1,v=p2-p1;ang=atan2(v.y,v.x);}
  bool operator<(const line &l)const{return ang<l.ang;}
  point intersection(line l)
  {
    point u=p-l.p;
    double t=(l.v^u)/(v^l.v);
    return p+v*t;
  }
};
inline int sgn(const double &x)
{
  if(fabs(x)<=eps)return 0;
  return x>eps?1:-1;
}
bool onLeft(line l,point p)
{
  return sgn(l.v^(p-l.p))>0;
}
vector<line>l;
int halfPlaneIntersection(int n,vector<point>&poly)
{
  sort(l.begin(),l.end());
  int first,last;
  vector<point>p(n);vector<line>q(n);
  q[first=last=0]=l[0];
  for(int i=1;i<n;i++)
  {
    while(first<last&&!onLeft(l[i],p[last-1]))last--;
    while(first<last&&!onLeft(l[i],p[first]))first++;
    q[++last]=l[i];
    if(sgn(fabs(q[last].v^q[last-1].v))==0)
    {
      last--;
      if(onLeft(q[last],l[i].p))q[last]=l[i];
    }
    if(first<last)p[last-1]=q[last-1].intersection(q[last]);
  }
  while(first<last&&!onLeft(q[first],p[last-1]))last--;
  if(last-first<=1)return 0;
  p[last]=q[last].intersection(q[first]);
  for(int i=first;i<=last;i++)
    poly.push_back(p[i]);
  return poly.size();
}
double polygoanArea(vector<point>p,int n)
{
  double area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return area/2.0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<point>p(n),poly;
    for(int i=0;i<n;i++)
      cin>>p[i].x>>p[i].y;
    reverse(p.begin(),p.end());
    p[n]=p[0];l.resize(n);
    for(int i=0;i<n;i++)
      l[i]=line(p[i],p[i+1]);
    int m=halfPlaneIntersection(n,poly);
    double ans=polygoanArea(poly,m);
    cout<<setprecision(2)<<fixed<<ans<<endl;
  }
  return 0;
}