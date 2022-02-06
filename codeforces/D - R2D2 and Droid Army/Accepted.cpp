/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2019 18:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 47000 KB                             
*  problem: https://codeforces.com/contest/514/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[6][N+2],par[6][N+2],ans[6];
inline int get(int x,int j)
{
  if(x==par[j][x])return x;
  return par[j][x]=get(par[j][x],j);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;stack<int>st[6];
  int mx=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>aa[j][i];
      while(st[j].size()&&aa[j][st[j].top()]<=aa[j][i])
        par[j][st[j].top()]=i,st[j].pop();
      par[j][i]=i;st[j].push(i);
    }
    int lo=1,hi=i,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;int sm=0;
      for(int j=1;j<=m;j++)
        sm+=aa[j][get(md,j)];
      if(sm<=k)hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      int sm=0;
      for(int j=1;j<=m;j++)
        sm+=aa[j][get(md,j)];
      if(sm<=k)break;
    }
    int ln=i-md+1;
    if(ln>mx)
    {
      mx=ln;
      for(int j=1;j<=m;j++)
        ans[j]=aa[j][get(md,j)];
    }
  }
  for(int i=1;i<=m;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}