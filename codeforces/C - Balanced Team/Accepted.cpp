/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/07/2019 21:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/1133/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;v.push_back(x);
  }
  sort(v.begin(),v.end());
  int ans=0;
  for(int i=0;i<v.size();i++)
  {
    int id=upper_bound(v.begin(),v.end(),v[i]+5)-v.begin();
    ans=max(ans,id-i);
  }
  cout<<ans<<endl;
  return 0;
}