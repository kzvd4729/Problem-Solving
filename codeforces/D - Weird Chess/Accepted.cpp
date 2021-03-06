/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2019 23:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/538/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int n,vis[N+2][N+2],mat[N+N+2][N+N+2];
string s[N+2];
bool ck(int dx,int dy)
{
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]=='o')
      {
        int ii=i+dx,jj=j+dy;
        if(ii>=0&&ii<n&&jj>=0&&jj<n)
        {
          if(s[ii][jj]=='.')return false;
          if(s[ii][jj]=='x')cnt++;
        }
      }
    }
  }
  if(cnt)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(s[i][j]=='o')
        {
          int ii=i+dx,jj=j+dy;
          if(ii>=0&&ii<n&&jj>=0&&jj<n)
          {
            if(s[ii][jj]=='x')vis[ii][jj]=1;
          }
        }
      }
    }
    return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>s[i];
  vector<pair<int,int> >ans;
  for(int i=-50;i<=50;i++)
  {
    for(int j=-50;j<=50;j++)
    {
      if(ck(i,j))ans.push_back({i,j});
    }
  }
  /*for(auto x:ans)
  {
    cout<<x.first<<" "<<x.second<<endl;
  }*/
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]=='x'&&vis[i][j]==0)
        cout<<"NO"<<endl,exit(0);
    }
  }
  cout<<"YES"<<endl;
  for(auto x:ans)
    mat[n+x.first][n+x.second]=1;
  for(int i=1;i<n+n;i++)
  {
    for(int j=1;j<n+n;j++)
    {
      if(i==n&&j==n)cout<<"o";
      else if(mat[i][j])cout<<'x';
      else cout<<".";
    }
    cout<<endl;
  }
  return 0;
}