/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/13/2020 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1301/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int f=0;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];if(aa[i]!=-1)f=1;
    }
    if(!f)
    {
      cout<<0<<" "<<0<<"\n";continue;
    }
    aa[0]=0,aa[n+1]=0;int mn=1e9,mx=0;
    for(int i=1;i<=n;i++)
    {
      if(aa[i]!=-1&&(aa[i-1]==-1||aa[i+1]==-1))
      {
        mn=min(mn,aa[i]);
        mx=max(mx,aa[i]);
      }
    }
    int md=(mn+mx)/2;
    int ans=0;
    for(int i=1;i<=n;i++)if(aa[i]==-1)aa[i]=md;
    for(int i=2;i<=n;i++)ans=max(ans,abs(aa[i]-aa[i-1]));
    cout<<ans<<" "<<md<<"\n";
  }
  return 0;
}