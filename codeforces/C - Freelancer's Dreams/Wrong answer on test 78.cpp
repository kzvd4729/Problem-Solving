/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2018 14:48                        
*  solution_verdict: Wrong answer on test 78                 language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 1600 KB                              
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
double ternary(int i,int j)
{
  double lo=0,hi=1e6,md1,md2,t1,t2;
  int loop=75;
  while(loop--)
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
  int pt=id;
  for(int i=1;i<id;i++)
  {
    while(pt>0)
    {
      double t1=ternary(i,pt);
      double t2=ternary(i,pt-1);
      ans=min(ans,min(t1,t2));
       if(t2<=t1)pt--;
      else break;
    }
    if(pt<i)break;
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