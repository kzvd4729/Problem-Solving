/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2018 22:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1056/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    while(x--)
    {
      int z;cin>>z;cnt[z]++;
    }
  }
  for(int i=1;i<=N;i++)
    if(cnt[i]==n)cout<<i<<" ";
  cout<<endl;
  return 0;
}