/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2019 21:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1194/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    if(k%3||k>n)
    {
      if(n%3)cout<<"Alice\n";
      else cout<<"Bob\n";
    }
    else
    {
      n-=k;n%=(k+1);
      if(n%3==1)cout<<"Bob\n";
      else cout<<"Alice\n";
    }
  }
  return 0;
}