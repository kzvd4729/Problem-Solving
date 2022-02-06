/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2021 18:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 452 ms                                          memory_used: 59900 KB                             
*  problem: https://codeforces.com/contest/1491/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 set<int>ad[N+2];
int f[N+2],ln[N+2],fib[N+2],vs[N+2],sub[N+2],pt,an[N+2];
 void no()
{
  cout<<"NO"<<endl,exit(0);
}
void reckon(int nd,int pr)
{
  sub[nd]=1;ln[++pt]=nd;an[nd]=pr;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    reckon(x,nd);sub[nd]+=sub[x];
  }
}
bool centroid(int nd)
{
  pt=0;reckon(nd,-1);
  if(fib[sub[nd]]==0)no();
  if(sub[nd]<=3)return true;
   int a=-1;
  for(int i=1;i<=pt;i++)
  {
    int u=ln[i];
    if(fib[sub[u]]&&fib[sub[nd]-sub[u]])
    {
      a=u;break;
    }
  }
  if(a==-1)no();int b=an[a];
  ad[a].erase(b);ad[b].erase(a);
  return (centroid(a)&centroid(b));
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   f[0]=1;
  f[1]=1;fib[1]=1;
  for(int i=2;i<=26;i++)
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
    ad[u].insert(v);ad[v].insert(u);
  }
  if(centroid(1))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
     return 0;
}