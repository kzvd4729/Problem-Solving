/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-21 14:33:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 203                                        memory_used (MB): 2.6                             
*  problem: https://vjudge.net/problem/LightOJ-1346
****************************************************************************************/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<stack>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=2e4;
const int inf=1e8;
int t,n,tc;
double xx;
struct point
{
  double x,y;
}pt[N+2];
struct equation
{
  double a,b,c;
};
int cross(point a,point b,point c)
{
  b.x-=a.x;
  b.y-=a.y;
  c.x-=a.x;
  c.y-=a.y;
  return b.x*c.y-c.x*b.y;
}
equation make_equation(point p1,point p2)
{
  equation eq;
  eq.a=p1.y-p2.y;
  eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  //ax+by=c;
  return eq;
}
point intersection(equation e1,equation e2)
{
  point ret;
  double det=e1.a*e2.b-e1.b*e2.a;
  double dx=e1.c*e2.b-e1.b*e2.c;
  double dy=e1.a*e2.c-e1.c*e2.a;
  ret.x=dx/det;ret.y=dy/det;
  return ret;
}
double dis(point a,point b)
{
  double t1=(a.x-b.x)*(a.x-b.x);
  double t2=(a.y-b.y)*(a.y-b.y);
  return sqrt(t1+t2);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>xx;
    for(int i=1;i<=n;i++)
      cin>>pt[i].x>>pt[i].y;
    point p={xx,0},cur=pt[1];
    double sum=0;
    for(int i=2;i<=n;i++)
    {
      int tmp=cross(p,cur,pt[i]);
      if(tmp<0)continue;
      if(tmp==0)
      {
        cur=pt[i];
        continue;
      }
      equation e1=make_equation(p,cur);
      equation e2=make_equation(pt[i],pt[i-1]);
      point z=intersection(e1,e2);
      sum+=dis(z,pt[i]);
      cur=pt[i];
    }
    cout<<"Case "<<++tc<<": "<<setprecision(10)<<fixed<<sum<<endl;
  }
  return 0;
}