/****************************************************************************************
*  @author: kzvd4729                                         created: 07-09-2018 16:17:37                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/SEPT18A/problems/TABGAME
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int dp[N+2][N+2];
string n,m;
int dfs(int i,int j)
{
  if(dp[i][j]!=-1)return dp[i][j];
  set<int>st;
  st.insert(dp[i-1][j]);
  st.insert(dp[i][j-1]);
  for(int k=0; ;k++)
    if(st.find(k)==st.end())return dp[i][j]=k;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>m>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=m.size();i++)
      dp[0][i]=m[i-1]-'0';
    for(int i=1;i<=n.size();i++)
      dp[i][0]=n[i-1]-'0';
    int q;cin>>q;string ans;
    while(q--)
    {
      int u,v;cin>>u>>v;
      if(dfs(u,v))ans.push_back('1');
      else ans.push_back('0');
    }
//    for(int i=3;i>=0;i--)
//    {
//      for(int j=3;j>=0;j--)
//      {
//        cout<<setw(3)<<dp[i][j];
//      }
//      cout<<endl;
//    }
    cout<<ans<<endl;
  }
  return 0;
}