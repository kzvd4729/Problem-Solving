/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-27 23:47:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-477
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-9;
int ty[N+2];
struct point
{
  double x,y;
}p1[20],p2[20];
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
    else
    {
      ty[id]=2;
      cin>>p1[id].x>>p1[id].y>>p2[id].x;
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
      else
      {
        if(dist(a,p1[i])<p2[i].x)
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