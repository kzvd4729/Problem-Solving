/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 21:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1101/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;int mxu=0,mxv=0;
  for(int i=1;i<=n;i++)
  {
    char c;int u,v;cin>>c>>u>>v;
    if(u>v)swap(u,v);
    if(c=='+')
      mxu=max(mxu,u),mxv=max(mxv,v);
    else
    {
      if(mxu<=u&&mxv<=v)cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
  return 0;
}