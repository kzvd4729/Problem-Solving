/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 00:33:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 32                                         memory_used (MB): 0.7                             
*  problem: https://vjudge.net/problem/POJ-1106
****************************************************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-12;
const double pi=acos(-1.0);
struct point
{
  double x,y;
  point(){}
  point(double _x,double _y){x=_x,y=_y;}
  point operator+(point p){return {x+p.x,y+p.y};}
  point operator-(point p){return {x-p.x,y-p.y};}
  double valsq(){return x*x+y*y;}
  double val(){return sqrt(valsq());}
}pt[N+2];
double radtodeg(double r){return r*180.0/pi;}
double degtored(double d){return d*pi/180.0;}
int sgn(double d)
{
  if(fabs(d)<=eps)return 0;
  return d<0.0?-1:1;
}
double modiatan2(point p)
{
  double ang=atan2(p.y,p.x);
  if(ang<0)ang+=pi+pi;
  return radtodeg(ang);
}
bool cmp(point a,point b)
{
  return modiatan2(a)<modiatan2(b);
}
int aa[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  point c;double r;
  while(true)
  {
    cin>>c.x>>c.y>>r;
    if(sgn(r)==-1)break;
    int n;cin>>n;int id=0;
    for(int i=1;i<=n;i++)
    {
      point p;cin>>p.x>>p.y;
      if((p-c).val()<=r)pt[++id]=p-c;
    }
    if(!id)
    {
      cout<<0<<endl;continue;
    }
    sort(pt+1,pt+id+1,cmp);
    for(int i=1;i<=id;i++)
    {
      aa[i]=modiatan2(pt[i]);
      aa[id+i]=360.0+aa[i];
    }
    int ans=0;
    for(int i=1;i<=id;i++)
    {
      int lo=i,hi=id+id,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(aa[md]-aa[i]<=180.0)lo=md;
        else hi=md;
      }
      for(md=hi;md>=lo;md--)
        if(aa[md]-aa[i]<=180.0)break;
      ans=max(ans,md-i+1);
    }
    cout<<ans<<endl;
  }
  return 0;
}