/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2018 15:07                        
*  solution_verdict: Time limit exceeded on test 86          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/605/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int id,p,q;
double ans;
pair<int,int>aa[N+2],bb[N+2];
void take_one(void)
{
  ans=1e9;
  for(int i=1;i<=id;i++)
    ans=min(ans,max((p*1.0)/(aa[i].first*1.0),(q*1.0)/(aa[i].second*1.0)));
}
inline double ternary(int i,int j)
{
  double lo=0,hi=5e5,md1,md2,t1,t2;
  while(hi-lo>0.000001)
  {
    md1=(lo+lo+hi)/3.0;
    md2=(lo+hi+hi)/3.0;
     t1=max(max(0*1.0,(p*1.0-(aa[i].first*md1)))/(aa[j].first*1.0),max(0*1.0,(q*1.0-(aa[i].second*md1)))/(aa[j].second*1.0));
    t2=max(max(0*1.0,(p*1.0-(aa[i].first*md2)))/(aa[j].first*1.0),max(0*1.0,(q*1.0-(aa[i].second*md2)))/(aa[j].second*1.0));
     if(t1+md1<=t2+md2)hi=md2;
    else lo=md1;
  }
  return md1+t1;
}
void take_two(void)
{
  for(int i=1;i<id;i++)
  {
    int lo=i+1,hi=id,md1,md2;
    while(hi-lo>3)
    {
      md1=(lo+lo+hi)/3;
      md2=(lo+hi+hi+2)/3;
      double t1=ternary(i,md1);
      double t2=ternary(i,md2);
      ans=min(ans,min(t1,t2));
       if(t1<=t2)hi=md2;
      else lo=md1;
    }
    for(int md=lo;md<=hi;md++)
      ans=min(ans,ternary(i,md));
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n>>p>>q;
  for(int i=1;i<=n;i++)
    cin>>bb[i].first>>bb[i].second;
  sort(bb+1,bb+n+1);
  for(int i=1;i<=n;i++)
  {
    while(id>0&&aa[id].second<=bb[i].second)
      id--;
    aa[++id]=bb[i];
  }
   take_one();take_two();
  cout<<setprecision(10)<<fixed<<ans<<endl;
   return 0;
}