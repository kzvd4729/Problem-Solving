/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-24 19:34:26                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-1714
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=51;
const int inf=1e9;
int n,m,ds[10003][N+2][N+2],bst[N+2][N+2],vis[10003][N+2][N+2];
int lt[N+2][N+2],rt[N+2][N+2],up[N+2][N+2],dw[N+2][N+2];
char mt[N+2][N+2];
string s;
void bfs(int i,int j)
{
  for(int l=0;l<=s.size();l++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        ds[l][i][j]=inf,vis[l][i][j]=0;
  memset(bst,0,sizeof(bst));
  ds[0][1][1]=0;
  deque<pair<int,pair<int,int> > >q;q.push_back({0,{1,1}});
  while(q.size())
  {
    pair<int,pair<int,int> >p=q.front();q.pop_front();
    int l=p.first,i=p.second.first,j=p.second.second;
    if(vis[l][i][j])continue;vis[l][i][j]=1;
    if(l==s.size())continue;
    if(l<bst[i][j])continue;bst[i][j]=l;
    if(s[l]==mt[i][j])
    {
      if(ds[l][i][j]<ds[l+1][i][j])
      {
        q.push_front({l+1,{i,j}});
        ds[l+1][i][j]=ds[l][i][j];
      }
      continue;
    }
    if(rt[i][j]<=m)
    {
      if(ds[l][i][j]+1<ds[l][i][rt[i][j]])
      {
        ds[l][i][rt[i][j]]=ds[l][i][j]+1;
        q.push_back({l,{i,rt[i][j]}});
      }
    }
    if(lt[i][j]>=1)
    {
      if(ds[l][i][j]+1<ds[l][i][lt[i][j]])
      {
        ds[l][i][lt[i][j]]=ds[l][i][j]+1;
        q.push_back({l,{i,lt[i][j]}});
      }
    }
    if(up[i][j]>=1)
    {
      if(ds[l][i][j]+1<ds[l][up[i][j]][j])
      {
        ds[l][up[i][j]][j]=ds[l][i][j]+1;
        q.push_back({l,{up[i][j],j}});
      }
    }
    if(dw[i][j]<=n)
    {
      if(ds[l][i][j]+1<ds[l][dw[i][j]][j])
      {
        ds[l][dw[i][j]][j]=ds[l][i][j]+1;
        q.push_back({l,{dw[i][j],j}});
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>m)
  {
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      for(int j=1;j<=m;j++)
        mt[i][j]=s[j-1];
    }
    cin>>s;s.push_back('*');
    for(int i=1;i<=n;i++)
      rt[i][m]=m+1,lt[i][1]=0;
    for(int j=1;j<=m;j++)
      up[1][j]=0,dw[n][j]=n+1;
    for(int i=1;i<=n;i++)
    {
      for(int j=m-1;j>=1;j--)
      {
        if(mt[i][j]==mt[i][j+1])
          rt[i][j]=rt[i][j+1];
        else rt[i][j]=j+1;
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=2;j<=m;j++)
      {
        if(mt[i][j]==mt[i][j-1])
          lt[i][j]=lt[i][j-1];
        else lt[i][j]=j-1;
      }
    }
    for(int j=1;j<=m;j++)
    {
      for(int i=2;i<=n;i++)
      {
        if(mt[i][j]==mt[i-1][j])
          up[i][j]=up[i-1][j];
        else up[i][j]=i-1;
      }
    }
    for(int j=1;j<=m;j++)
    {
      for(int i=n-1;i>=1;i--)
      {
        if(mt[i][j]==mt[i+1][j])
          dw[i][j]=dw[i+1][j];
        else dw[i][j]=i+1;
      }
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        bfs(i,j);
    int ans=inf;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        ans=min(ans,ds[s.size()][i][j]);
      }
    }
    cout<<ans+s.size()<<endl;
  }
  return 0;
}