/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 15:55                        
*  solution_verdict: Wrong answer on test 26                 language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 216300 KB                            
*  problem: https://codeforces.com/contest/282/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
int dp[N+2][N+2][N+2][2],dp2[N+2][N+2][2];
bool dfs(int a,int b,int c,int tr)
{
  int x=(a^b)^c;
  return x;
//  if(dp[a][b][c][tr]!=-1)return dp[a][b][c][tr];
//  if(tr)
//  {
//    dp[a][b][c][tr]=0;
//    for(int i=1;i<=a;i++)
//      dp[a][b][c][tr]|=dfs(a-i,b,c,0);
//    for(int i=1;i<=b;i++)
//      dp[a][b][c][tr]|=dfs(a,b-i,c,0);
//    for(int i=1;i<=c;i++)
//      dp[a][b][c][tr]|=dfs(a,b,c-i,0);
//    int mn=min(min(a,b),c);
//    for(int i=1;i<=mn;i++)
//      dp[a][b][c][tr]|=dfs(a-i,b-i,c-i,0);
//  }
//  else
//  {
//    dp[a][b][c][tr]=1;
//    for(int i=1;i<=a;i++)
//      dp[a][b][c][tr]&=dfs(a-i,b,c,1);
//    for(int i=1;i<=b;i++)
//      dp[a][b][c][tr]&=dfs(a,b-i,c,1);
//    for(int i=1;i<=c;i++)
//      dp[a][b][c][tr]&=dfs(a,b,c-i,1);
//    int mn=min(min(a,b),c);
//    for(int i=1;i<=mn;i++)
//      dp[a][b][c][tr]&=dfs(a-i,b-i,c-i,1);
//  }
//  return dp[a][b][c][tr];
}
bool dfs2(int a,int b,int tr)
{
  if(dp2[a][b][tr]!=-1)return dp2[a][b][tr];
  if(tr)
  {
    dp2[a][b][tr]=0;
    for(int i=1;i<=a;i++)
      dp2[a][b][tr]|=dfs2(a-i,b,0);
    for(int i=1;i<=b;i++)
      dp2[a][b][tr]|=dfs2(a,b-i,0);
    int mn=min(a,b);
    for(int i=1;i<=mn;i++)
      dp2[a][b][tr]|=dfs2(a-i,b-i,0);
  }
  else
  {
    dp2[a][b][tr]=1;
    for(int i=1;i<=a;i++)
      dp2[a][b][tr]&=dfs2(a-i,b,1);
    for(int i=1;i<=b;i++)
      dp2[a][b][tr]&=dfs2(a,b-i,1);
    int mn=min(a,b);
    for(int i=1;i<=mn;i++)
      dp2[a][b][tr]&=dfs2(a-i,b-i,1);
  }
  return dp2[a][b][tr];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 //        memset(dp,-1,sizeof(dp));
//  for(int i=1;i<=6;i++)
//  {
//    for(int j=1;j<=6;j++)
//    {
//      for(int k=1;k<=6;k++)
//      {
//        int x=(i^j)^k;
//         if(dfs(i,j,k,1))cout<<i<<" "<<j<<" "<<k<<" BitLGM "<<x<<endl;
//        else cout<<i<<" "<<j<<" "<<k<<" BitAryo "<<x<<endl;
//      }
//    }
//  }
   int n,a=0,b=0,c=0;cin>>n;
  if(n==1)
  {
    cin>>a;
    cout<<"BitLGM"<<endl;
  }
  else if(n==2)
  {
    cin>>a>>b;
    memset(dp2,-1,sizeof(dp2));
    if(dfs2(a,b,1))cout<<"BitLGM"<<endl;
    else cout<<"BitAryo"<<endl;
  }
  else
  {
    cin>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    if(dfs(a,b,c,1))cout<<"BitLGM"<<endl;
    else cout<<"BitAryo"<<endl;
  }
  return 0;
}