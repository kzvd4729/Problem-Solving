/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 12:40                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/797/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],dp[N+2];
vector<int>qr[N+2];
int main()
{
  don't compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int q;cin>>q;
  while(q--)
  {
    int p,k;cin>>p>>k;
    qr[k].push_back(p);
  }
  for(int i=1;i<=n;i++)
    sort(qr[i].begin(),qr[i].end());
  int sq=sqrt(n+1);
  for(int i=1;i<=sq;i++)
  {
    if(qr[i].size()==0)continue;
    memset(dp,-1,sizeof(dp));
    reverse(qr[i].begin(),qr[i].end());
      }
  return 0;
}