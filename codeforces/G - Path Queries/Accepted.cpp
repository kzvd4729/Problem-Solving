/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/30/2019 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 17300 KB                             
*  problem: https://codeforces.com/contest/1213/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int par[N+2],sz[N+2];long ans[N+2];
vector<vector<int> >ed;
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    vector<int>v(3);
    cin>>v[1]>>v[2]>>v[0];
    ed.push_back(v);
  }
  sort(ed.begin(),ed.end());
  for(int i=1;i<=n;i++)
    par[i]=i,sz[i]=1;
  long cur=0;
  for(auto x:ed)
  {
    int r1=_find(x[1]),r2=_find(x[2]);
    if(r1==r2)assert(0);
    cur+=(1LL*sz[r1]*sz[r2]);
    par[r1]=r2;sz[r2]+=sz[r1];
    ans[x[0]]=cur;
  }
  for(int i=1;i<=N;i++)
    ans[i]=max(ans[i],ans[i-1]);
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;cout<<ans[x]<<" ";
  }
  cout<<endl;
  return 0;
}