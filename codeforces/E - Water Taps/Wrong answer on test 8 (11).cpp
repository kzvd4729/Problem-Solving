/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2018 20:39                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 1450 ms                                         memory_used: 6800 KB                              
*  problem: https://codeforces.com/contest/954/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double eps=0.01;
int n;
double tr,now;
struct data
{
  double x,t;
}arr[200005];
bool cmp(data A,data B)
{
  return A.t>B.t;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>tr;
  for(int i=1;i<=n;i++)cin>>arr[i].x;
  for(int i=1;i<=n;i++)cin>>arr[i].t;
  sort(arr+1,arr+n+1,cmp);
  double tx=0,txt=0;
  for(int i=1;i<=n;i++)
  {
    tx+=arr[i].x;
    txt+=(arr[i].x*arr[i].t);
  }
  now=(txt*1.00)/(tx*1.00);
  if(now+eps<tr)
  {
    cout<<setprecision(10)<<fixed<<now+eps<<endl;
    return 0;
  }
  for(int i=1;i<=n;i++)
  {
    double tmp=0;
    if(tx-arr[i].x-eps<=0)tmp=0;
    else tmp=(txt-arr[i].x*arr[i].t)/(tx-arr[i].x);
    if(tmp<=tr)
    {
      double lo=0,hi=arr[i].x,md;
      for(int j=1;j<=100;j++)
      {
        md=(lo+hi)/2;
        if(tx-md-eps<=0)tmp=0;
        else tmp=(txt-md*arr[i].t)/(tx-md);
        if(tmp<=tr)hi=md;
        else lo=md;
      }
      tx-=md;
      cout<<setprecision(10)<<fixed<<tx<<endl;
      return 0;
    }
    else
    {
      txt-=(arr[i].x*arr[i].t);
      tx-=arr[i].x;
    }
  }
  return 0;
}