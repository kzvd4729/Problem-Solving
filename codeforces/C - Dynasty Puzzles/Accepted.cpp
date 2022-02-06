/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2018 14:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 17300 KB                             
*  problem: https://codeforces.com/contest/192/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,dp[30][30],cnt[N+2],ans;
string s[N+2],tmp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>tmp;
    cnt[i]=tmp.size();
    s[i].push_back(tmp.front());
    s[i].push_back(tmp.back());
  }
  for(int i=1;i<=n;i++)
  {
    int a=s[i][0]-'a';
    int b=s[i][1]-'a';
    for(int j=0;j<26;j++)
    {
      if(dp[j][a]==0)continue;
      dp[j][b]=max(dp[j][b],dp[j][a]+cnt[i]);
    }
    dp[a][b]=max(dp[a][b],cnt[i]);
  }
  for(int i=0;i<26;i++)ans=max(ans,dp[i][i]);
  cout<<ans<<endl;
  return 0;
}