/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-18 22:42:18                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 125                                        memory_used (MB): 0.9                             
*  problem: https://vjudge.net/problem/POJ-1279
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
const int N=5e4;
const double eps=1e-8;
inline int sgn(const double &x)
{
  return x>eps?1:(x<-eps?-1:0);
}
struct point
{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator+(const point &rhs)const{return point(x+rhs.x,y+rhs.y);}
  point operator-(const point &rhs)const{return point(x-rhs.x,y-rhs.y);}
  point operator*(double scale)const{return point(x*scale,y*scale);}
  double operator^(const point &rhs)const{return x*rhs.y-y*rhs.x;}
};
struct line
{
  point p,v;double ang;
  line(){}
  line(point p,point v):p(p),v(v){ang=atan2(v.y,v.x);}
  bool operator<(const line &rhs)const{return ang<rhs.ang;}
};
double cross(point a,point b){return a^b;}
bool onLeft(line l,point p)
{
  return sgn(cross(l.v,p-l.p))>0;
}
point getIntersection(line a,line b)
{
  point u=a.p-b.p;
  double t=cross(b.v,u)/cross(a.v,b.v);
  return a.p+a.v*t;
}
vector<line>l;
int halfPlaneIntersection(int n,vector<point>&poly)
{
  sort(l.begin(),l.end());
  int first,last;
  //point *p=new point[n];
  //line *q=new line[n];
  vector<point>p(n);vector<line>q(n);
  q[first=last=0]=l[0];
  for(int i=1;i<n;i++)
  {
    while(first<last&&!onLeft(l[i],p[last-1]))last--;
    while(first<last&&!onLeft(l[i],p[first]))first++;
    q[++last]=l[i];
    if(sgn(fabs(cross(q[last].v,q[last-1].v)))==0)
    {
      last--;
      if(onLeft(q[last],l[i].p))q[last]=l[i];
    }
    if(first<last)p[last-1]=getIntersection(q[last-1],q[last]);
  }
  while(first<last&&!onLeft(q[first],p[last-1]))last--;
  if(last-first<=1)return 0;
  p[last]=getIntersection(q[last],q[first]);
  for(int i=first;i<=last;i++)
    poly.push_back(p[i]);
  return poly.size();
}
double polygoanArea(vector<point>p,int n)
{
  double area=0;
  for(int i=1;i<n-1;i++)
    area+=cross(p[i]-p[0],p[i+1]-p[0]);
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
      l[i]=line(p[i],p[i+1]-p[i]);
    int m=halfPlaneIntersection(n,poly);
    double ans=polygoanArea(poly,m);
    cout<<setprecision(2)<<fixed<<ans<<endl;
  }
  return 0;
}