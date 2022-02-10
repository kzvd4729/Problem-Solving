/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-08 23:03:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 4.5                             
*  problem: https://vjudge.net/problem/SPOJ-SICRANO
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;

struct point
{
  long x,y;
  point(){};point(long _x,long _y):x(_x),y(_y){}
  point operator+(point p){return point(x+p.x,y+p.y);}
  point operator-(point p){return point(x-p.x,y-p.y);}
  point operator*(long d){return point(x*d,y*d);}
  point operator/(long d){return point(x/d,y/d);}

  long operator^(point p)
  {
    return x*p.y-y*p.x;//0 if two vectors are same
    //signed area of the parallelogram by two vector
    //positive if p is ccw to the vector
  }
};
struct line
{
  point p,v;//v is vector,going through p;
  line(){}
  line(point _p,point _v):p(_p),v(_v){}
  void makeLine(point p1,point p2){p=p1,v=p2-p1;}
  bool onLine(point p1)
  {
    if((v^(p1-p))!=0)return false;//area of triangle has to be 0
    return true;
  }
};
struct segment
{
  point a,b;
  segment(){};
  segment(point _a,point _b):a(_a),b(_b){}
  bool onLine(point p)
  {
    line l;l.makeLine(a,b);
    if(!l.onLine(p))return false;
    if(p.x>=min(a.x,b.x)&&p.x<=max(a.x,b.x)&&p.y>=min(a.y,b.y)&&p.y<=max(a.y,b.y))
      return true;//precision 
    return false;
  }
};
point p[N+2];segment sg[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,m;cin>>n>>m;
    for(long i=1;i<=n;i++)cin>>p[i].x>>p[i].y;

    for(long i=1;i<=m;i++)
    {
      cin>>sg[i].a.x>>sg[i].a.y>>sg[i].b.x>>sg[i].b.y;
      int cnt=0;
      for(int j=1;j<=n;j++)
        if(sg[i].onLine(p[j]))cnt++;
      cout<<cnt<<endl;
    }
  }
  return 0;
}