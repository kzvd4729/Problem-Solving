/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-08 18:25:47                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 233 ms                                          memory_used: 5232 KB                              
*  problem: https://atcoder.jp/contests/abc109/tasks/abc109_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int mat[505][505];
struct data
{
  int a,b,c,d;
};
vector<data>ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<m;j++)
    {
      if(mat[i][j]%2)
      {
        ans.push_back({i,j,i,j+1});
        mat[i][j+1]++;
      }
    }
  }
  for(int i=1;i<n;i++)
  {
    if(mat[i][m]%2)
    {
      ans.push_back({i,m,i+1,m});
      mat[i+1][m]++;
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x.a<<" "<<x.b<<" "<<x.c<<" "<<x.d<<endl;
  return 0;
}