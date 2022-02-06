/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 21:21                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1208/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<cnt++<<" ";
    }
    cout<<endl;
  }
  return 0;
}