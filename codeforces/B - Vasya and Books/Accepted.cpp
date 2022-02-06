/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2018 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1073/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],id[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];id[aa[i]]=i;
  }
  int mx=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    cout<<max(0,id[x]-mx)<<" ";
    mx=max(mx,id[x]);
  }
  cout<<endl;
  return 0;
}