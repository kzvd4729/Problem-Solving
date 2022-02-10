/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-20 19:27:47                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1410
****************************************************************************************/
#include<iostream>
using namespace std;
int sgn(int x)
{
  return x>0?1:x<0?-1:1;
}
struct point
{
  int x,y;
  point(int _x=0,int _y=0){x=_x,y=_y;}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  int operator*(const point &p){return {x*p.x+y*p.y};}
  int operator^(const point &p){return x*p.y-y*p.x;}
};
struct segment
{
  point s,e;
  segment(){}
  segment(point _s,point _e){s=_s,e=_e;}
  void input(){cin>>s.x>>s.y>>e.x>>e.y;}
  void output()
  {
    cout<<s.x<<" "<<s.y<<" ----> "<<e.x<<" "<<e.y<<endl;
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
    else if(d1==0&&sgn((s-sg.s)*(e-sg.s))<=0)
    {
      r=sg.s;return 2;
    }
    else if(d2==0&&sgn((s-sg.e)*(e-sg.e))<=0)
    {
      r=sg.e;return 2;
    }
    else if(d3==0&&sgn((sg.s-s)*(sg.e-s))<=0)
    {
      r=s;return 2;
    }
    else if(d4==0&&sgn((sg.s-e)*(sg.e-e))<=0)
    {
      r=e;return 2;
    }
    return 0;
  }
};
bool inRectangle(point a,point b,point c)
{
  int minx=min(a.x,b.x),maxx=max(a.x,b.x);
  int miny=min(a.y,b.y),maxy=max(a.y,b.y);
  return c.x>=minx&&c.x<=maxx&&c.y>=miny&&c.y<=maxy;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    segment sg;sg.input();
    int l,r,u,d;cin>>l>>u>>r>>d;point p;
    if(inRectangle({l,u},{r,d},sg.s)||inRectangle({l,u},{r,d},sg.s))
    {
      cout<<"T\n";continue;
    }
    if(sg.segmentIntersect(segment(point(l,u),point(l,d)),p))
    {
      cout<<"T\n";continue;
    }
    if(sg.segmentIntersect(segment(point(l,u),point(r,u)),p))
    {
      cout<<"T\n";continue;
    }
    if(sg.segmentIntersect(segment(point(r,d),point(l,d)),p))
    {
      cout<<"T\n";continue;
    }
    if(sg.segmentIntersect(segment(point(r,d),point(r,u)),p))
    {
      cout<<"T\n";continue;
    }
    cout<<"F\n";
  }
  return 0;
}