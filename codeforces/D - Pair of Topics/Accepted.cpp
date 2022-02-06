/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/12/2020 19:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/1324/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
   for(int i=1;i<=n;i++)cin>>aa[i];vector<int>v;
  for(int i=1;i<=n;i++)
  {
    cin>>bb[i];v.push_back(aa[i]-bb[i]);
  }
  sort(v.begin(),v.end());long ans=0;
  for(int i=1;i<=n;i++)
  {
    int d=aa[i]-bb[i];
    int id=upper_bound(v.begin(),v.end(),-d)-v.begin();
    ans+=n-id;if(d>0)ans--;
  }
  cout<<ans/2<<endl;
  return 0;
}