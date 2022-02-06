/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/25/2020 12:07                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 919 ms                                          memory_used: 55700 KB                             
*  problem: https://codeforces.com/contest/659/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int mt[N+2][N+2],sz[N+2][N+2],vs[N+2][N+2],n,m;
pair<int,int>par[N+2][N+2];
pair<int,int>get(int i,int j)
{
  if(par[i][j]==make_pair(i,j))return {i,j};
  return par[i][j]=get(par[i][j].first,par[i][j].second);
}
void dfs(int i,int j,int mn,int cnt)
{
  if(cnt==0)return ;
  if(i>n||i<1||j>m||j<1||vs[i][j]||mt[i][j]<mn)return ;
  cnt--;vs[i][j]=1;
  dfs(i+1,j,mn,cnt);dfs(i-1,j,mn,cnt);
  dfs(i,j+1,mn,cnt);dfs(i,j-1,mn,cnt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;long k;cin>>k;
  vector<vector<int> >v;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mt[i][j];
      v.push_back({mt[i][j],i,j});
    }
  }
  sort(v.begin(),v.end(),greater<vector<int> >());
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)par[i][j]={i,j},sz[i][j]=1;
  auto add=[&](int a,int b,int c,int d)
  {
    pair<int,int>p=get(c,d);
    if(p==make_pair(a,b))return ;
    sz[a][b]+=sz[p.first][p.second];
    par[p.first][p.second]={a,b};
  };
  for(auto x:v)
  {
    int i=x[1],j=x[2];
    if(vs[i+1][j])add(i,j,i+1,j);
    if(vs[i-1][j])add(i,j,i-1,j);
    if(vs[i][j+1])add(i,j,i,j+1);
    if(vs[i][j-1])add(i,j,i,j-1);
     vs[i][j]=1;
    if(k%x[0]==0&&k/x[0]<=sz[i][j])
    {
      cout<<"YES\n";memset(vs,0,sizeof(vs));
      dfs(i,j,x[0],k/x[0]);
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          if(vs[i][j])cout<<x[0]<<" ";
          else cout<<0<<" ";
        }
        cout<<"\n";
      }
      exit(0);
    }
  }
  cout<<"NO\n";
  return 0;
}