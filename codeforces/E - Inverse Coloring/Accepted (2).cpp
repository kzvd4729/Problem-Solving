/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2019 11:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1777 ms                                         memory_used: 6000 KB                              
*  problem: https://codeforces.com/contest/1027/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500;
const long mod=998244353;
long pre[N+2],dp1[N+2][N+2][2],dp2[N+2][N+2];
int mx,n,k;
inline long dfs1(int i,int cn,int f)
{
  if(!cn)f=1;if(i>n)return f;
  if(dp1[i][cn][f]!=-1)return dp1[i][cn][f];
  long now=0;
  now=now+dfs1(i+1,mx-1,f);
  if(cn)now=now+dfs1(i+1,cn-1,f);
  return dp1[i][cn][f]=now%mod;
}
inline long dfs2(int i,int cn)
{
  if(cn*mx>=k)return 0;
  if(i>n)return 1;long now=0;
  if(dp2[i][cn]!=-1)return dp2[i][cn];
  now=now+dfs2(i+1,cn+1);
  now=now+dfs2(i+1,1);
  return dp2[i][cn]=now%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    memset(dp1,-1,sizeof(dp1));
    mx=i;pre[i]=dfs1(2,i-1,0)*2LL;
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    memset(dp2,-1,sizeof(dp2));
    mx=i;ans+=pre[i]*dfs2(2,1);
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}