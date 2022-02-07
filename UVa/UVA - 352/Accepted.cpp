/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-25 11:55:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-352
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e18;
const int N=1e5;
int dr[]={1,1,1,-1,-1,-1,0,0};
int dc[]={1,-1,0,1,-1,0,1,-1};
int n,vis[30][30],tc;
char mat[30][30];
string s;
void dfs(int r,int c)
{
  vis[r][c]=1;
  for(int i=0;i<8;i++)
  {
    int ii=r+dr[i];
    int jj=c+dc[i];
    if(ii>n||ii<1||jj>n||jj<1||vis[ii][jj]||mat[ii][jj]=='0')continue;
    dfs(ii,jj);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n)
  {
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      for(int j=1;j<=n;j++)
      {
        mat[i][j]=s[j-1];
      }
    }
    memset(vis,0,sizeof(vis));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(mat[i][j]=='0')continue;
        if(vis[i][j])continue;
        ans++;
        dfs(i,j);
      }
    }
    cout<<"Image number "<<++tc<<" contains "<<ans<<" war eagles."<<endl;
  }
  return 0;
}