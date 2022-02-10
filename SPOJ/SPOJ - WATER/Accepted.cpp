/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-22 20:11:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3680                                       memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-WATER
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int mt[N+2][N+2],n,m,vis[N+2][N+2],mrk[N+2][N+2];
vector<pair<int,int> >v;
void dfs(int i,int j,int vl)
{
  v.push_back({i,j});mrk[i][j]=1;
  for(int k=0;k<4;k++)
  {
    int ii=i+dx[k],jj=j+dy[k];
    if(mt[ii][jj]==vl&&vis[ii][jj]==0&&mrk[ii][jj]==0)
      dfs(ii,jj,vl);
  }
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
        cin>>mt[i][j];
      }
    }
    memset(vis,0,sizeof(vis));
    memset(mrk,0,sizeof(mrk));
    for(int j=1;j<=m;j++)
      vis[1][j]=1,vis[n][j]=1;
    for(int i=1;i<=n;i++)
      vis[i][1]=1,vis[i][m]=1;
    int ans=0,prv=0;
    while(true)
    {
      for(int i=2;i<n;i++)
      {
        for(int j=2;j<m;j++)
        {
          dfs(i,j,mt[i][j]);
          int mn=1e9;
          for(auto x:v)
          {
            for(int k=0;k<4;k++)
            {
              int ii=x.first+dx[k],jj=x.second+dy[k];
              if(mrk[ii][jj])continue;
              mn=min(mn,mt[ii][jj]);
            }
          }
          if(mn<=mt[i][j])mn=mt[i][j];
          ans+=v.size()*(mn-mt[i][j]);
          while(v.size())
          {
            mrk[v.back().first][v.back().second]=0;
            mt[v.back().first][v.back().second]=mn;
            v.pop_back();
          }
        }
      }
      if(ans==prv)break;prv=ans;
    }
    cout<<ans<<endl;
  }
  return 0;
}