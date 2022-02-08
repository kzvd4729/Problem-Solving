/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-07 20:02:37                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 5 ms                                            memory_used: 768 KB                               
*  problem: https://atcoder.jp/contests/arc094/tasks/arc094_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans,mn=2e9;
struct data
{
  long a,b,d;
}arr[200005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].a>>arr[i].b;
    arr[i].d=arr[i].a-arr[i].b;
    ans+=arr[i].a;
    if(arr[i].d>0)mn=min(arr[i].b,mn);
  }
  long bn=0,sum=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i].d<0)
    {
      bn-=arr[i].d;
      sum+=arr[i].a;
    }
  }
  if(bn==0)cout<<sum<<endl,exit(0);
  else cout<<ans-mn<<endl;
   return 0;
}