/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2019 19:58                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/594/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int vis[N+2],aa[N+2],fir[N+2],last[N+2];
vector<int>v[N+2];
long seg[5*N+2];
pair<int,int>pp[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
void factorize(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      v[j].push_back(i);
      vis[j]=1;
    }
  }
}
void upd(int node,int lo,int hi,int id,long vl)
{
  if(lo==hi)
  {
    seg[node]=(seg[node]*vl)%mod;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=(seg[node*2]*seg[node*2+1])%mod;
}
long qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 1;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return (qry(node*2,lo,md,lt,rt)*qry(node*2+1,md+1,hi,lt,rt))%mod;
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  factorize();int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=5*n;i++)seg[i]=1;
   int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    cin>>fir[i];
    cin>>pp[i].first;pp[i].second=i;
  }
  sort(pp+1,pp+n+1);
  for(int i=1;i<=n;i++)
  {
    int id=pp[i].second;
    for(auto x:v[aa[i]])
    {
      if(!last[x])upd
    }
  }
  return 0;
}