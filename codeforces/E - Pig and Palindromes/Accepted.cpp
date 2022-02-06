/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2018 17:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 873 ms                                          memory_used: 261500 KB                            
*  problem: https://codeforces.com/contest/570/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
const int mod=1e9+7;
int n,m;
vector<int>dp[N+1][N+1];
char mat[N+1][N+1];
int dfs(int r,int c,int br)
{
  int mv=r+c-2;
  int bc=m-(mv-(n-br));
  if(r>n||c>m||br<1||bc<1)return 0;
  if(r>br||c>bc||mat[r][c]!=mat[br][bc])return 0;
  if(r==br&&c==bc)return 1;
  if(r==br&&c+1==bc)return 1;
  if(r+1==br&&c==bc)return 1;
   if(dp[br][r][c]!=-1)return dp[br][r][c];
  int here=0;
   here+=dfs(r+1,c,br-1);here%=mod;
  here+=dfs(r+1,c,br);here%=mod;
  here+=dfs(r,c+1,br-1);here%=mod;
  here+=dfs(r,c+1,br);here%=mod;
   return dp[br][r][c]=here;
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
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
      dp[i][j].resize(N-j+1,-1);
    }
  }
  cout<<dfs(1,1,n)<<endl;
  return 0;
}