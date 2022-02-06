/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 20:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
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
  sort(aa+1,aa+n+1);int p=1,ans=0,pt=1;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])
    {
      pt=max(pt,i+1);
      while(true)
      {
        if(pt>n)break;
        if(vis[pt]==0)break;
        pt++;
      }
      if(pt>n)break;
      vis[pt++]=1;p=max(p,pt);
    }
    while(true)
    {
      if(p>n)break;
      if(aa[p]-aa[i]>=k)break;
      p++;
    }
    if(p<=n)
      ans++,vis[p++]=1;
  }
  cout<<ans<<endl;
  return 0;
}