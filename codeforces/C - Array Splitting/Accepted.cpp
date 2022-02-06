/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2019 16:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 7000 KB                              
*  problem: https://codeforces.com/contest/1197/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  vector<int>v;long ans=0;
  for(int i=2;i<=n;i++)
  {
    v.push_back(aa[i]-aa[i-1]);
    ans+=v.back();
  }
  sort(v.begin(),v.end());
  while(m>1)
  {
    ans-=v.back();v.pop_back();
    m--;
  }
  cout<<ans<<endl;
  return 0;
}