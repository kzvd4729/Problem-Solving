/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 16:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 28400 KB                             
*  problem: https://codeforces.com/contest/671/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define double long double
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
}aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  point a,b,t;cin>>a.x>>a.y>>b.x>>b.y>>t.x>>t.y;
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i].x>>aa[i].y;
   cout<<setprecision(10)<<fixed;
  if(n==1)cout<<t.dist(aa[1])+min(a.dist(aa[1]),b.dist(aa[1]))<<endl,exit(0);
   double d1=2e18,d2=2e18+1,i1=-1,i2=-1;
  for(int i=1;i<=n;i++)
  {
    double d=a.dist(aa[i])-t.dist(aa[i]);
    if(d<d1)
    {
      d2=d1,i2=i1;d1=d,i1=i;
    }
    else if(d<d2)
    {
      d2=d,i2=i;
    }
  }
  double d3=2e18,d4=2e18+1,i3=-1,i4=-1;
  for(int i=1;i<=n;i++)
  {
    double d=b.dist(aa[i])-t.dist(aa[i]);
    if(d<d3)
    {
      d4=d3,i4=i3;d3=d,i3=i;
    }
    else if(d<d4)
    {
      d4=d,i4=i;
    }
  }
  int j1,j2;double ans=0;
  if(i1!=i3)ans=d1+d3,j1=i1,j2=i3;
  else 
  {
    if(d1+d4<d2+d3)ans=d1+d4,j1=i1,j2=i4;
    else ans=d2+d3,j1=i2,j2=i3;
  }
  if(d1<ans)ans=d1,j1=i1,j2=-1;
  if(d3<ans)ans=d3,j1=-1,j2=i3;
  //cout<<ans<<endl;
  //cout<<j1<<" "<<j2<<endl;cout<<ans<<endl;
  for(int i=1;i<=n;i++)
  {
    //if(i==j1||i==j2)ans+=t.dist(aa[i]);
    ans+=2*t.dist(aa[i]);
  }
  cout<<ans<<endl;
  return 0;
}