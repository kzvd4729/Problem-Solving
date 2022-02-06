/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/12/2020 19:21                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/1324/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)po[i].clear();
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];
      po[aa[i]].push_back(i);
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<po[i].size();j++)
        if(po[i][j]-1!=po[i][j-1])f=1;
    }
    for(int i=1;i<n;i++)
    {
      if(aa[i]!=aa[i+1])continue;
      for(int j=i+2;j<=n;j++)
      {
        if(po[aa[j]][0]<i)f=1;
      }
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}