/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-28 00:01:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-478
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-6;
int ty[N+2];
struct point
{
  double x,y;
}p1[20],p2[20],p3[20];
bool in_rec(point a,point b,point c)
{
  double mnx=min(b.x,c.x),mxx=max(b.x,c.x);
  double mny=min(b.y,c.y),mxy=max(b.y,c.y);
  return a.x>mnx&&a.x<mxx&&a.y>mny&&a.y<mxy;
}
double dist(point p1,point p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double area(point a,point b,point c)
{
  double ab=dist(a,b),bc=dist(b,c),ca=dist(c,a);
  double s=(ab+bc+ca)/2.0;
  return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int id=0;
  while(true)
  {
    char c;cin>>c;if(c=='*')break;id++;
    if(c=='r')
    {
      ty[id]=1;
      cin>>p1[id].x>>p1[id].y>>p2[id].x>>p2[id].y;
    }
    else if(c=='c')
    {
      ty[id]=2;
      cin>>p1[id].x>>p1[id].y>>p2[id].x;
    }
    else
    {
      ty[id]=3;
      cin>>p1[id].x>>p1[id].y>>p2[id].x>>p2[id].y>>p3[id].x>>p3[id].y;
    }
  }
  int nw=1;
  while(true)
  {
    point a;cin>>a.x>>a.y;int f=0;
    if(fabs(a.x-9999.9)<=eps&&fabs(a.y-9999.9)<=eps)
      break;
    for(int i=1;i<=id;i++)
    {
      if(ty[i]==1)
      {
        if(in_rec(a,p1[i],p2[i]))
        {
          cout<<"Point "<<nw<<" is contained in figure "<<i<<endl;
          f=1;
        }
      }
      else if(ty[i]==2)
      {
        if(dist(a,p1[i])<p2[i].x)
        {
          cout<<"Point "<<nw<<" is contained in figure "<<i<<endl;
          f=1;
        }
      }
      else
      {
        double ar=area(p1[i],p2[i],p3[i]);
        double ab=area(a,p1[i],p2[i]);
        double bc=area(a,p2[i],p3[i]);
        double ca=area(a,p3[i],p1[i]);
        int bad=0;
        if(fabs(ab)<=eps)bad=1;
        if(fabs(bc)<=eps)bad=1;
        if(fabs(ca)<=eps)bad=1;

        if(fabs(ab+bc+ca-ar)<=eps&&!bad)
        {
          cout<<"Point "<<nw<<" is contained in figure "<<i<<endl;
          f=1;
        }
      }
    }
    if(!f)cout<<"Point "<<nw<<" is not contained in any figure"<<endl;
    nw++;
  }
  return 0;
}