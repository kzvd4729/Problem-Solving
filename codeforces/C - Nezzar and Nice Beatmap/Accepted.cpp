/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2021 16:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/1477/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
 const double eps=1e-9,pi=acos(-1.0);
int sgn(double d)
{
  if(fabs(d)<eps)return 0;return d<0.0?-1:1;
}
struct point
{
  double x,y;
  point(){};point(double _x,double _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(double d){return point(x*d,y*d);}
  point operator/(double d){return point(x/d,y/d);}
  bool operator==(point p){return x==p.x&&y==p.y;}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  double value(){return sqrt(x*x+y*y);}
  double dist(point p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
  point unitVector()
  {
    //invalid if vector is (0,0)
    double v=value();return point(x/v,y/v);
  }
  double operator*(point p)
  {
    return x*p.x+y*p.y;//0 if vectors are perpendicular;
  }
  double operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
  point rotateCCW(double a)//radian
  {
    return point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
  }
  point rotateCCW90(){return point(-y,x);}
  point rotateCCW180(){return point(-x,-y);}
  point rotateCCW270(){return point(y,-x);}
};
double radToDeg(double r){return r*180.0/pi;}
double degToRed(double d){return d*pi/180.0;}
double modifiedatan2(point p)//counter-clockwise full angle with positive x axis
{
  double ang=atan2(p.y,p.x);if(ang<0)ang+=pi+pi;//carefull
  return radToDeg(ang);//deg return 
}
 bool ck(point a,point b,point c)
{
  a=a-b,b=c-b;
  double ang=acos(a*b/(a.value()*b.value()));
   return radToDeg(ang)<90.0-eps;
}
point p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v={1,2};
   for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
   for(int i=3;i<=n;i++)
  {
    int g=0;
    for(int j=i-1;j>=0;j--)
    {
      bool f1=0,f2=0,f3=0;
       if(j-2<0)f1=1;
      else f1=ck(p[v[j-2]],p[v[j-1]],p[i]);
       if(j-1<0||j>=(int)(v.size()))f2=1;
      else f2=ck(p[v[j-1]],p[i],p[v[j]]);
       if(j+1>=(int)v.size())f3=1;
      else f3=ck(p[i],p[v[j]],p[v[j+1]]);
        if(f1&&f2&&f3)
      {
        g=1;
        v.insert(v.begin()+j,i);
        break;
      }
    }
    if(g==0)assert(0);
  }
  for(auto x:v)cout<<x<<" ";cout<<endl;
   return 0;
}