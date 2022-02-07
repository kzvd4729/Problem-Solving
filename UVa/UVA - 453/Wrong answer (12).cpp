/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-29 16:42:19                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-453
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const long double eps=1e-7;
const long double ad=1e-4;
struct point
{
  long double x,y;
};
struct equation
{
  long double a,b,c;
};
point sub(point a,point b)
{
  a.x-=b.x;a.y-=b.y;
  return a;
}
point add(point a,point b)
{
  a.x+=b.x;a.y+=b.y;
  return a;
}
bool equal(point a,point b)
{
  return fabs(a.x-b.x)<=eps&&fabs(a.y-b.y)<=eps;
}
equation make_equation(point p1,point p2)
{
  equation eq;//ax+by=c;
  eq.a=p1.y-p2.y;eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  return eq;
}
equation perpendicular(equation eq,point p)
{
  equation rt;rt.a=eq.b;rt.b=-eq.a;
  rt.c=rt.a*p.x+rt.b*p.y;return rt;
}
point equation_to_vector(equation e)
{
  return {e.b,-e.a};
}
long double dist(point p1,point p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
void print(point a,point b)
{
  cout<<"("<<a.x+ad<<","<<a.y+ad<<")";
  cout<<"("<<b.x+ad<<","<<b.y+ad<<")";
  cout<<endl;
}

void circle_circle_intersection(point c1,long double r1,point c2,long double r2)
{
  cout<<setprecision(3)<<fixed;
  if(equal(c1,c2)&&fabs(r1-r2)<=eps)
  {
    if(fabs(r1)<=eps)
    {
      //assert(0);
      cout<<"("<<c1.x+ad<<","<<c1.y+ad<<")"<<endl;
    }
    else cout<<"THE CIRCLES ARE THE SAME"<<endl;
    return ;
  }
  long double c1c2=dist(c1,c2);
  if(c1c2>r1+r2)
  {
    cout<<"NO INTERSECTION"<<endl;
    return ;
  }
  long double c1p=(r1*r1+c1c2*c1c2-r2*r2)/(2.0*c1c2);
  long double h=sqrt(r1*r1-c1p*c1p);

  point p=sub(c2,c1);
  p.x*=c1p/c1c2;p.y*=c1p/c1c2;
  p=add(p,c1);

  if(fabs(c1c2-r1-r2)<=eps)
  {
    cout<<"("<<p.x<<","<<p.y<<")"<<endl;
    return ;
  }
  equation e=make_equation(c1,c2);
  e=perpendicular(e,{0,0});
  point v=equation_to_vector(e);

  long double ds=dist({0,0},v);
  v.x*=h/ds;v.y*=h/ds;

  point a={p.x+v.x,p.y+v.y};
  point b={p.x-v.x,p.y-v.y};

  if(fabs(a.x-b.x)<=eps)
  {
    if(a.y<b.y)print(a,b);
    else print(b,a);
  }
  else
  {
    if(a.x<b.x)print(a,b);
    print(b,a);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  point c1,c2;long double r1,r2;
  while(cin>>c1.x>>c1.y>>r1>>c2.x>>c2.y>>r2)
  {
    circle_circle_intersection(c1,r1,c2,r2);
  }
  return 0;
}