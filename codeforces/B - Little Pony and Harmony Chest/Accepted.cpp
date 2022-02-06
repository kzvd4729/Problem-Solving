/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2019 19:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1809 ms                                         memory_used: 104700 KB                            
*  problem: https://codeforces.com/contest/453/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int aa[N+2],n,str[N+2],mp[N+2];
int dp[N+2][(1<<18)+2];
/************ Seive **************/
int IsPrime[N+2];vector<int>Prime;
void Seive(int n)
{
  Prime.push_back(2);IsPrime[1]=1;
  for(int i=4;i<=n;i+=2)IsPrime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(IsPrime[i])continue;Prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      IsPrime[j]=1;
  }
}
///////////////////////////////////
int dfs(int st,int msk)
{
  if(st>n)return dp[st][msk]=0;
  if(dp[st][msk]!=-1)return dp[st][msk];
  int now=aa[st]-1+dfs(st+1,msk);
  for(int i=2;i<=60;i++)
  {
    if((msk&str[i]))continue;
    now=min(now,abs(aa[st]-i)+dfs(st+1,msk|str[i]));
  }
  return dp[st][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  Seive(60);for(int i=0;i<Prime.size();i++)mp[Prime[i]]=i;
  for(int i=2;i<=60;i++)
  {
    int msk=0;int x=i;
    for(int j=2;j<=60;j++)
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
    for(int i=2;i<=60;i++)
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