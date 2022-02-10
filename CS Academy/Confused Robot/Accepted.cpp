/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 377 ms                                          memory_used: 97.3 MB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],n,m;
string s[N+2],p;
pair<int,int>dfs(int x,int y,int i,int mv)
{
  if(i==mv)return {x,y};
  if(p[i]=='U')
  {
    if(x&&s[x-1][y]=='.')x--;
    return dfs(x,y,i+1,mv);
  }
  else if(p[i]=='D')
  {
    if(x<n-1&&s[x+1][y]=='.')x++;return dfs(x,y,i+1,mv);
  }
  else if(p[i]=='L')
  {
    if(y&&s[x][y-1]=='.')y--;return dfs(x,y,i+1,mv);
  }
  else
  {
    if(y<m-1&&s[x][y+1]=='.')y++;return dfs(x,y,i+1,mv);
  }
}
pair<int,int>dp[500+2][500+2][32+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>m>>q;
  for(int i=0;i<n;i++)cin>>s[i];
  cin>>p;int sz=p.size();
//cout<<p<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      dp[i][j][0]=dfs(i,j,0,sz);
  }
  for(int k=1;k<=30;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        pair<int,int>p=dp[i][j][k-1];
        dp[i][j][k]=dp[p.first][p.second][k-1];
      }
    }
  }
  while(q--)
  {
    int i,j,v;cin>>i>>j>>v;i--,j--;
    int rm=v%sz;//cout<<"here"<<endl;
    int mk=v/sz;//cout<<mk<<endl;
    for(int k=30;k>=0;k--)
    {
      if(mk&(1<<k))
      {
        pair<int,int>p=dp[i][j][k];
        i=p.first,j=p.second;
      }
    }
    //cout<<i<<" ** "<<j<<endl;
    pair<int,int>p=dfs(i,j,0,rm);
    cout<<p.first+1<<" "<<p.second+1<<"\n";
  }
  return 0;
}