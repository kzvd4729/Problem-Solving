/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 16:53:59                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 686 ms                                          memory_used: 13184 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_k
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,aa[N+2],dp[N+2];
int dfs(int k)
{
  if(dp[k]!=-1)return dp[k];
  set<int>st;
  for(int i=1;i<=n;i++)
    if(k-aa[i]>=0)
      st.insert(dfs(k-aa[i]));
  for(int i=0; ;i++)
    if(st.find(i)==st.end())
      return dp[k]=i;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  if(dfs(k))cout<<"First"<<endl;
  else cout<<"Second"<<endl;
  return 0;
}