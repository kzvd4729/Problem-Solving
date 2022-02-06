/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:31                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/301/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,aa[N+2];
int ck(void)
{
  int sum=0;
  for(int i=1;i<n+n;i++)
    sum+=aa[i];
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<n+n;i++)cin>>aa[i];
  int ans=ck();sort(aa+1,aa+n+n);
  for(int i=1;i<=n;i++)aa[i]*=-1;
    ans=max(ans,ck());
  sort(aa+1,aa+n+n);
  for(int i=1;i<=n;i++)aa[i]*=-1;
  ans=max(ans,ck());
  cout<<ans<<endl;
   return 0;
}