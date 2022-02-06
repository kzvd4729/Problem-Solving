/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2019 18:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 12100 KB                             
*  problem: https://codeforces.com/contest/702/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  vector<int>v(m);
  for(int i=0;i<m;i++)cin>>v[i];
  sort(v.begin(),v.end());int mx=0;
  for(int i=1;i<=n;i++)
  {
    int mn=2e9;
    int id=lower_bound(v.begin(),v.end(),aa[i])-v.begin();
    if(id<v.size())mn=abs(aa[i]-v[id]);
    id--;if(id>=0)mn=min(mn,abs(aa[i]-v[id]));
    mx=max(mx,mn);
  }
  cout<<mx<<endl;
  return 0;
}