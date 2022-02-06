/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2020 22:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 265 ms                                          memory_used: 5900 KB                              
*  problem: https://codeforces.com/contest/516/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=2e3;
int n,m;string a[N+2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int i,int j)
{
  int cnt=0;
  for(int k=0;k<4;k++)
  {
    int u=i+dx[k],v=j+dy[k];
    if(u>=1&&u<=n&&v>=1&&v<=m&&a[u][v]=='.')cnt++;
  }
  if(cnt!=1)return ;int u,v;
  for(int k=0;k<4;k++)
  {
    u=i+dx[k],v=j+dy[k];
    if(u>=1&&u<=n&&v>=1&&v<=m&&a[u][v]=='.')
    {
      if(i==u)
      {
        if(j<v)a[i][j]='<',a[u][v]='>';
        else a[u][v]='<',a[i][j]='>';
      }
      else
      {
        if(i<u)a[i][j]='^',a[u][v]='v';
        else a[u][v]='^',a[i][j]='v';
      }
      break;
    }
  }
  i=u,j=v;
  for(int k=0;k<4;k++)
  {
    u=i+dx[k],v=j+dy[k];
    if(u>=1&&u<=n&&v>=1&&v<=m&&a[u][v]=='.')
      dfs(u,v);
  }
}
void no()
{
  cout<<"Not unique"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i],a[i]="*"+a[i];
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(a[i][j]=='.')
      {
        //cout<<i<<" "<<j<<endl;
        dfs(i,j);
      }
    }
  }
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='.')no();
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)cout<<a[i][j];
      cout<<endl;
  }
  return 0;
}