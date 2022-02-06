/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 18:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 22100 KB                             
*  problem: https://codeforces.com/contest/1328/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>adj[N+2];int lv[N+2],p[N+2],ent[N+2],ext[N+2],tim;
void dfs(int node,int par,int l)
{
  p[node]=par,lv[node]=l;ent[node]=++tim;
  for(auto x:adj[node])
  {
    if(x!=par)dfs(x,node,l+1);
  }
  ext[node]=tim;
}
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,0,0);p[1]=1;
  while(m--)
  {
    int x;cin>>x;
    for(int i=1;i<=x;i++)
      cin>>aa[i];
    sort(aa+1,aa+x+1,[](int a,int b){
      return lv[a]<lv[b];
    });
    // for(int i=1;i<=x;i++)cout<<aa[i]<<" ";
    //   cout<<endl;
    aa[0]=1;int f=0;
    for(int i=1;i<=x;i++)
    {
      int pr=p[aa[i-1]];
      if(ent[aa[i]]>=ent[pr]&&ent[aa[i]]<=ext[pr]);
      else f=1;
    }
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}