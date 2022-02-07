/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-24 18:52:26                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-1714
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=51;
const int inf=1e9;
int n,m,dis[N+2][N+2][N+2][N+2],dp[10003][N+2][N+2];
int lt[N+2][N+2],rt[N+2][N+2],up[N+2][N+2],dw[N+2][N+2];
char mt[N+2][N+2];vector<pair<int,int> >pos[N+2];
string s;
void bfs(int si,int sj)
{
  queue<pair<int,int> >q;q.push({si,sj});
  dis[si][sj][si][sj]=0;
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    int i=p.first,j=p.second;
    if(rt[i][j]<=m)
    {
      if(dis[si][sj][i][j]+1<dis[si][sj][i][rt[i][j]])
      {
        dis[si][sj][i][rt[i][j]]=dis[si][sj][i][j]+1;
        q.push({i,rt[i][j]});
      }
    }
    if(lt[i][j]>=1)
    {
      if(dis[si][sj][i][j]+1<dis[si][sj][i][lt[i][j]])
      {
        dis[si][sj][i][lt[i][j]]=dis[si][sj][i][j]+1;
        q.push({i,lt[i][j]});
      }
    }
    if(up[i][j]>=1)
    {
      if(dis[si][sj][i][j]+1<dis[si][sj][up[i][j]][j])
      {
        dis[si][sj][up[i][j]][j]=dis[si][sj][i][j]+1;
        q.push({up[i][j],j});
      }
    }
    if(dw[i][j]<=n)
    {
      if(dis[si][sj][i][j]+1<dis[si][sj][dw[i][j]][j])
      {
        dis[si][sj][dw[i][j]][j]=dis[si][sj][i][j]+1;
        q.push({dw[i][j],j});
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>m)
  {
    map<char,int>mp;int cnt=0;
    for(int i=1;i<=N;i++)pos[i].clear();
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      for(int j=1;j<=m;j++)
      {
        mt[i][j]=s[j-1];
        if(!mp[mt[i][j]])
          mp[mt[i][j]]=++cnt;
        pos[mp[mt[i][j]]].push_back({i,j});
      }
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
        for(int ii=1;ii<=n;ii++)
          for(int jj=1;jj<=m;jj++)
            dis[i][j][ii][jj]=inf;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        bfs(i,j),dp[0][i][j]=inf;
    int ans=inf,id=mp[s[0]];
    for(auto x:pos[id])
    {
      dp[0][x.first][x.second]=dis[1][1][x.first][x.second];
    }
    for(int l=1;l<s.size();l++)
    {
      int a=mp[s[l-1]],b=mp[s[l]];
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          dp[l][i][j]=inf;
        }
      }
      if(a==b)
      {
        for(int i=1;i<=n;i++)
        {
          for(int j=1;j<=m;j++)
          {
            dp[l][i][j]=dp[l-1][i][j];
          }
        }
      }
      else
      {
        for(auto x:pos[a])
        {
          for(auto z:pos[b])
          {
            dp[l][z.first][z.second]=min(dp[l][z.first][z.second],dp[l-1][x.first][x.second]+dis[x.first][x.second][z.first][z.second]);
          }
        }
      }
    }
    //cout<<dis[1][1][3][2]<<endl;
    id=mp['*'];
    for(auto x:pos[id])
    {
      //cout<<x.first<<" "<<x.second<<endl;
      ans=min(ans,dp[s.size()-1][x.first][x.second]);
    }
    cout<<ans+s.size()<<endl;
  }
  return 0;
}