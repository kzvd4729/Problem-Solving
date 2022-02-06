/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 01:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1450 ms                                         memory_used: 128600 KB                            
*  problem: https://codeforces.com/contest/757/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6+2,mod=1e9+7;
int dp[20+2][N+2],vis[N+2];
vector<int>p[N+2];
void cal()
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      p[j].push_back(i);vis[j]=1;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=N;i++)
    dp[1][i]=i+1;
  for(int j=2;j<=20;j++)
  {
    for(int i=1;i<=N;i++)
      dp[j][i]=(dp[j][i-1]+dp[j-1][i])%mod;
  }
  cal();int q;cin>>q;
  while(q--)
  {
    int r,n;cin>>r>>n;
    int ans=1;
    for(auto x:p[n])
    {
      int cnt=0,tmp=n;
      while(tmp%x==0)
      {
        cnt++;tmp/=x;
      }
      ans=(1LL*ans*dp[cnt][r+1])%mod;
    }
    cout<<ans<<"\n";
  }
  return 0;
}