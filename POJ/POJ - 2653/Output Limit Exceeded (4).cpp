/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-21 22:25:03                      
*  solution_verdict: Output Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2653
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const double eps=1e-9;
int sgn(double x)
{
  return x>eps?1:x<eps?-1:0;
}
struct point
{
  double x,y;
  point(double _x=0,double _y=0){x=_x,y=_y;}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  double operator*(const point &p){return x*p.x+y*p.y;}
  double operator^(const point &p){return x*p.y-y*p.x;}
};
struct segment
{
  point s,e;
  segment(){}
  segment(point _s,point _e){s=_s,e=_e;}
  void set(point _s,point _e){s=_s,e=_e;}
  void input(){scanf("%f%lf%lf%lf",&s.x,&s.y,&e.x,&e.y);}
  void output()
  {cout<<s.x<<" "<<s.y<<" ----> "<<e.x<<" "<<e.y<<endl;}
  bool inRectangle(point p)
  {
    int minx=min(s.x,e.x),maxx=max(s.x,e.x);
    int miny=min(s.y,e.y),maxy=max(s.y,e.y);
    return p.x>=minx&&p.x<=maxx&&p.y>=miny&&p.y<=maxy;
  }
  int segmentIntersect(segment sg,point &r)
  {
    int s1,s2,s3,s4;
    int d1=sgn(s1=(e-s)^(sg.s-s));
    int d2=sgn(s2=(e-s)^(sg.e-s));
    int d3=sgn(s3=(sg.e-sg.s)^(s-sg.s));
    int d4=sgn(s4=(sg.e-sg.s)^(e-sg.s));
    if((d1^d2)==-2&&(d3^d4)==-2)
    {
      r.x=sg.s.x*s2-sg.e.x*s1/(s2-s1);
      r.y=sg.s.y*s2-sg.e.y*s1/(s2-s1);
      return 1;
    }
    else if(d1==0&&sgn((s-sg.s)*(e-sg.s))<=0){r=sg.s;return 2;}
    else if(d2==0&&sgn((s-sg.e)*(e-sg.e))<=0){r=sg.e;return 2;}
    else if(d3==0&&sgn((sg.s-s)*(sg.e-s))<=0){r=s;return 2;}
    else if(d4==0&&sgn((sg.s-e)*(sg.e-e))<=0){r=e;return 2;}
    return 0;
  }
};
int main()
{
  int n;
  while(cin>>n)
  {
    if(!n)break;vector<segment>sg(n);vector<bool>vis(n,0);
    point p;
    for(int i=0;i<n;i++)
      sg[i].input();
    for(int i=n-1;i>=0;i--)
    {
      if(vis[i])continue;
      for(int j=0;j<i;j++)
      {
        if(sg[i].segmentIntersect(sg[j],p))
        {
          vis[j]=1;break;
        }
      }
    }
    printf("Top sticks: ");int f=0;
    for(int i=0;i<n;i++)
    {
      if(!vis[i])
      {
        if(!f)printf("%d",i+1),f=1;
        else printf(", %d",i+1);
      }
    }
    printf(".\n");
  }
  return 0;
}