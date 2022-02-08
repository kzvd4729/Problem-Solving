/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2018 17:24:26                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.51 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/APRIL18A/problems/HIGHWAYC
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const long double inf=1e12;
const long double eps=1e-6;
long long t,n,d[12];
long double v[12],p[12],c[12],s,y,in[12],out[12],dis,tmp,ttm;
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
          else in[i]=(dis*1.0)/v[i];
          dis=0.0-p[i]+c[i];
          out[i]=(dis*1.0)/v[i];
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
          else in[i]=(dis*1.0)/v[i];
          dis=p[i]+c[i];
          out[i]=(dis*1.0)/v[i];
        }
      }
    }
    ttm=0.0;
    for(int i=1;i<=n;i++)
    {
      if(ttm>out[i]||(ttm+tmp)<in[i])ttm+=tmp;
      else ttm=out[i]+tmp+(eps/v[i]);
    }
    cout<<setprecision(10)<<fixed<<ttm<<endl;
  }
  return 0;
}