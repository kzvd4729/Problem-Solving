/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/16/2020 17:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 90000 KB                             
*  problem: https://codeforces.com/contest/1391/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;
vector<vector<int> >v;int n,m;
int dp[N+2][2][2][2];
int dfs(int id,int a,int b,int c)
{
  if(id>m)return 0;
  if(dp[id][a][b][c]!=-1)return dp[id][a][b][c];
  int now=1e9;
  for(int i=0;i<=1;i++)
  {
    for(int j=0;j<=1;j++)
    {
      for(int k=0;k<=1;k++)
      {
        if((a+b+i+j)%2==0||(b+c+j+k)%2==0)continue;
        now=min(now,(i!=v[1][id])+(j!=v[2][id])+(k!=v[3][id])+dfs(id+1,i,j,k));
      }
    }
  }
  return dp[id][a][b][c]=now;
}
int mm[N+2][2][2];
int dfs(int id,int a,int b)
{
  if(id>m)return 0;
  if(mm[id][a][b]!=-1)return mm[id][a][b];
  int now=1e9;
  for(int i=0;i<=1;i++)
  {
    for(int j=0;j<=1;j++)
    {
      if((a+b+i+j)%2==0)continue;
      now=min(now,(i!=v[1][id])+(j!=v[2][id])+dfs(id+1,i,j));
    }
  }
  return mm[id][a][b]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  if(n==1)cout<<0<<endl,exit(0);
  if(n>=4)cout<<-1<<endl,exit(0);
   v.resize(n+2);
  for(int i=1;i<=n;i++)
  {
    v[i].resize(m+2);string s;cin>>s;
    for(int j=1;j<=m;j++)v[i][j]=s[j-1]-'0';
  }
   if(n==3)
  {
    int now=1e9,id=1;memset(dp,-1,sizeof dp);
    for(int i=0;i<=1;i++)
    {
      for(int j=0;j<=1;j++)
      {
        for(int k=0;k<=1;k++)
        {
          now=min(now,(i!=v[1][id])+(j!=v[2][id])+(k!=v[3][id])+dfs(id+1,i,j,k));
        }
      }
    }
    cout<<now<<endl;
  }
  else
  {
    int now=1e9,id=1;memset(mm,-1,sizeof mm);
    for(int i=0;i<=1;i++)
    {
      for(int j=0;j<=1;j++)
      {
        now=min(now,(i!=v[1][id])+(j!=v[2][id])+dfs(id+1,i,j));
      }
    }
    cout<<now<<endl;
  }
  return 0;
}