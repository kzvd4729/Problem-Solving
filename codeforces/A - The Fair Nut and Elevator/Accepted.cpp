/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2018 22:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1084/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n;
int ret(int x)
{
  int sum=0;
  for(int i=1;i<=n;i++)
  {
    sum+=aa[i]*(i-1+abs(x-i)+x-1);
  }
  return sum*2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int ans=1e9;
  for(int i=1;i<=n;i++)
    ans=min(ans,ret(i));
  cout<<ans<<endl;
   return 0;
}