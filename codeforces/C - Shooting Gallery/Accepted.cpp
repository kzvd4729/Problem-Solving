/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2018 23:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/30/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n;
double dp[N+2];
struct data
{
  double x,y,p;
  int t;
}arr[N+2];
bool cmp(data A,data B)
{
  return A.t<B.t;
}
long dis(data A,data B)
{
  return (A.x-B.x)*1LL*(A.x-B.x)+(A.y-B.y)*1LL*(A.y-B.y);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i].x>>arr[i].y>>arr[i].t>>arr[i].p;
  sort(arr+1,arr+n+1,cmp);
   for(int i=1;i<=n;i++)dp[i]=arr[i].p;
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if(dis(arr[i],arr[j])<=(arr[j].t-arr[i].t)*1LL*(arr[j].t-arr[i].t))
        dp[j]=max(dp[j],dp[i]+arr[j].p);
  double ans=0;
  for(int i=1;i<=n;i++)
    ans=max(ans,dp[i]);
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}