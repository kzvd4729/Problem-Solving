/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/30/2019 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2500 KB                              
*  problem: https://codeforces.com/contest/1213/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;int cnt=0;
    v[x].push_back(0);
    while(x)
    {
      x/=2;++cnt;
      v[x].push_back(cnt);
    }
  }
  int mn=1e9;
  for(int i=0;i<=N;i++)
  {
    if(v[i].size()<k)continue;
    sort(v[i].begin(),v[i].end());
    int sm=0;
    for(int j=0;j<k;j++)
      sm+=v[i][j];
    mn=min(mn,sm);
  }
  cout<<mn<<endl;
  return 0;
}