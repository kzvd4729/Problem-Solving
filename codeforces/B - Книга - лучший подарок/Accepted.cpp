/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2019 18:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/609/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  long ans=0;
  for(int i=1;i<=m;i++)
  {
    ans+=(fr[i]*(n-fr[i]))*1LL;
  }
  cout<<ans/2<<endl;
  return 0;
}