/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-15 18:05:58                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc027/tasks/agc027_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int arr[N+2],ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n>>x;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
  for(int i=1;i<=n;i++)
  {
    if(x>=arr[i])
      ans++,x-=arr[i];
  }
  if(ans==n&&x)ans--;
  cout<<ans<<endl;
  return 0;
}