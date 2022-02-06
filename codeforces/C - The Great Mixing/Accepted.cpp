/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2019 19:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 795 ms                                          memory_used: 10600 KB                             
*  problem: https://codeforces.com/contest/788/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
bitset<N+1>dp1,dp2;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,n;cin>>m>>n;vector<int>v;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;v.push_back(x);
    dp1[x]=1;
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i=1;i<=1000;i++)
  {
    if(dp1[m*i])cout<<i<<endl,exit(0);
    dp2.reset();
    for(auto x:v)
      dp2|=(dp1<<x);
    dp1=dp2;
  }
  cout<<-1<<endl;
  return 0;
}