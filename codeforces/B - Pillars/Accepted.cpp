/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2019 15:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/1197/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>aa(n+1);
  for(int i=1;i<=n;i++)cin>>aa[i];
   stack<int>prv,nxt;
  prv.push(-1);nxt.push(-1);
  for(int i=1;i<=n;i++)
  {
    if(aa[i]!=n)continue;
    for(int j=n;j>i;j--)
      nxt.push(aa[j]);
    for(int j=1;j<i;j++)
      prv.push(aa[j]);
    break;
  }
  int tar=n-1;
  while(tar)
  {
    if(prv.top()==tar)
      tar--,prv.pop();
    else if(nxt.top()==tar)
      tar--,nxt.pop();
    else cout<<"NO"<<endl,exit(0);
  }
  cout<<"YES"<<endl;
  return 0;
}