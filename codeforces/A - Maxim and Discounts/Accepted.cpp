/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 15:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 154 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/261/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>m;int mn=1e9;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;mn=min(mn,x);
  }
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1,greater<int>());
  long ans=0;
  for(int i=1;i<=n;i+=mn+2)
  {
    for(int j=i;j<=min(n,i+mn-1);j++)
      ans+=aa[j]*1LL;
  }
  cout<<ans<<endl;
  return 0;
}