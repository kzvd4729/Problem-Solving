/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-18 18:10:59                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 35 ms                                           memory_used: 1408 KB                              
*  problem: https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  vector<pair<int,int> >pp(n);
  for(int i=1;i<=n;i++)
  {
    int x,l;cin>>x>>l;
    pp[i-1]={x-l,x+l};
  }
  sort(pp.begin(),pp.end());
   dp[n-1]=1;
  for(int i=n-2;i>=0;i--)
  {
    dp[i]=dp[i+1];
    int id=lower_bound(pp.begin(),pp.end(),make_pair(pp[i].second,-1))-pp.begin();
    dp[i]=max(dp[i],dp[id]+1);
  }
  cout<<dp[0]<<endl;
  return 0;
}