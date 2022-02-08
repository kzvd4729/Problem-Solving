/****************************************************************************************
*  @author: kzvd4729                                         created: 30-11-2019 20:15:21                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.12 sec                                        memory_used: 30.2M                                
*  problem: https://www.codechef.com/LTIME78A/problems/APARTS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;
int vis[N+2][N+2],pr[N+2][N+2],n,m;
pair<int,int>pp[N*N+2];
void dfs(int i,int j)
{
  if(i<1||j<1||i>n||j>m)return ;
  if(vis[i][j])return ;vis[i][j]=1;
  dfs(i+1,j-1);dfs(i+1,j);dfs(i+1,j+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int x;cin>>x;pp[x]={i,j};
        vis[i][j]=0;
      }
    }
    for(int p=n*m;p>=1;p--)
    {
      int i=pp[p].first,j=pp[p].second;
      if(!vis[i][j])pr[i][j]=1;
      else pr[i][j]=0;
      dfs(i,j);
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cout<<pr[i][j];
      cout<<"\n";
    }
  }
  return 0;
}