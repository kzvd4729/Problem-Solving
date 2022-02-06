/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 17:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1762 ms                                         memory_used: 173800 KB                            
*  problem: https://codeforces.com/contest/1106/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
struct data
{
  int s,e,d,w;
}aa[N+2];int n;long dp[N+1][201];
pair<int,int>seg[5*N+2],lazy[5*N+2],pp[N+2];
void too_lazy(int node,int lo,int hi)
{
  if(lazy[node].first>seg[node].first)
    seg[node]=lazy[node];
  else if(lazy[node].first==seg[node].first)
    seg[node].second=max(seg[node].second,lazy[node].second);
  if(lo!=hi)
  {
    if(lazy[node].first>lazy[node*2].first)
      lazy[node*2]=lazy[node];
    else if(lazy[node].first==lazy[node*2].first)
      lazy[node*2].second=max(lazy[node*2].second,lazy[node].second);
     if(lazy[node].first>lazy[node*2+1].first)
      lazy[node*2+1]=lazy[node];
    else if(lazy[node].first==lazy[node*2+1].first)
      lazy[node*2+1].second=max(lazy[node*2+1].second,lazy[node].second);
  }
}
void upd(int node,int lo,int hi,int lt,int rt,int vl,int id)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]={vl,id};too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl,id);
  upd(node*2+1,md+1,hi,lt,rt,vl,id);
  pair<int,int>p1=seg[node*2],p2=seg[node*2+1],p;
  if(p1.first>p2.first)p=p1;
  else if(p2.first>p1.first)p=p2;
  else p={p1.first,max(p1.second,p2.second)};
  seg[node]=p;
}
pair<int,int>qry(int node,int lo,int hi,int id)
{
  too_lazy(node,lo,hi);
  if(lo==hi)return seg[node];
  int md=(lo+hi)/2;
  if(id<=md)return qry(node*2,lo,md,id);
  else return qry(node*2+1,md+1,hi,id);
}
long dfs(int st,int m)
{
  if(st>n)return 0;
  if(dp[st][m]!=-1)return dp[st][m];
  long now=1e18;
  if(m)now=min(now,dfs(st+1,m-1));
  now=min(now,pp[st].first*1LL+dfs(pp[st].second+1,m));
  return dp[st][m]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int m,k;cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
    cin>>aa[i].s>>aa[i].e>>aa[i].d>>aa[i].w;
    upd(1,1,n,aa[i].s,aa[i].e,aa[i].w,aa[i].d);
  }
  for(int i=1;i<=n;i++)
  {
    pp[i]=qry(1,1,n,i);
    pp[i].second=max(pp[i].second,i);
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,m)<<endl;
  return 0;
}