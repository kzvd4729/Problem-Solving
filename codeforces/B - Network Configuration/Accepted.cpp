/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2019 13:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/412/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.begin(),v.end(),greater<int>());
  cout<<v[k-1]<<endl;
  return 0;
}