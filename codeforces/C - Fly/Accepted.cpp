/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2018 15:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1011/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n;
double pay,a[N+2],b[N+2];
bool ok(double xx)
{
  xx-=((pay+xx)/a[1]);
  if(xx<0.0)return false;
  for(int i=2;i<=n;i++)
  {
    xx-=((pay+xx)/b[i]);
    if(xx<0.0)return false;
    xx-=((pay+xx)/a[i]);
    if(xx<0.0)return false;
  }
  xx-=((pay+xx)/b[1]);
  if(xx<0.0)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>pay;
   for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
    cin>>b[i];
   double lo=0.0,hi=1000000000.0+100.0,md;
   for(int i=1;i<=100;i++)
  {
    md=(lo+hi)/2.0;
    if(ok(md))hi=md;
    else lo=md;
  }
  if(md>1000000000.0)cout<<-1<<endl;
  else cout<<setprecision(10)<<fixed<<md<<endl;
  return 0;
}