/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-20 18:52:29                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 21 ms                                           memory_used: 1152 KB                              
*  problem: https://atcoder.jp/contests/agc024/tasks/agc024_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int arr[N+2],n;
long ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   if(arr[1]!=0)cout<<-1<<endl,exit(0);
  for(int i=2;i<=n;i++)
  {
    if(arr[i]==0)continue;
    if(arr[i]==arr[i-1]+1)ans++;
    else
    {
      if(arr[i]<=arr[i-1])ans+=(arr[i]*1LL);
      else cout<<-1<<endl,exit(0);
    }
  }
  cout<<ans<<endl;
  return 0;
}