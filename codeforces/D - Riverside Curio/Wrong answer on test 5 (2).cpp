/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 18:10                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/957/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[100005],now,d,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  now=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i]==now)now++;
    else if(arr[i]<now)ans+=now-arr[i]-1;
    else
    {
      d=arr[i]-now;
      ans+=(d*(d+1))/2;
      now=arr[i]+1;
    }
  }
  cout<<ans<<endl;
  return 0;
}