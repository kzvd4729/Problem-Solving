/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2019 00:39                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 233 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1253/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int dp[N+2],n,m,lt[N+2],rt[N+2],bit[N+2];
void upd(int x,int v)
{
  for( ;x>0;x-=x&-x)bit[x]=min(bit[x],v);
}
int get(int x)
{
  if(x<=0)return 0;
  int ret=1e9;
  for( ;x<=m+m;x+=x&-x)ret=min(ret,bit[x]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x,s;cin>>x>>s;
    lt[i]=max(1,x-s),rt[i]=min(m,x+s);
  }
  for(int j=1;j<=m+m;j++)dp[j]=bit[j]=1e9;
  for(int j=1;j<=m+m;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(rt[i]>j)continue;
      dp[j]=min(dp[j],j-rt[i]+get(lt[i]-j+rt[i]-1));
      upd(j,dp[j]);
    }
  }
  int mn=1e9;//cout<<dp[m]<<endl;
  for(int i=m;i<=m+m;i++)mn=min(mn,dp[i]);
  cout<<mn<<endl;
  return 0;
}