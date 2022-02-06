/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2021 00:14                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 48000 KB                             
*  problem: https://codeforces.com/contest/1491/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int f[N+2],fib[N+2],sub[N+2];
set<int>ad[N+2];
void reckon(int nd,int pr)
{
  sub[nd]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    reckon(x,nd);sub[nd]+=sub[x];
  }
}
int a,b,id;
void dfs(int ind,int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
     if(fib[sub[x]]==ind-1||fib[sub[x]]==ind-2)
    {
      a=nd,b=x;return ;
    }
    dfs(ind,x,nd);
  }
}
bool centroid(int nd)
{
  reckon(nd,-1);
  if(sub[nd]<=3)return true;
   a=-1;dfs(fib[sub[nd]],nd,-1);
  if(a==-1)return false;
   ad[a].erase(b);ad[b].erase(a);
  return (centroid(a)&&centroid(b));
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   f[0]=1;
  f[1]=1;fib[1]=1;
  for(int i=2;i<=100;i++)
  {
    f[i]=f[i-1]+f[i-2];
    if(f[i]>N)break;
    fib[f[i]]=i;
  }
   int n;cin>>n;
  if(fib[n]==0)cout<<"NO"<<endl,exit(0);
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].insert(v);ad[v].insert(u);
  }
  if(centroid(1))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
     return 0;
}