/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 164 ms                                          memory_used: 34.2 MB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,m,ds[N+2][N+2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char mt[N+2][N+2],tmp[N+2][N+2];
vector<pair<int,int> >pos;
void bfs(void)
{
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      ds[i][j]=1e9;
  queue<pair<int,int> >q;
  for(auto x:pos)
  {
    q.push(x);ds[x.first][x.second]=0;
  }
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    for(int i=0;i<4;i++)
    {
      int u=p.first+dx[i];
      int v=p.second+dy[i];
      if(ds[u][v]>ds[p.first][p.second]+1)
      {
        ds[u][v]=ds[p.first][p.second]+1;
        q.push({u,v});
      }
    }
  }
}
int f,edx,edy;
void dfs(int i,int j)
{
  if(i>n||i<1||j>m||j<1)return ;
  if(tmp[i][j]=='#')return ;
  if(i==edx&&j==edy)f=1;
  tmp[i][j]='#';
  for(int k=0;k<4;k++)
    dfs(i+dx[k],j+dy[k]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;int stx,sty;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
    {
      mt[i][j]=s[j-1];
      if(mt[i][j]=='P')
        pos.push_back({i,j});
      if(mt[i][j]=='S')stx=i,sty=j;
      if(mt[i][j]=='F')edx=i,edy=j;
    }
  }
  bfs();
  int lo=0,hi=1e4,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(ds[i][j]<=md)tmp[i][j]='#';
        else tmp[i][j]='.';
      }
    }
    f=0;dfs(stx,sty);
    if(f)lo=md;else hi=md;
  }
  for(md=hi;md>=lo;md--)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(ds[i][j]<=md)tmp[i][j]='#';
        else tmp[i][j]='.';
        //if(md==3)cout<<tmp[i][j];
      }
      //if(md==3)cout<<endl;
    }
    f=0;dfs(stx,sty);
    if(f)cout<<md+1<<endl,exit(0);
  }
  cout<<"impossible"<<endl;
  return 0;
}