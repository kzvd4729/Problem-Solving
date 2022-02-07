/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-02 22:09:35                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-453
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
const double ad=1e-8;
struct point
{
  double x,y;
  point(){}
  point(double _x,double _y){x=_x,y=_y;}
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  point operator*(double d){return {x*d,y*d};}
  point operator/(double d){return {x/d,y/d};}
  double vlsq(){return x*x+y*y;}
  point perp(){return {-y,x};}
};
int sgn(double d)
{
  if(d==0)return 0;
  if(d<0)return -1;
  return 1;
}
int circleCircle(point o1,double r1,point o2,double r2,pair<point,point>&out)
{
  point d=o2-o1;double d2=d.vlsq();
  if(fabs(d2)<=eps){return 0;}// concentric circles
  double pd=(d2+r1*r1-r2*r2)/2;// = |O_1P| * d
  double h2=r1*r1-pd*pd/d2;// = hˆ2
  if(h2>=0)
  {
    point p=o1+d*pd/d2,h=d.perp()*sqrt(h2/d2);
    out={p-h,p+h};
  }
  return 1+sgn(h2);
}
bool isequal(point a,point b)
{
  return fabs(a.x-b.x)<=eps&&fabs(a.y-b.y)<=eps;
}
void print(point a,point b)
{
  cout<<"("<<a.x+ad<<","<<a.y+ad<<")";
  cout<<"("<<b.x+ad<<","<<b.y+ad<<")";
  cout<<endl;
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  point c1,c2;double r1,r2;
  while(cin>>c1.x>>c1.y>>r1>>c2.x>>c2.y>>r2)
  {
    pair<point,point>out;
    cout<<setprecision(3)<<fixed;
    if(isequal(c1,c2)&&fabs(r1-r2)<=eps)
    {
      if(fabs(r1)<=eps)
      {
        cout<<"("<<c1.x<<","<<c1.y<<")"<<endl;
      }
      else cout<<"THE CIRCLES ARE THE SAME"<<endl;
      continue;
    }
    int f=circleCircle(c1,r1,c2,r2,out);
    if(f==0)
    {
      cout<<"NO INTERSECTION"<<endl;continue;
    }
    point a=out.first,b=out.second;
    if(f==1)
    {
      cout<<"("<<a.x+ad<<","<<a.y+ad<<")"<<endl;
    }
    else
    {
      if(fabs(a.x-b.x)<=eps)
      {
        if(a.y<b.y)print(a,b);
        else print(b,a);
      }
      else
      {
        if(a.x<b.x)print(a,b);
        else print(b,a);
      }
    }
  }
  return 0;
}