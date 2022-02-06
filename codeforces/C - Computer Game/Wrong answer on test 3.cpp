/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2019 19:29                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1183/problem/C
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
    int k,n,a,b;cin>>k>>n>>a>>b;k--;
    k-=n*b;
    if(k<0)cout<<-1<<"\n";
    else cout<<min(n,k/(a-b))<<"\n";
  }
  return 0;
}