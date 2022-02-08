/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2018 17:08:41                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.28 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/APRIL18A/problems/HIGHWAYC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double inf=1e12;
long t,n;
double v[12],d[12],p[12],c[12],s,y,in[12],out[12],dis,tmp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>s>>y;
        tmp=(y*1.0)/s;
        for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)
    {
      if(d[i])
      {
        if(p[i]-c[i]>=0.0)
        {
          in[i]=inf;
          out[i]=inf;
        }
        else
        {
          dis=0.0-p[i];
          if(dis<=0.0)in[i]=0.0;
          else in[i]=dis/v[i];
          dis=0.0-p[i]+c[i];
          out[i]=dis/v[i];
        }
      }
      else
      {
        if(p[i]+c[i]<=0)
        {
          in[i]=inf;
          out[i]=inf;
        }
        else
        {
          dis=p[i];
          if(dis<=0)in[i]=0.0;
          else in[i]=dis/v[i];
          dis=p[i]+c[i];
          out[i]=dis/v[i];
        }
      }
    }
    //for(int i=1;i<=n;i++)cout<<in[i]<<" "<<out[i]<<endl;
    double ttm=0.0;
    for(int i=1;i<=n;i++)
    {
      if(ttm>out[i]||ttm+tmp<in[i])ttm+=tmp;
      else ttm=out[i]+tmp;
    }
    cout<<setprecision(3)<<fixed<<ttm<<endl;
  }
  return 0;
}