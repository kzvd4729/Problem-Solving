/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-10 20:24:59                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 58                                         memory_used (MB): 4.9                             
*  problem: https://vjudge.net/problem/LightOJ-1092
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=(1<<8);
int cl[10],n,m,dp[10][N+2][N+2];
string s[10];
vector<int>vc[N+2];
int nex(int msk,int ret,int r)
{
  for(int i=0;i<r;i++)
  {
    if(!(msk&(1<<i)))continue;
    ret^=(1<<i);
    if(i)ret^=(1<<(i-1));
    if(i<r-1)ret^=(1<<(i+1));
  }
  return ret;
}
int dfs(int i,int prv,int msk)
{
  if(i==m)
  {
    if(prv==((1<<n)-1))return 0;
    return 1e9;
  }
  if(dp[i][prv][msk]!=-1)return dp[i][prv][msk];
  int now=1e9;
  for(auto x:vc[prv])
    now=min(now,__builtin_popcount(x)+dfs(i+1,nex(msk^x,cl[i],n),x));
  return dp[i][prv][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=0;i<n;i++)
      cin>>s[i];
    for(int j=0;j<m;j++)
    {
      cl[j]=0;
      for(int i=0;i<n;i++)
      {
        if(s[i][j]=='*')cl[j]|=(1<<i);
      }
    }
    for(int i=0;i<(1<<n);i++)
      vc[i].clear();
    for(int i=0;i<(1<<n);i++)
    {
      for(int j=0;j<(1<<n);j++)
      {
        int msk=nex(j,i,n);
        if(msk==((1<<n)-1))
          vc[i].push_back(j);
      }
    }
    int ans=1e9;memset(dp,-1,sizeof(dp));
    for(int i=0;i<(1<<n);i++)
      ans=min(ans,__builtin_popcount(i)+dfs(1,nex(i,cl[0],n),i));
    cout<<"Case "<<++tc<<": ";
    if(ans==1e9)cout<<"impossible"<<"\n";
    else cout<<ans<<"\n";
  }
  return 0;
}