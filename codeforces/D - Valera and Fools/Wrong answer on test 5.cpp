/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2020 19:04                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 106100 KB                            
*  problem: https://codeforces.com/contest/369/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3+4;
int aa[N+2],hn[N+2][N+2],zr[N+2][N+2],n,k,v[N+2][N+2];
void dfs(int i,int j)
{
  if(v[i][j])return ;v[i][j]=1;
  if(j>n)return ;
   if(hn[i][i])
  {
    if(hn[j][n])dfs(j+1,j+2);
    else if(zr[j][n])dfs(i,j+1);
    else 
    {
      dfs(i,j+1);dfs(j+1,j+2);
    }
  }
  else if(zr[i][j])
  {
    if(hn[j][n])dfs(j,j+1);
    else if(zr[j][n]);
    else
    {
      dfs(j,j+1);
    }
  }
  else
  {
    if(hn[j][n])
    {
      dfs(j,j+1);dfs(j+1,j+2);
    }
    else if(zr[j][n])
    {
      dfs(i,j+1);
    }
    else 
    {
      dfs(j,j+1);dfs(i,j+1);
      dfs(j+1,j+2);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
  }
  for(int i=1;i<=n;i++)
  {
    if(aa[i]==100)hn[i][i]=1;
    if(aa[i]==0)zr[i][i]=1;
    for(int j=i+1;j<=n;j++)
    {
      hn[i][j]=hn[i][j-1]|(aa[j]==100);
      zr[i][j]=zr[i][j-1]&(aa[j]==0);
    }
  }
  dfs(1,2);int cnt=0;
  for(int i=1;i<=n+2;i++)
  {
    for(int j=1;j<=n+2;j++)
    {
      //if(v[i][j])cout<<i<<" "<<j<<endl;
      if(v[i][j])cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}