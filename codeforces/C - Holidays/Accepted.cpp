/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/44/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int lt,rt;cin>>lt>>rt;
    for(int i=lt;i<=rt;i++)
      cnt[i]++;
  }
  for(int i=1;i<=n;i++)
  {
    if(cnt[i]!=1)
    {
      cout<<i<<" "<<cnt[i]<<endl,exit(0);
    }
  }
  cout<<"OK"<<endl;
  return 0;
}