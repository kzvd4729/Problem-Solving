/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/23/2019 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 11900 KB                             
*  problem: https://codeforces.com/contest/1108/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>vv[N+2];
vector<int>dv(int x)
{
  vector<int>v;
  for(int i=1;i<=x;i++)
    if(x%i==0)v.push_back(i);
  return v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>xx;
  for(int i=0;i<n;i++)
  {
    int x;cin>>x;xx.push_back(x);
  }
  sort(xx.begin(),xx.end());
  for(int i=0;i<n;i++)
    vv[i]=dv(xx[i]);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      vector<int>v=vv[i];
      for(auto x:vv[j])
        v.push_back(x);
      sort(v.begin(),v.end());
      if(v==xx)
      {
        cout<<xx[i]<<" "<<xx[j]<<endl,exit(0);
      }
    }
  }
  return 0;
}