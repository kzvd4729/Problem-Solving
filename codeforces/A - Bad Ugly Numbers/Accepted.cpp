/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2020 10:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1326/problem/A
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
    int n;cin>>n;
    if(n==1)cout<<-1<<"\n";
    else
    {
      cout<<'2';
      for(int i=1;i<n;i++)cout<<'3';
      cout<<"\n";
    }
  }
  return 0;
}