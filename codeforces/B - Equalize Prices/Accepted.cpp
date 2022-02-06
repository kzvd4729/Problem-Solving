/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2019 19:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1183/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    int n,k;cin>>n>>k;int mn=1e9,mx=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      mn=min(mn,x);mx=max(mx,x);
    }
    if(mx-mn>k+k)cout<<-1<<"\n";
    else cout<<mn+k<<"\n";
  }
  return 0;
}