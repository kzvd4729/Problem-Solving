/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/13/2019 14:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 211800 KB                            
*  problem: https://codeforces.com/contest/571/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,aa[N+2],a,b,vis[N+2];
long qm[N+2],dp[5000+2][5000+2];
long dfs(int i,int c1,int c2)
{
  if(i>n)
  {
    if(c1+c2)return 1e18;
    else return 0;
  }
  if(dp[c1][c2]!=-1)return dp[c1][c2];
  long ret=1e18;
  if(i+a-1<=n&&c1)ret=min(ret,qm[i+a-1]-qm[i]+dfs(i+a,c1-1,c2));
  if(i+b-1<=n&&c2)ret=min(ret,qm[i+b-1]-qm[i]+dfs(i+b,c1,c2-1));
  return dp[c1][c2]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=1;i<=k;i++)
  {
    int cnt=0;
    for(int j=i;j<=n;j+=k)
      cnt++;
    vis[cnt]++;
  }
  int c1=0,c2=0;a=-1,b=-1;
  for(int i=1;i<=N;i++)
  {
    if(!vis[i])continue;
    if(a==-1)a=i,c1=vis[i];
    else b=i,c2=vis[i];
  }
  //cout<<a<<" "<<b<<" "<<c1<<" "<<c2<<endl;
  for(int i=2;i<=n;i++)
    qm[i]=qm[i-1]+aa[i]-aa[i-1];
//  for(int i=1;i<=n;i++)
//    cout<<qm[i]<<" ";
//  cout<<endl;
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,c1,c2)<<endl;
  return 0;
}