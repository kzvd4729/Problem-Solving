/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 18:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1250/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cnt[N+2],k;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;int mx=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;cnt[x]++;
    mx=max(mx,cnt[x]);
  }
  long ans=1LL*mx*k;
  sort(cnt+1,cnt+k+1);
//  for(int i=1;i<=k;i++)
//    cout<<cnt[i]<<" ";
//  cout<<endl;
//  cout<<ans<<endl;
  for(int i=1;i<=k/2;i++)
  {
    int now=mx;int pt=i+i;
    for(int j=1;j<=i;j++)
      now=max(now,cnt[j]+cnt[pt--]);
    ans=min(ans,1LL*now*(k-i));
  }
  cout<<ans<<endl;
  return 0;
}