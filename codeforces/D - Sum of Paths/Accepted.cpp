/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/08/2021 21:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 841 ms                                          memory_used: 98200 KB                             
*  problem: https://codeforces.com/contest/1467/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3,inf=1e9+1,mod=1e9+7;
int a[N+2],n,dp[N+2][N+2],tmp[N+2];
int dfs(int i,int j)
{
  if(j==0)return 1;
  if(dp[i][j]!=-1)return dp[i][j];
  int now=0;
  if(i==1)now=dfs(i+1,j-1);
  else if(i==n)now=dfs(i-1,j-1);
  else now=(dfs(i-1,j-1)+dfs(i+1,j-1))%mod;
   return dp[i][j]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k,q;cin>>n>>k>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
   memset(dp,-1,sizeof dp);
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=k;j++)
      tmp[i]=(tmp[i]+1LL*dfs(i,j)*dfs(i,k-j))%mod;
  }
  //for(int i=1;i<=n;i++)cout<<tmp[i]<<" ";cout<<endl;
   int ans=0;
  for(int i=1;i<=n;i++)ans=(ans+1LL*tmp[i]*a[i])%mod;
  while(q--)
  {
    int id,vl;cin>>id>>vl;
     ans=(ans-1LL*tmp[id]*a[id])%mod;
    a[id]=vl;
    ans=(ans+1LL*tmp[id]*a[id])%mod;
     ans=(ans+mod)%mod;
    cout<<ans<<" ";
  }
  cout<<endl;
    return 0;
}