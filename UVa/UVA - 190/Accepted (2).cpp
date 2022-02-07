/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-01 22:55:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-190
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
  point(double _x,double _y){x=_x,y=_y;}
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  point operator*(double d){return {x*d,y*d};}
  point operator/(double d){return {x/d,y/d};}
  double sqvl(){return x*x+y*y;}
  double vl(){return sqrt(x*x+y*y);}
};
double dot(point v,point w){return v.x*w.x+v.y*w.y;}
double cross(point v,point w){return v.x*w.y-v.y*w.x;}
struct line
{
  point v;double c;
  line(){}
  line(point _v,double _c){v=_v,c=_c;}
  line(point p,point q){v=q-p;c=cross(v,p);}
};
line perp(point v,point p)
{
  v={-v.y,v.x};double c=cross(v,p);
  return {v,c};
}
bool intersect(line l1,line l2,point&o)
{
  double d=cross(l1.v,l2.v);
  if(fabs(d)<=eps)return 0;
  o=(l2.v*l1.c-l1.v*l2.c)/d;
  return 1;
}
point mid(point a,point b)
{
  return (a+b)/2.0;
}
void print(point center,point a)
{
  cout<<setprecision(3)<<fixed;
  double r1=(center-a).vl();
  if(r1<0)center.x*=-1,center.y*=-1;
  cout<<"(x";
  if(center.x>=0)cout<<" - ";
  else cout<<" + ";
  cout<<fabs(center.x);
  cout<<")^2 + (y";
  if(center.y>=0)cout<<" - ";
  else cout<<" + ";
  cout<<fabs(center.y);
  cout<<")^2 = ";
  cout<<fabs(r1);
  cout<<"^2"<<endl;


  double hx=-2*center.x;
  double yk=-2*center.y;
  double cns=center.x*center.x+center.y*center.y-r1*r1;
  cout<<"x^2 + y^2";

  if(hx>=0)cout<<" + ";
  else cout<<" - ";
  cout<<fabs(hx)<<"x";

  if(yk>=0)cout<<" + ";
  else cout<<" - ";
  cout<<fabs(yk)<<"y";

  if(cns>=0)cout<<" + ";
  else cout<<" - ";
  cout<<fabs(cns);
  cout<<" = 0"<<endl<<endl;

}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  point a,b,c;
  while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y)
  {
    line l1(a,b),l2(b,c);
    point pab=mid(a,b);
    point pbc=mid(b,c);

    line prl1=perp(l1.v,pab);
    line prl2=perp(l2.v,pbc);

    point o;intersect(prl1,prl2,o);
    print(o,a);
  }
  
  return 0;
}