/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2020 12:39                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/67/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
 #define setp(a) cout<<setprecision(a)<<fixed
const double eps=1e-9;
int sgn(double x)
{
  if(fabs(x)<=eps)return 0;
  return x>0?1:-1;
}
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
    //care for parallel lines???
    double t=(l.v^(p-l.p))/(v^l.v);
    return p+v*t;
  }
};
vector<point>halfPlaneIntersection(vector<line>&l)
{
  //lines are anti-clockwise
  int n=l.size();sort(l.begin(),l.end());
  int first=0,last=0;vector<point>poly;
  vector<point>p(n);vector<line>q(n);
  q[first]=l[0];
  for(int i=1;i<n;i++)
  {
    while(first<last&&(l[i].v^(p[last-1]-l[i].p))<=eps)last--;//<-eps
    while(first<last&&(l[i].v^(p[first]-l[i].p))<=eps)first++;//<-eps
    q[++last]=l[i];
    if(sgn(q[last].v^q[last-1].v)==0)
    {
      last--;
      if((q[last].v^(l[i].p-q[last].p))>eps)q[last]=l[i];//>=-eps
    }
    if(first<last)p[last-1]=q[last-1].intersection(q[last]);
  }
  while(first<last&&(q[first].v^(p[last-1]-q[first].p))<=eps)//<-eps
    last--;
  if(last-first<=1)return poly;
  p[last]=q[last].intersection(q[first]);
  for(int i=first;i<=last;i++)poly.push_back(p[i]);
  return poly;//ccw path
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<point>v(n);
  for(int i=0;i<n;i++)cin>>v[i].x>>v[i].y;
   int y=v[0].y,x1=v[0].x,x2=v[1].x;
   vector<line>l;
  for(int i=n-1;i>0;i--)
  {
    line x(v[i],v[i-1]);l.push_back(x);
  }
  line x(v[0],v[n-1]);l.push_back(x);
   v=halfPlaneIntersection(l);
   setp(3);
  //for(auto x:v)cout<<x.x<<" "<<x.y<<endl;
  v.push_back(v[0]);
  double ad=0.0000001;int ans=0;
  for(int i=0;i<(int)v.size()-1;i++)
  {
    //cout<<v[i].x<<" "<<v[i].y<<endl;
    if(floor(v[i].y+ad)==y&&floor(v[i+1].y+ad)==y)
    {
      x1=max(x1,(int)ceil(v[i+1].x-ad));
      x2=min(x2,(int)floor(v[i].x+ad));
      cout<<x2-x1+1<<endl,exit(0);
       //cout<<v[i+1].x<<" "<<v[i].x<<endl;
    }
  }
  for(auto x:v)if(floor(x.y+ad)==y)cout<<1<<endl,exit(0);
  cout<<0<<endl;
  return 0;
}