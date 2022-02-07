/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-03 15:01:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-572
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
char mat[102][102];
int vis[102][102],print,n,m;
int dr[]={0, 0, 1, 1, 1,-1,-1,-1};
int dc[]={1,-1,-1, 0, 1,-1, 0, 1};
string s;
bool invalid(int i,int j)
{
  if(i>n||i<1||j>m||j<1)return true;
  return false;
}
void dfs(int r,int c)
{
  vis[r][c]=1;
  for(int i=0;i<8;i++)
  {
    int rr=r+dr[i];
    int cc=c+dc[i];
    if(invalid(rr,cc)||vis[rr][cc]||mat[rr][cc]=='*')continue;
    dfs(rr,cc);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while(cin>>n>>m)
  {
    if(n==0)break;
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      for(int j=1;j<=m;j++)
      {
        mat[i][j]=s[j-1];
      }
    }
    memset(vis,0,sizeof(vis));
    print=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(vis[i][j]==0&&mat[i][j]=='@')
        {
          print++;
          dfs(i,j);
        }
      }
    }

    cout<<print<<endl;

  }
  return 0;
}