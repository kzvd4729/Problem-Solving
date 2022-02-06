/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2018 22:08                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 1622 ms                                         memory_used: 6500 KB                              
*  problem: https://codeforces.com/contest/954/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double eps=0.00001;
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
  for(int i=1;i<=n;i++)
  {
     if(tx+eps<=0)now=0;
    else now=txt/tx;
     double lo=0,hi=arr[i].x,md1,md2,tmp,tmp1,tmp2;
    for(int j=1;j<=50;j++)
    {
      md1=(lo+lo+hi)/3.0;
      md2=(lo+hi+hi)/3.0;
       if(tx-md1-eps<=0)tmp1=0;
      else tmp1=(txt-md1*arr[i].t)/(tx-md1);
       if(tx-md2-eps<=0)tmp2=0;
      else tmp2=(txt-md2*arr[i].t)/(tx-md2);
       int inc;
      if(tmp2>=tmp1)inc=1;
      else inc=0;
       if(inc)
      {
        if(tr>tmp1)lo=md1;
        else hi=md2;
      }
      else
      {
        if(tr>tmp1)hi=md2;
        else lo=md1;
      }
    }
    tmp=(txt-md1*arr[i].t)/(tx-md1);
    if(fabs(tmp-tr)<=eps)
    {
      cout<<setprecision(10)<<fixed<<(tx-lo)<<endl;
      return 0;
    }
    txt-=(arr[i].x*arr[i].t);
    tx-=arr[i].x;
  }
  cout<<0<<endl;
  return 0;
}