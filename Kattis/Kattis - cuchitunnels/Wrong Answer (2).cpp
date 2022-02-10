/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 17:27:31                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-cuchitunnels
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int sm=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;sm+=x;
  }
  if(sm==n*2-2)cout<<"YES\n";
  else cout<<"NO\n";
  
  return 0;
}