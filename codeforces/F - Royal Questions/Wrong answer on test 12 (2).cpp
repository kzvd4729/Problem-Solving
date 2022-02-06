/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 20:32                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2500 KB                              
*  problem: https://codeforces.com/contest/875/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int par[N+2],ck[N+2],vis[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<vector<int> >ed(m);
  for(int i=0;i<m;i++)
  {
    ed[i].resize(3);
    cin>>ed[i][1]>>ed[i][2]>>ed[i][0];
  }
  sort(ed.begin(),ed.end());reverse(ed.begin(),ed.end());
  for(int i=1;i<=n;i++)par[i]=i;int ans=0;
  for(int i=0;i<m;i++)
  {
    int r1=get(ed[i][1]),r2=get(ed[i][2]);
    if(r1!=r2)ans+=ed[i][0],par[r1]=r2;
    else ck[i]=1;
  }
  for(int i=0;i<m;i++)
  {
    if(!ck[i])continue;
    int r1=get(ed[i][1]),r2=get(ed[i][2]);
    if(r1!=r2)assert(0);
     if(!vis[r1])ans+=ed[i][0],vis[r1]=1;
  }
  cout<<ans<<endl;
  return 0;
}