/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/22/2019 21:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 22100 KB                             
*  problem: https://codeforces.com/contest/1249/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int str[N+2],lft[N+2],qm[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,c;cin>>n>>c;
  for(int i=2;i<=n;i++)cin>>str[i];
  for(int i=2;i<=n;i++)cin>>lft[i];
  for(int i=1;i<=n;i++)qm[i]=qm[i-1]+lft[i];
   set<int>st;st.insert(0);
  for(int i=2;i<=n;i++)
  {
    dp[i]=dp[i-1]+str[i];
    dp[i]=min(dp[i],*st.begin()+qm[i]+c);
     st.insert(dp[i]-qm[i]);
  }
  for(int i=1;i<=n;i++)
    cout<<dp[i]<<" ";
  cout<<endl;
  return 0;
}