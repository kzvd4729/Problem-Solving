/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 00:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/723/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int sz,f,vis[52][52],n,m,k,ans;
char mat[52][52];
string s;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
priority_queue<pair<int,pair<int,int> > >pq;
void dfs(int r,int c)
{
  sz++;
  vis[r][c]=1;
  for(int i=0;i<4;i++)
  {
    int xx=r+dr[i];
    int yy=c+dc[i];
    if(xx<1||xx>n||yy<1||yy>m)
    {
      f=-1;
      return ;
    }
    if(vis[xx][yy]==0&&mat[xx][yy]=='.')dfs(xx,yy);
  }
}
void dfs2(int r,int c)
{
  mat[r][c]='*';
  for(int i=0;i<4;i++)
  {
    int xx=r+dr[i];
    int yy=c+dc[i];
    if(mat[xx][yy]=='.')dfs2(xx,yy);
  }
}int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=s[j-1];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]=='.'&&vis[i][j]==0)
      {
        f=0;
        sz=0;
        dfs(i,j);
        if(f==0)pq.push({-sz,{i,j}});
      }
    }
  }
  while(pq.size()>k)
  {
    pair<int,pair<int,int> >p=pq.top();
    pq.pop();
    ans-=p.first;
    dfs2(p.second.first,p.second.second);
  }
  cout<<ans<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cout<<mat[i][j];
    }
    cout<<endl;
  }
  return 0;
}