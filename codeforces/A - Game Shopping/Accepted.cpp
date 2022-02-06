/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1009/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,arr[10004],cost[10004];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>cost[i];
  for(int i=1;i<=m;i++)
    cin>>arr[i];
   arr[m+1]=-1;
  int l=1,ans=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[l]>=cost[i])
      ans++,l++;
  }
  cout<<ans<<endl;
  return 0;
}