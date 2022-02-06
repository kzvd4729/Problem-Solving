/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2021 23:40                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++17 (64)                          
*  run_time: 264 ms                                          memory_used: 71200 KB                             
*  problem: https://codeforces.com/contest/1491/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 vector<int>ad[N+2],nm[N+2];
int f[N+2],fib[N+2],vs[N+2],sub[N+2];
 void reckon(int nd,int pr)
{
  sub[nd]=1;
  int sz=ad[nd].size();
  for(int i=0;i<sz;i++)
  {
    if(ad[nd][i]==pr)continue;
    if(vs[nm[nd][i]])continue;
    reckon(ad[nd][i],nd);
    sub[nd]+=sub[ad[nd][i]];
  }
}
int a,b,id;
void dfs(int tt,int nd,int pr)
{
  int sz=ad[nd].size();
  for(int i=0;i<sz;i++)
  {
    int x=ad[nd][i];
    if(x==pr)continue;
    if(vs[nm[nd][i]])continue;
     if(fib[sub[x]]&&fib[tt-sub[x]])
    {
      a=nd,b=x,id=nm[nd][i];return ;
    }
    dfs(tt,x,nd);
  }
}
bool centroid(int nd)
{
  reckon(nd,-1);
  if(sub[nd]==1)return true;
  if(fib[sub[nd]]==0)return false;
   a=-1,b=-1;
  dfs(sub[nd],nd,-1);
  if(a==-1)return false;
   vs[id]=1;
  return (centroid(a)&centroid(b));
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   f[0]=1;
  f[1]=1;fib[1]=1;
  for(int i=2;i<=28;i++)
  {
    f[i]=f[i-1]+f[i-2];
    fib[f[i]]=1;
  }
  //cout<<f[26]<<endl;
   int n;cin>>n;
  if(fib[n]==0)cout<<"NO"<<endl,exit(0);
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
     nm[u].push_back(i);nm[v].push_back(i);
  }
  if(centroid(2))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
     return 0;
}