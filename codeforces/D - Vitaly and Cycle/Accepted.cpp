/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 10:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 6900 KB                              
*  problem: https://codeforces.com/contest/557/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int dg[N+2];
vector<int>adj[N+2];
void case3(int n,int m)
{
  if(m)return ;
  cout<<3<<" "<<(1LL*n*(n-1)*(n-2))/6<<endl,exit(0);
}
void case2(int n,int m)
{
  for(int i=1;i<=n;i++)if(dg[i]>1)return ;
  cout<<2<<" "<<1LL*(n-2)*m<<endl,exit(0);
}
bool vs[N+2],f;int cl[N+2],cnt[2+2];
void dfs(int node,int c)
{
  if(vs[node]){if(cl[node]!=c)f=1;return ;}
  vs[node]=1;cl[node]=c;cnt[c]++;
  for(auto x:adj[node])
    dfs(x,c^1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;dg[u]++,dg[v]++;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  case3(n,m);case2(n,m);
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    if(vs[i])continue;cnt[0]=0,cnt[1]=0;
    dfs(i,0);//int mx=max(cnt[0],cnt[1]);
    ans+=(1LL*cnt[0]*(cnt[0]-1))/2;
    ans+=(1LL*cnt[1]*(cnt[1]-1))/2;
  }
  if(f)cout<<0<<" "<<1<<endl;
  else cout<<1<<" "<<ans<<endl;
  return 0;
}