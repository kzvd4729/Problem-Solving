/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 19:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 21900 KB                             
*  problem: https://codeforces.com/contest/1105/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=1e9+1;
int ex[N+2],n,m,k,cnt[N+2];
char mat[N+2][N+2];
vector<pair<int,int> >pos[N+2];
void bfs(int id)
{
  queue<pair<int,pair<int,int> > >q;
  vector<pair<int,int> >vv;
  for(auto x:pos[id])
    q.push({0,x});
  while(q.size())
  {
    pair<int,pair<int,int> >p=q.front();q.pop();
    if(p.first>=ex[id])continue;
    int i,j;int x=p.second.first,y=p.second.second;
    i=x+1,j=y;
    if(i<=n)
    {
      if(mat[i][j]=='.')
      {
        mat[i][j]=char(id+'0');
        q.push({p.first+1,{i,j}});
        vv.push_back({i,j});
      }
    }
    i=x-1,j=y;
    if(i>=1)
    {
      if(mat[i][j]=='.')
      {
        mat[i][j]=char(id+'0');
        q.push({p.first+1,{i,j}});
        vv.push_back({i,j});
      }
    }
    i=x,j=y+1;
    if(j<=m)
    {
      if(mat[i][j]=='.')
      {
        mat[i][j]=char(id+'0');
        q.push({p.first+1,{i,j}});
        vv.push_back({i,j});
      }
    }
    i=x,j=y-1;
    if(j>=1)
    {
      if(mat[i][j]=='.')
      {
        mat[i][j]=char(id+'0');
        q.push({p.first+1,{i,j}});
        vv.push_back({i,j});
      }
    }
  }
  pos[id]=vv;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
    cin>>ex[i];
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
    {
      mat[i][j]=s[j-1];
      if(mat[i][j]>='1'&&mat[i][j]<='9')
        pos[mat[i][j]-'0'].push_back({i,j});
    }
  }
  int f=1;
  while(f)
  {
    f=0;
    for(int i=1;i<=k;i++)
    {
      if(pos[i].size())
      {
        f=1;bfs(i);
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]>='1'&&mat[i][j]<='9')
        cnt[mat[i][j]-'0']++;
    }
  }
  for(int i=1;i<=k;i++)
    cout<<cnt[i]<<" ";
  cout<<endl;
  return 0;
}