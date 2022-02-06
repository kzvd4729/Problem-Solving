/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2019 19:29                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/453/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int aa[N+2],n,str[N+2],mp[N+2];
int dp[N+2][30003];
int dfs(int st,int msk)
{
  if(st>n)return dp[st][msk]=0;
  if(dp[st][msk]!=-1)return dp[st][msk];
  int now=aa[st]-1+dfs(st+1,msk);
  for(int i=2;i<=30;i++)
  {
    if((msk&str[i]))continue;
    now=min(now,abs(aa[st]-i)+dfs(st+1,msk|str[i]));
  }
  return dp[st][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mp[2]=0;mp[3]=1;mp[5]=2;mp[7]=3;mp[11]=4;
  mp[13]=5;mp[17]=6;mp[19]=7;mp[23]=8;mp[29]=9;
  for(int i=2;i<=30;i++)
  {
    int msk=0;int x=i;
    for(int j=2;j<=30;j++)
    {
      while(x%j==0)
      {
        x/=j;msk|=(1<<mp[j]);
      }
    }
    str[i]=msk;
  }
  memset(dp,-1,sizeof(dp));
  cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
  int ans=dfs(1,0);int st=1,msk=0;
  //cout<<ans<<endl;
  int cnt=0;
  while(st<=n)
  {
    if(dp[st][msk]==aa[st]-1+dp[st+1][msk])
    {
      cnt++;ans-=(aa[st]-1);
      cout<<1<<" ";st++;continue;
    }
    for(int i=2;i<=30;i++)
    {
      if(msk&str[i])continue;
      if(dp[st][msk]==abs(aa[st]-i)+dp[st+1][(msk|str[i])])
      {
        cout<<i<<" ";cnt++;ans-=abs(aa[st]-i);
        st++;msk|=str[i];break;
      }
    }
    //cout<<st<<endl;
  }
  if(cnt!=n||ans)assert(0);
  cout<<endl;
    return 0;
}