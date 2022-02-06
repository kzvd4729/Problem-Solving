/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 20:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/961/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int cnt[1003],n,m,x,mn=1e9;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>x;
    cnt[x]++;
  }
  for(int i=1;i<=n;i++)mn=min(mn,cnt[i]);
  cout<<mn<<endl;
   return 0;
}