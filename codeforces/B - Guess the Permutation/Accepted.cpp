/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2018 14:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/618/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int mat[N+2][N+2],n,ans[N+2],vis[N+2];
int _find(int nm)
{
  for(int i=1;i<=n;i++)
  {
    int f=0;if(vis[i])continue;
    for(int j=1;j<=n;j++)
    {
      if(mat[i][j]>nm)f=1;
    }
    if(f==0)return i;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>mat[i][j];
  for(int nm=1;nm<=n;nm++)
  {
    int id=_find(nm);
    ans[id]=nm;vis[id]=1;
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}