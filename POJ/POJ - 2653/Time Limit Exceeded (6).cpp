/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 15:11:40                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2653
****************************************************************************************/
#include<iostream>
#include<cmath>
#define long long long
using namespace std;
const int N=1e5;
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
}p1[N+2],p2[N+2];
int sgn(double x)
{
  if(fabs(x)<=eps)return 0;
  return x>0?1:-1;
}
bool inrec(point p,point a,point b)
{
  double x1,x2,y1,y2;
  x1=min(a.x,b.x);x2=max(a.x,b.x);
  y1=min(a.y,b.y);y2=max(a.y,b.y);
  return p.x>=x1&&p.x<=x2&&p.y>=y1&&p.y<=y2;
}
bool segmentintersect(point a,point b,point c,point d)
{
  int o1=sgn((b-a)^(c-a)),o2=sgn((b-a)^(d-a));
  int o3=sgn((d-c)^(a-c)),o4=sgn((d-c)^(b-c));
  if(o1*o2==-1&&o3*o4==-1)return true;
  if(o1==0&&inrec(c,a,b))return true;
  if(o2==0&&inrec(d,a,b))return true;
  if(o3==0&&inrec(a,c,d))return true;
  if(o4==0&&inrec(b,c,d))return true;
  return false;
}
int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(true)
  {
    int n;cin>>n;if(!n)break;
    for(int i=1;i<=n;i++)
    {
      cin>>p1[i].x>>p1[i].y>>p2[i].x>>p2[i].y;
      vis[i]=0;
    }
    //cout<<segmentintersect(p1[1],p2[1],p1[2],p2[2])<<endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(segmentintersect(p1[i],p2[i],p1[j],p2[j]))
        {
          vis[i]=1;break;
        }
      }
    }
    cout<<"Top sticks: ";int f=0;
    for(int i=1;i<=n;i++)
    {
      if(!vis[i])
      {
        if(!f)cout<<i,f=1;
        else cout<<", "<<i;
      }
    }
    cout<<"."<<endl;
  }
  return 0;
}