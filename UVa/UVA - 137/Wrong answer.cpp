/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-26 15:02:47                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-137
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
struct point
{
  double x,y;
  point(){}
  point(double _x,double _y):x(_x),y(_y){}
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
int sgn(double x)
{
  if(fabs(x)<=eps)return 0;
  return x>0?1:-1;
}
//lines are extended to infinity.
//there is a half plane in counter-clock
//side of every line
//finds the common polygoan of those halfplane
vector<point>halfPlaneIntersection(vector<line>&l)
{
  //lines are anti-clockwise
  int n=l.size();sort(l.begin(),l.end());
  int first=0,last=0;vector<point>poly;
  vector<point>p(n);vector<line>q(n);
  q[first]=l[0];
  for(int i=1;i<n;i++)
  {
    while(first<last&&(l[i].v^(p[last-1]-l[i].p))<=eps)last--;
    while(first<last&&(l[i].v^(p[first]-l[i].p))<=eps)first++;
    q[++last]=l[i];
    if(sgn(q[last].v^q[last-1].v)==0)
    {
      last--;
      if((q[last].v^(l[i].p-q[last].p))>eps)q[last]=l[i];
    }
    if(first<last)p[last-1]=q[last-1].intersection(q[last]);
  }
  while(first<last&&(q[first].v^(p[last-1]-q[first].p))<=eps)
    last--;
  if(last-first<=1)return poly;
  p[last]=q[last].intersection(q[first]);
  for(int i=first;i<=last;i++)poly.push_back(p[i]);
  return poly;
}
//positive for anti-clockwise
//expected a non closed circuit
double polygoanArea(vector<point>&p)
{
  int n=p.size();double area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return abs(area/2.0);//signed
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    if(!n)break;vector<point>v(n);
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    reverse(v.begin(),v.end());
    double area=polygoanArea(v);//cout<<area<<endl;
    vector<line>l;
    for(int i=0;i<n;i++)
      l.push_back(line(v[i],v[(i+1)%n]));

    cin>>n;v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++)
      l.push_back(line(v[i],v[(i+1)%n]));
    area+=polygoanArea(v);


    vector<point>poly=halfPlaneIntersection(l);
    area-=2*polygoanArea(poly);
    cout<<setw(8)<<setprecision(2)<<fixed<<area;
  }
  return 0;
}