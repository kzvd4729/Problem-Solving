/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 23:28:17                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 38.8M                                
*  problem: https://www.codechef.com/ALKH2019/problems/ARYGRD
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e8;
int n,m,k,dp[N+2][N+2][6];
char mt[N+2][N+2];
int dfs(int i,int j,int l)
{
  if(i>n)
  {
    if(j==m&&l==0)return 0;
    return -inf;
  }
  int p1=j,p2=j+l,p3=j+k;
  if(p3>m)return -inf;
  int cnt=0,f=0;
  for(int ii=p2;ii<=p3;ii++)
  {
    if(mt[i][ii]=='*')cnt++;
    if(mt[i][ii]=='#')f=1;
  }
  if(f)return -inf;
  if(dp[i][j][l]!=-1)return dp[i][j][l];
  int ret=-inf;
  for(int ii=p1;ii<=p3;ii++)
  {
    if(mt[i][ii]=='#')break;
    if(mt[i][ii]=='*'&&ii<p2)cnt++;
    ret=max(ret,cnt+dfs(i+1,ii,p3-ii));
  }
  return dp[i][j][l]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
    {
      mt[i][j]=s[j-1];
    }
  }
  memset(dp,-1,sizeof(dp));
  int ans=dfs(1,1,0);
  if(ans<0)ans=-1;
  cout<<ans<<endl;
  return 0;
}