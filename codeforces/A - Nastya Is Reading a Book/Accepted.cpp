/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2019 22:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1136/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>lt[i]>>rt[i];
  int k;cin>>k;k--;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(rt[i]<=k)cnt++;
  }
  cout<<n-cnt<<endl;
  return 0;
}