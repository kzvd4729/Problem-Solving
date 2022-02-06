/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 19:19                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 78 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/716/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,arr[N+2],ans,c;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>c;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  arr[n+1]=arr[n];
  for(int i=n+1;i>1;i--)
  {
    if(arr[i]-arr[i-1]<=c)ans++;
    else break;
  }
  cout<<ans<<endl;
  return 0;
}