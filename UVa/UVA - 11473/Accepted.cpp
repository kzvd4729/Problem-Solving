/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-11 23:14:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11473
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e9;
const double eps=0.00000001;
long t,tc,n,k;
struct point
{
    double x, y;
}p[102];
double dis(point p1,point p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--)
    {
      cin>>n>>k;
      for(long i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
      double tt=0,pr;
      for(long i=1;i<n;i++)tt+=dis(p[i],p[i+1]);
      pr=tt/(k-1);

      cout<<"Road #"<<++tc<<":"<<endl;
      cout<<setprecision(2)<<fixed;
      cout<<p[1].x<<" "<<p[1].y<<endl;
      point prev=p[1];
      double tmp=pr;
      for(long i=2;i<=n;i++)
      {
        double xx=dis(prev,p[i]);
        if(xx+eps>=tmp)
        {
          point pp;
          pp.x=prev.x+((p[i].x-prev.x)*tmp)/xx;
          pp.y=prev.y+((p[i].y-prev.y)*tmp)/xx;
          cout<<pp.x<<" "<<pp.y<<endl;
          prev=pp;
          tmp=pr;
          i--;
        }
        else
        {
          tmp-=xx;
          prev=p[i];
        }
      }
      cout<<endl;
    }
    return 0;
}