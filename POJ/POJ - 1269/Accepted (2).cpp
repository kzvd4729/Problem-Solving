/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 15:51:53                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 0.7                             
*  problem: https://vjudge.net/problem/POJ-1269
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<iomanip>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
struct point
{
  double x,y;
  point(){}
  point(double _x,double _y){x=_x,y=_y;}
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  point operator*(double d){return {x*d,y*d};}
  point operator/(double d){return {x/d,y/d};}
  double operator*(point p){return x*p.x+y*p.y;}
  double operator^(point p){return x*p.y-y*p.x;}
};
struct line
{
  point v;double c;
  line(){}
  line(point _v,double _c){v=_v,c=_c;}
  line(point p1,point p2){v=p2-p1;c=v^p1;}
  double pointlinedistmul(point p){return (double)(v^p)-c;}
  int intersect(line l,point p,point&o)
  {
    double d=v^l.v;
    if(fabs(d)<=eps)
    {
      if(fabs(pointlinedistmul(p))<=eps)
        return 2;
      return 0;
    }
    o=(l.v*c-v*l.c)/d;return 1;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;cout<<"INTERSECTING LINES OUTPUT"<<endl;
  while(t--)
  {
    point a,b,c,d,o;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    line l1(a,b),l2(c,d);
    int f=l1.intersect(l2,c,o);
    if(!f)cout<<"NONE"<<endl;
    else if(f==2)cout<<"LINE"<<endl;
    else cout<<setprecision(2)<<fixed<<"POINT "<<o.x<<" "<<o.y<<endl;
  }
  cout<<"END OF OUTPUT"<<endl;
  return 0;
}