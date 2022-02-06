/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2019 00:26                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1253/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int dp[N+2],n,m,lt[N+2],rt[N+2],bit[N+2];
void upd(int x,int v)
{
  for( ;x>0;x-=x&-x)bit[x]=min(bit[x],v);
}
int get(int x)
{
  if(x<=0)return 0;
  int ret=1e9;
  for( ;x<=m;x+=x&-x)ret=min(ret,bit[x]);
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
  for(int j=1;j<=m;j++)dp[j]=bit[j]=1e9;
  for(int j=1;j<=m;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(rt[i]>j)continue;
      dp[j]=min(dp[j],j-rt[i]+get(lt[i]-j+rt[i]-1));
      upd(j,dp[j]);
    }
  }
  cout<<dp[m]<<endl;
  return 0;
}