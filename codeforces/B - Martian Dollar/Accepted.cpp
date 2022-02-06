/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 23:09                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/41/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int R=1e9;
const int N=2e3;
int n,m,mx[N+2],arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=n;i>=1;i--)
    mx[i]=max(arr[i],mx[i+1]);
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    int num=m/arr[i];
    int mod=m%arr[i];
    ans=max(ans,num*mx[i]+mod);
  }
  cout<<ans<<endl;
  return 0;
}