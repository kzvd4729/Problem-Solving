/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-12 20:25:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1061
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int vis[10][10],dp[10][(1<<8)+2];
vector<int>v;
vector<vector<int> >way;
void _assign(int row,int col,int x)
{
  for(int i=1;i<=8;i++)
  {
    for(int j=1;j<=8;j++)
    {
      if(i==row||j==col||abs(i-row)==abs(j-col))
        vis[i][j]+=x;
    }
  }
}
void dfs(int col)
{
  if(col>8)
  {
    way.push_back(v);return ;
  }
  for(int row=1;row<=8;row++)
  {
    if(vis[row][col])continue;
    _assign(row,col,1);v.push_back(row);
    dfs(col+1);
    _assign(row,col,-1);v.pop_back();
  }
}
vector<pair<int,int> >pos,pth;
int dfs(int col,int msk)
{
  if(col==8)return 0;
  int now=1e9;if(dp[col][msk]!=-1)return dp[col][msk];
  for(int i=0;i<8;i++)
  {
    if((msk&(1<<i)))continue;
    pair<int,int>p1=pth[col],p2=pos[i];
    int cst;
    if(p1==p2)cst=0;
    else if(abs(p1.first-p2.first)==abs(p1.second-p2.second))cst=1;
    else if(p1.first==p2.first||p1.second==p2.second)cst=1;
    else cst=2;
    now=min(now,cst+dfs(col+1,(msk|(1<<i))));
  }
  return dp[col][msk]=now;
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  dfs(1);int t,tc=0;cin>>t;
  while(t--)
  {
    pos.clear();
    for(int i=0;i<8;i++)
    {
      string s;cin>>s;
      for(int j=0;j<8;j++)
      {
        if(s[j]=='q')
          pos.push_back({i,j});
      }
    }
    int ans=1e9;
    for(auto x:way)
    {
      pth.clear();
      for(int i=0;i<x.size();i++)
        pth.push_back({x[i]-1,i});
      memset(dp,-1,sizeof(dp));
      ans=min(ans,dfs(0,0));
    }
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}