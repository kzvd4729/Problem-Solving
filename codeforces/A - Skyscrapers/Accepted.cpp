/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/08/2019 15:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 608 ms                                          memory_used: 13500 KB                             
*  problem: https://codeforces.com/contest/1137/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int mt[N+2][N+2];
vector<int>row[N+2],col[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mt[i][j];
      row[i].push_back(mt[i][j]);
      col[j].push_back(mt[i][j]);
    }
  }
  for(int i=1;i<=n;i++)
  {
    sort(row[i].begin(),row[i].end());
    row[i].erase(unique(row[i].begin(),row[i].end()),row[i].end());
  }
  for(int i=1;i<=m;i++)
  {
    sort(col[i].begin(),col[i].end());
    col[i].erase(unique(col[i].begin(),col[i].end()),col[i].end());
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      int a=row[i].size(),b=col[j].size();
      int mx=max(a,b);
      int rl1=lower_bound(row[i].begin(),row[i].end(),mt[i][j])-row[i].begin();
      int rl2=lower_bound(col[j].begin(),col[j].end(),mt[i][j])-col[j].begin();
      int rl=max(rl1,rl2)+1;
       a=rl+a-rl1-1;b=rl+b-rl2-1;
      mx=max(mx,max(a,b));
      cout<<mx<<" ";
    }
    cout<<"\n";
  }
  return 0;
}