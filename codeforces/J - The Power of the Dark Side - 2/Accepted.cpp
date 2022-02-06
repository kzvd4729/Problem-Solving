/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/12/2019 18:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 37500 KB                             
*  problem: https://codeforces.com/gym/102215/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long aa[N+2],bb[N+2],cc[N+2],mn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;vector<long>v;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i]>>bb[i]>>cc[i];
    mn[i]=min(cc[i]+aa[i],min(aa[i]+bb[i],bb[i]+cc[i]));
    v.push_back(mn[i]);
  }
  sort(v.begin(),v.end());
  for(int i=1;i<=n;i++)
  {
    long sm=aa[i]+bb[i]+cc[i];
    long ans=upper_bound(v.begin(),v.end(),sm-2)-v.begin();
    if(mn[i]<=sm-2)ans--;
     cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}