/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/03/2018 20:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1003/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x,fr[102],mx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    fr[x]++;
    mx=max(mx,fr[x]);
  }
  cout<<mx<<endl;
  return 0;
}