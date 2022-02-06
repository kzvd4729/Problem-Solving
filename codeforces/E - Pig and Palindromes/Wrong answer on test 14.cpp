/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2018 16:41                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/570/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const long mod=2e9+7;
int n,m,dp[N+2][N+2][N+2];
char mat[N+2][N+2];
int dfs(int r,int c,int br)
{
  int mv=r+c-2;
  int bc=m-(mv-(n-br));
  if(r>n||c>m||br<1||bc<1)return 0;
  if(r>br||c>bc||mat[r][c]!=mat[br][bc])return 0;
  if(r==br&&c==bc)return 1;
  if(r==br&&c+1==bc)return 1;
  if(r+1==br&&c==bc)return 1;
   if(dp[r][c][br]!=-1)return dp[r][c][br];
  long here=0;
   here+=dfs(r+1,c,br-1)*1LL;
  here+=dfs(r+1,c,br)*1LL;
  here+=dfs(r,c+1,br-1)*1LL;
  here+=dfs(r,c+1,br)*1LL;
   here=here%mod;
  return dp[r][c][br]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=s[j-1];
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,1,n)<<endl;
  return 0;
}