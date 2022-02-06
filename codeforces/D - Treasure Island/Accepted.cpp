/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/04/2019 15:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 117500 KB                            
*  problem: https://codeforces.com/contest/1214/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<vector<char> >mt;
vector<vector<int> >vis;
int n,m;
int dfs(int i,int j)
{
  if(i==n&&j==m)return 1;
  if(i>n||j>m)return 0;
  if(vis[i][j])return 0;
  if(mt[i][j]=='#')return 0;
   vis[i][j]=1;
  if(dfs(i+1,j))return 1;
  return dfs(i,j+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;mt.resize(n+1),vis.resize(n+1);
  for(int i=1;i<=n;i++)mt[i].resize(m+1),vis[i].resize(m+1);
   for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)mt[i][j]=s[j-1];
  }
  int ans=0;
  if(dfs(1,1))ans=1;
  vis[1][1]=0;
  if(dfs(1,1))ans=2;
  cout<<ans<<endl;
   return 0;
}