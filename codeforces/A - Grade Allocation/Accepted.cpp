/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1316/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;int sm=0;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];
      if(i>1)sm+=aa[i];
    }
    cout<<min(aa[1]+sm,m)<<"\n";
  }
  return 0;
}