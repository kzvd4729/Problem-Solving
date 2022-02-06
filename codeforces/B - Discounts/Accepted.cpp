/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2019 21:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1132/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2],sum;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];sum+=aa[i];
  }
  sort(aa+1,aa+n+1);
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;
    cout<<sum-aa[n-x+1]<<"\n";
  }
  return 0;
}