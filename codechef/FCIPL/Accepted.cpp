/****************************************************************************************
*  @author: kzvd4729                                         created: 21-04-2020 12:36:02                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/problems/FCIPL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,mod=998244353;
int ncr[N+2][N+2];
void calNCR(int n)
{
  for(int i=0;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
  }
}
int dp1[N+2][N+2];
int dfs1(int p,int r)
{
  if(p==0&&r==0)return 1;
  if(p==0||r==0)return 0;
  if(dp1[p][r]!=-1)return dp1[p][r];
  int ret=0;
  for(int i=1;i<=p;i++)
    ret=(ret+1LL*ncr[p-1][i-1]*dfs1(p-i,r-1))%mod;
  return dp1[p][r]=ret;
}
int dp2[N+2][N+2];
int dfs2(int q,int r)
{
  if(q==0&&r==0)return 1;
  if(q<=1||r==0)return 0;
  if(dp2[q][r]!=-1)return dp2[q][r];
  int ret=0;
  for(int i=2;i<=q;i++)
    ret=(ret+1LL*ncr[q-1][i-1]*dfs2(q-i,r-1))%mod;
  return dp2[q][r]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calNCR(N);memset(dp1,-1,sizeof(dp1));memset(dp2,-1,sizeof(dp2));
  int t;cin>>t;
  while(t--)
  {
    int p,q,r;cin>>p>>q>>r;
    int ans=0;
    for(int i=1;i<r;i++)
    {
      //cout<<dfs1(p,i)<<" "<<dfs2(q,r-i)<<endl;
      ans=(ans+1LL*dfs1(p,i)*dfs2(q,r-i))%mod;
    }
    cout<<ans<<endl;
  }
  return 0;
}