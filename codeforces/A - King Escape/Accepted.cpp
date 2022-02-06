/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2018 23:27                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 42900 KB                             
*  problem: https://codeforces.com/contest/1033/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,vis[N+2][N+2];
void dfs(int x,int y,int r,int c)
{
  //cout<<x<<" "<<y<<endl;
  if(x<1||y<1||x>n||y>n)return ;
  if(vis[x][y])return ;
  vis[x][y]=1;
  if(x==r&&y==c)cout<<"YES"<<endl,exit(0);
  dfs(x+1,y,r,c);
  dfs(x-1,y,r,c);
  dfs(x,y+1,r,c);
  dfs(x,y-1,r,c);
  dfs(x+1,y-1,r,c);
  dfs(x-1,y+1,r,c);
  dfs(x+1,y+1,r,c);
  dfs(x-1,y-1,r,c);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  int ax,ay;cin>>ax>>ay;
  for(int i=1;i<=n;i++)
    vis[i][ay]=1;
  for(int i=1;i<=n;i++)
    vis[ax][i]=1;
  for(int i=1;i<=n;i++)
  {
    int ii=ax+i;
    int jj=ay+i;
    if(ii<1||jj<1||ii>n||jj>n)continue;
    vis[ii][jj]=1;
  }
  for(int i=1;i<=n;i++)
  {
    int ii=ax-i;
    int jj=ay-i;
    if(ii<1||jj<1||ii>n||jj>n)continue;
    vis[ii][jj]=1;
  }
  for(int i=1;i<=n;i++)
  {
    int ii=ax+i;
    int jj=ay-i;
    if(ii<1||jj<1||ii>n||jj>n)continue;
    vis[ii][jj]=1;
  }
  for(int i=1;i<=n;i++)
  {
    int ii=ax-i;
    int jj=ay+i;
    if(ii<1||jj<1||ii>n||jj>n)continue;
    vis[ii][jj]=1;
  }
//  for(int i=1;i<=n;i++)
//  {
//    for(int j=1;j<=n;j++)
//    {
//      cout<<vis[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  int bx,by;cin>>bx>>by;
  int cx,cy;cin>>cx>>cy;
  dfs(bx,by,cx,cy);
  cout<<"NO"<<endl;
   return 0;
}