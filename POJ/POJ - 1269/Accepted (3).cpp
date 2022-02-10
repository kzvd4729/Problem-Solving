/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 15:49:16                      
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
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  point operator*(double d){return {x*d,y*d};}
  point operator/(double d){return {x/d,y/d};}
};
double dot(point v,point w){return v.x*w.x+v.y*w.y;}
double cross(point v,point w){return v.x*w.y-v.y*w.x;}
struct line
{
  point v;double c;
  line(point p,point q){v=q-p;c=cross(v,p);}
  double disttopoint(point p){return cross(v,p)-c;}
};
bool intersect(line l1,line l2,point&o)
{
  double d=cross(l1.v,l2.v);
  if(fabs(d)<=eps)return false;
  o=(l2.v*l1.c-l1.v*l2.c)/d;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;cout<<"INTERSECTING LINES OUTPUT"<<endl;
  while(t--)
  {
    point a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    line l1(a,b);line l2(c,d);point o;
    int f=intersect(l1,l2,o);
    cout<<setprecision(2)<<fixed;
    if(!f)
    {
      if(fabs(l2.disttopoint(a))<=eps)cout<<"LINE"<<endl;
      else cout<<"NONE"<<endl;
    }
    else cout<<"POINT"<<" "<<o.x<<" "<<o.y<<endl;
  }
  cout<<"END OF OUTPUT"<<endl;
  return 0;
}