/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2018 23:02                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/954/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n;
long double txt,tx,tr,lo,hi,md,ans;
struct data
{
  long double x,t;
}arr[200005];
bool cmp(data A,data B)
{
  return A.t<B.t;
}
bool cmp2(data A,data B)
{
  return A.t>B.t;
}
long double check(long double xx)
{
  long double str=xx,sum=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i].x<=xx)
    {
      sum+=(arr[i].t*arr[i].x);
      xx-=arr[i].x;
    }
    else
    {
      sum+=(arr[i].t*xx);
      xx=0;
      break;
    }
  }
  return sum/str;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>tr;
  for(int i=1;i<=n;i++)cin>>arr[i].x;
  for(int i=1;i<=n;i++)cin>>arr[i].t;
  for(int i=1;i<=n;i++)
  {
    tx+=arr[i].x;
    txt+=(arr[i].x*arr[i].t);
  }
  sort(arr+1,arr+n+1,cmp);
  lo=0,hi=tx;
  for(int j=1;j<=60;j++)
  {
    md=(lo+hi)/2.0;
    if(check(md)<=tr)lo=md;
    else hi=md;
  }
  ans=md;
  sort(arr+1,arr+n+1,cmp2);
  lo=0,hi=tx;
  for(int j=1;j<=60;j++)
  {
    md=(lo+hi)/2.0;
    if(check(md)<=tr)lo=md;
    else hi=md;
  }
  ans=min(ans,md);
  cout<<setprecision(12)<<fixed<<ans<<endl;
  return 0;
}