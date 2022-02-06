/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2020 16:45                        
*  solution_verdict: Time limit exceeded on test 13          language: GNU C++17                               
*  run_time: 2500 ms                                         memory_used: 77300 KB                             
*  problem: https://codeforces.com/contest/1088/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=5e5,inf=1e9+1;
int l[N+2],r[N+2],a[N+2];
vector<int>adj[N+2];
int sg[4*N+8];
void upd(int nd,int lo,int hi,int id,int vl)
{
  if(lo==hi){sg[nd]=vl;return;}
  int md=(lo+hi)/2;
  if(id<=md)upd(nd*2,lo,md,id,vl);
  else upd(nd*2+1,md+1,hi,id,vl);
  sg[nd]=min(sg[nd*2],sg[nd*2+1]);
}
int get(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)return sg[nd];
  int md=(lo+hi)/2;
  return min(get(nd*2,lo,md,lt,rt),get(nd*2+1,md+1,hi,lt,rt));
}
long ans;int n;
void dfs(int nd,int pr,int d)
{
  if(d)
  {
    long now=1LL*inf*inf;
    for(int i=0;i<=20;i++)
    {
      int lt=d-r[i],rt=d-l[i];
      if(rt<0)break;lt=max(0,lt);
      int ot=get(1,0,n-1,lt,rt);
      now=min(now,ot+a[nd]+1LL*min(ot,a[nd])*i);
    }
    ans+=now;
  }
  upd(1,0,n-1,d,a[nd]);
  for(auto x:adj[nd])
    if(x!=pr)dfs(x,nd,d+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  l[0]=r[0]=1;l[1]=r[1]=2;
  for(int i=2;i<=20;i++)
  {
    l[i]=(1<<(i-1))+1;
    r[i]=(1<<i);
  }
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  //for(int i=0;i<=5;i++)cout<<l[i]<<" "<<r[i]<<endl;
  int mn=inf,r;
  for(int i=1;i<=n;i++)if(a[i]<mn)mn=a[i],r=i;
  dfs(r,-1,0);cout<<ans<<endl;
  return 0;
}