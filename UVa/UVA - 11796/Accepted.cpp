/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-02 17:12:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 630                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11796
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;

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
}p[N+2],q[N+2];
point cal(point a,point b,double d)
{
 b=b-a;return a+((point)b.unitVector()*d);
}
double ret(point a,point b,point c,point d,double t,double v)
{
 double lo=0,hi=t,md1,md2;int loop=200;
 point p1,p2;double d1,d2;
 while(loop--)
 {
  md1=(lo+lo+hi)/3.0,md2=(lo+hi+hi)/3.0;
  p1=cal(a,b,md1),p2=cal(c,d,md1*v);
  d1=p1.dist(p2);

  p1=cal(a,b,md2),p2=cal(c,d,md2*v);
  d2=p1.dist(p2);
  if(d1<d2)hi=md2;else lo=md1;
 }
 return d1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
   int n,m;cin>>n>>m;double d1=0;
   for(int i=1;i<=n;i++)
   {
    cin>>p[i].x>>p[i].y;
    if(i>1)d1+=p[i].dist(p[i-1]);
   }
   double d2=0;
   for(int i=1;i<=m;i++)
   {
    cin>>q[i].x>>q[i].y;
    if(i>1)d2+=q[i].dist(q[i-1]);
   }
   double v=d2/d1,mn=p[1].dist(q[1]),mx=p[1].dist(q[1]);
   int i=2,j=2;point a=p[1],b=q[1];
   //cout<<mn<<" "<<mx<<endl;
   while(i<=n&&j<=m)
   {
    double t1=a.dist(p[i]);
    double t2=b.dist(q[j])/v;
    if(t1<t2)
    {
     mn=min(mn,ret(a,p[i],b,q[j],t1,v));
     a=p[i++],b=cal(b,q[j],t1*v);
    }
    else
    {
     mn=min(mn,ret(a,p[i],b,q[j],t2,v));
     a=cal(a,p[i],t2),b=q[j++];
    }
    mn=min(mn,a.dist(b)),mx=max(mx,a.dist(b));
   }
   cout<<"Case "<<++tc<<": "<<round(mx-mn)<<endl;
 }
  return 0;
}