/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/09/2019 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1102/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int col[N+2];
vector<int>vc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    vc[x].push_back(i);
  }
  vector<int>v;
  while(v.size()<=n)
  {
    for(int i=1;i<=k;i++)
      v.push_back(i);
  }
  int pt=0;
  for(int i=1;i<=N;i++)
  {
    if(vc[i].size()>k)cout<<"NO"<<endl,exit(0);
    for(auto x:vc[i])
    {
      col[x]=v[pt++];
    }
  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<col[i]<<" ";
  cout<<endl;
  return 0;
}