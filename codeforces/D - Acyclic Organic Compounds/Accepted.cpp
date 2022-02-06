/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2020 19:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 109500 KB                            
*  problem: https://codeforces.com/contest/601/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#define long long long
using namespace std;
const int N=7e5;
int vl[N+2],sz=1;string s;
vector<int>adj[N+2];
int tr[N+2][26],ds[N+2];
void merge(int a,int b)
{
  for(int i=0;i<26;i++)
  {
    if(tr[b][i]==0)continue;
    if(tr[a][i]==0)
    {
      tr[a][i]=tr[b][i];continue;
    }
    merge(tr[a][i],tr[b][i]);
  }
  ds[a]=1;
  for(int i=0;i<26;i++)
  {
    if(tr[a][i]==0)continue;
    if(tr[a][i])ds[a]+=ds[tr[a][i]];
  }
}
int mx=-1,cnt=0;
void upd(int x)
{
  if(x>mx)mx=x,cnt=1;else if(x==mx)cnt++;
}
int dfs(int node,int par)
{
  vector<int>rt;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    rt.push_back(dfs(x,node));
  }
  if(rt.size()==0)
  {
    int nd=++sz;
    tr[nd][s[node]-'a']=++sz;ds[sz]=1;
    ds[nd]=2;upd(1+vl[node]);return nd;
  }
  int now=-1,id;
  for(auto x:rt)if(ds[x]>now)now=ds[x],id=x;
  for(auto x:rt)if(x!=id)merge(id,x);
   int nd=++sz;ds[nd]=ds[id]+1;
  tr[nd][s[node]-'a']=id;
  upd(ds[nd]-1+vl[node]);return nd;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>vl[i];
  cin>>s;s="#"+s;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1);cout<<mx<<" "<<cnt<<endl;
   return 0;
}