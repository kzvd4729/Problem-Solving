/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2019 02:34                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1156/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  int ans=0,p=1;
  for(int i=1;i<=n;i++)
  {
    if(p>n)break;if(vis[i])p++;
    while(true)
    {
      if(p>n)break;
      if(aa[p]-aa[i]>=k)
      {
        ans++;vis[p]=1;p++;
        break;
      }
      p++;
    }
  }
  cout<<ans<<endl;
  return 0;
}