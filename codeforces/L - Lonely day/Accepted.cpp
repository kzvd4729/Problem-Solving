/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2021 23:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 52300 KB                             
*  problem: https://codeforces.com/gym/102700/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
const int inf=1e9;
int ds[N+2][N+2];
pair<int,int>p[N+2][N+2];
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="X"+s[i];
   int x,y,ti,tj;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='S')x=i,y=j;
      if(s[i][j]=='E')ti=i,tj=j;
      ds[i][j]=inf;
    }
  }
  queue<pair<int,int> >q;
  p[x][y]={-1,-1},ds[x][y]=0;q.push({x,y});
   while((int)q.size())
  {
    pair<int,int>u=q.front();q.pop();
     int a=u.first,b=u.second,c=-1,d=-1;
     //D
    c=-1,d=-1;
    for(int i=a+1;i<=n;i++)
    {
      if(s[i][b]=='X')continue;
      c=i,d=b;break;
    }
    if(c!=-1&&ds[a][b]+1<ds[c][d])
    {
      p[c][d]={a,b};ds[c][d]=ds[a][b]+1;
      q.push({c,d});
    }
     //L
    c=-1,d=-1;
    for(int j=b-1;j>=1;j--)
    {
      if(s[a][j]=='X')continue;
      c=a,d=j;break;
    }
    if(c!=-1&&ds[a][b]+1<ds[c][d])
    {
      p[c][d]={a,b};ds[c][d]=ds[a][b]+1;
      q.push({c,d});
    }
     //R
    for(int j=b+1;j<=m;j++)
    {
      if(s[a][j]=='X')continue;
      c=a,d=j;break;
    }
    if(c!=-1&&ds[a][b]+1<ds[c][d])
    {
      p[c][d]={a,b};ds[c][d]=ds[a][b]+1;
      q.push({c,d});
    }
     //U
    c=-1,d=-1;
    for(int i=a-1;i>=1;i--)
    {
      if(s[i][b]=='X')continue;
      c=i,d=b;break;
    }
    if(c!=-1&&ds[a][b]+1<ds[c][d])
    {
      p[c][d]={a,b};ds[c][d]=ds[a][b]+1;
      q.push({c,d});
    }
  }
  if(ds[ti][tj]==inf)cout<<-1<<endl,exit(0);
  string ans;int pr=ds[ti][tj];
  //cout<<pr<<endl;
  while(true)
  {
    if(ti==x&&tj==y)break;
    int ni,nj;
    if(p[ti][tj].first==ti&&p[ti][tj].second<tj)
    {
      ans.push_back('R');
      ni=p[ti][tj].first,nj=p[ti][tj].second;
    }
    else if(p[ti][tj].first==ti&&p[ti][tj].second>tj)
    {
      ans.push_back('L');
      ni=p[ti][tj].first,nj=p[ti][tj].second;
    }
    else if(p[ti][tj].first<ti&&p[ti][tj].second==tj)
    {
      ans.push_back('D');
      ni=p[ti][tj].first,nj=p[ti][tj].second;
    }
    else if(p[ti][tj].first>ti&&p[ti][tj].second==tj)
    {
      ans.push_back('U');
      ni=p[ti][tj].first,nj=p[ti][tj].second;
    }
    ti=ni,tj=nj;
  }
  reverse(ans.begin(),ans.end());
  cout<<pr<<endl<<ans<<endl;
  return 0;
}