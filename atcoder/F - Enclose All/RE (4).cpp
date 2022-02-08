/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-12 22:34:03                      
*  solution_verdict: RE                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 98 ms                                           memory_used: 384 KB                               
*  problem: https://atcoder.jp/contests/abc151/tasks/abc151_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
//..............................................................................
/*
a circle is uniquely determined by two or three points
*/
const double eps=1e-9;
int sgn(const double d)
{
  if(fabs(d)<=eps)return 0;
  return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(){};point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(double d){return point(x*d,y*d);}
  point operator/(double d){return {x/d,y/d};}
  double value(){return sqrt(x*x+y*y);}
  point unit()
  {
    //invalid if point is (0,0)
    double v=value();return point(x/v,y/v);
  }
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
};
point findP(point a,point b,double d)
{
  b=b-a;point u=b.unit();
  u=u*d;return a+u;
}
bool isInside(vector<point>&p,point &c,double r)
{
  for(auto x:p)if(sgn(c.dist(x)-r)==1)return false;
  return true;
}
point minimumEnclosingCircle(vector<point>&p)
{
  cout<<setprecision(6)<<fixed;
  int n=p.size();if(n<2)return {-1,-1};//degenerate case
  double r=0;point c=p[0];int a=-1,b=-1;
  for(int i=0;i<n;i++)
  {
    if(c.dist(p[i])>r)r=c.dist(p[i]),a=i;//first point on boundery
  }
  //cout<<r<<endl;
  //cout<<c.x<<" "<<c.y<<endl;
   double lo=0,hi=r,md;point tc;
  while(hi-lo>(1e-12))
  {
    md=(lo+hi)/2.0;tc=findP(p[a],c,md);
     if(isInside(p,tc,md))hi=md;else lo=md; 
  }
  c=tc,r=md;
  //cout<<r<<endl;
  //cout<<c.x<<" "<<c.y<<endl;
  for(int i=0;i<n;i++)
  {
    if(i==a)continue;
    //cout<<c.dist(p[i])-r<<endl;
    if(sgn(c.dist(p[i])-r)==0)b=i;
  }
  if(b==-1)assert(0);//something fishy
   //cout<<a<<" "<<b<<endl;
  //cout<<c.x<<" "<<c.y<<endl;
   point m=(p[a]+p[b])/2.0;//cout<<m.x<<" "<<m.y<<endl;
  lo=0,hi=m.dist(c);//cout<<hi<<endl;
  while(hi-lo>(1e-12))
  {
    md=(lo+hi)/2.0;tc=findP(m,c,md);
     if(isInside(p,tc,tc.dist(p[a])))hi=md;else lo=md; 
  }
  //cout<<tc.x<<" "<<tc.y<<endl;
  return tc;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<point>p(n);
  for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
   point c=minimumEnclosingCircle(p);
   double r=0;
  for(auto x:p)r=max(r,c.dist(x));
   cout<<setprecision(6)<<fixed<<r<<endl;
    return 0;
}