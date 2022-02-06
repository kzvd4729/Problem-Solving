/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2018 14:24                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
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
  cin>>n;set<int>st;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>mat[i][j];
      st.insert(mat[i][j]);
    }
  }
  while(st.size())
  {
    int nm=*st.begin();
    st.erase(nm);int id=_find(nm);
    ans[id]=nm;vis[id]=1;
  }
  for(int i=1;i<=n;i++)
  {
    if(ans[i]==0)ans[i]=n;
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}