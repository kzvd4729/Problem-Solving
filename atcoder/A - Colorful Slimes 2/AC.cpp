/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-14 18:18:40                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc026/tasks/agc026_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[10002],ans,cnt;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  arr[++n]=-1;
  for(int i=1;i<=n;i++)
  {
    if(arr[i]==arr[i-1])
      cnt++;
    else
    {
      ans+=(cnt/2);
      cnt=1;
    }
  }
  cout<<ans<<endl;
  return 0;
}