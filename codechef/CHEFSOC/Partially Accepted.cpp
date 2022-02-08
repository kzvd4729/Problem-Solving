/****************************************************************************************
*  @author: kzvd4729                                         created: 04-03-2019 17:24:23                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 19.3M                                
*  problem: https://www.codechef.com/MARCH19A/problems/CHEFSOC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n,dp[15][10000];
int dfs(int i,int msk)
{
  //cout<<i<<" "<<msk<<endl;getchar();
  if(dp[i][msk]!=-1)return dp[i][msk];
  int now=1;
  if(i+1<n&&(msk&(1<<(i+1)))==0)
    now+=dfs(i+1,msk|(1<<(i+1)));
  if(i-1>=0&&(msk&(1<<(i-1)))==0)
    now+=dfs(i-1,msk|(1<<(i-1)));
  if(aa[i]==2)
  {
    if(i+2<n&&(msk&(1<<(i+2)))==0)
      now+=dfs(i+2,msk|(1<<(i+2)));
    if(i-2>=0&&(msk&(1<<(i-2)))==0)
      now+=dfs(i-2,msk|(1<<(i-2)));
  }
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;for(int i=0;i<n;i++)cin>>aa[i];
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,(1<<0))<<endl;
  }
  return 0;
}