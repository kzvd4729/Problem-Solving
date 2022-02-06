/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 19:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1209/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ans,aa[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    ans++;
    for(int j=i;j<=n;j++)
    {
      if(aa[j]%aa[i]==0)vis[j]=1;
    }
  }
  cout<<ans<<endl;
  return 0;
}