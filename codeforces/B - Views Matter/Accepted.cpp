/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/22/2018 22:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1061/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;long sum=0;m=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];sum+=aa[i]*1LL;
    m=max(m,aa[i]);
  }
  sort(aa+1,aa+n+1,greater<int>());
  long ans=0;int pt=m;
  for(int i=1;i<n;i++)
  {
    if(aa[i+1]<pt)
    {
      ans+=(pt-aa[i+1])*1LL;pt=aa[i+1];
    }
    else
    {
      pt--;ans++;
    }
  }
  pt=max(pt,1);
  cout<<sum-(ans+pt*1LL)<<endl;
  return 0;
}