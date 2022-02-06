/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2019 22:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1130/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int mt[N+2][N+2],n,r2,c2,vis[N+2][N+2],mrk[N+2][N+2];
int ans,r1,c1;
void dfs1(int i,int j)
{
  if(mt[i][j]||vis[i][j])return ;
  vis[i][j]=1;int ii,jj;
  ii=i+1,jj=j;if(ii<=n)dfs1(ii,jj);
  ii=i,jj=j+1;if(jj<=n)dfs1(ii,jj);
  ii=i-1,jj=j;if(ii>=1)dfs1(ii,jj);
  ii=i,jj=j-1;if(jj>=1)dfs1(ii,jj);
}
void dfs2(int i,int j)
{
  if(mt[i][j]||mrk[i][j])return ;
  mrk[i][j]=1;int ii,jj;
  ii=i+1,jj=j;if(ii<=n)dfs2(ii,jj);
  ii=i,jj=j+1;if(jj<=n)dfs2(ii,jj);
  ii=i-1,jj=j;if(ii>=1)dfs2(ii,jj);
  ii=i,jj=j-1;if(jj>=1)dfs2(ii,jj);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>r1>>c1>>r2>>c2;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=n;j++)
      mt[i][j]=s[j-1]-'0';
  }
  dfs1(r2,c2);dfs2(r1,c1);int ans=1e9;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(int a=1;a<=n;a++)
      {
        for(int b=1;b<=n;b++)
        {
          if(mrk[i][j]&&vis[a][b])
            ans=min(ans,(i-a)*(i-a)+(j-b)*(j-b));
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}