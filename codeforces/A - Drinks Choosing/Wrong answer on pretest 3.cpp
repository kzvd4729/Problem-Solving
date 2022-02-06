/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2019 20:42                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1195/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;vector<int>v;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  if(n%2)v.push_back(v.back()+1);
  int ans=0;
  for(int i=0;i<v.size();i+=2)
  {
    if(v[i]==v[i+1])ans+=2;
    else ans++;
  }
  cout<<ans<<endl;
  return 0;
}