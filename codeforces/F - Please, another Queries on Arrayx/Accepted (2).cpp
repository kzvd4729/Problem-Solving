/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2020 19:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 5148 ms                                         memory_used: 48600 KB                             
*  problem: https://codeforces.com/contest/1114/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5,mod=1e9+7;
bool isPrime(int x)
{
  for(int i=2;i<x;i++)if(x%i==0)return false;
  return true;
}
#define lft node*2
#define rgt node*2+1
long dor[5*N+2],con[300+2],ms[5*N+2];int ml[5*N+2],lz[5*N+2],aa[N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    ml[node]=aa[lo];dor[node]=con[aa[lo]];
    return ;
  }
  int md=(lo+hi)/2;
  build(lft,lo,md);build(rgt,md+1,hi);
   dor[node]=dor[lft]|dor[rgt];
  ml[node]=(1LL*ml[lft]*ml[rgt])%mod;
}
int big(int b,int p)
{
  //if(b==1)return b;
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
void tooLazy(int node,int lo,int hi)
{
  if(lz[node]==1)return ;
  ml[node]=(1LL*ml[node]*big(lz[node],hi-lo+1))%mod;
  dor[node]|=ms[node];
   if(lo!=hi)
  {
    lz[lft]=(1LL*lz[lft]*lz[node])%mod;
    lz[rgt]=(1LL*lz[rgt]*lz[node])%mod;
     ms[lft]|=ms[node];ms[rgt]|=ms[node];
  }
  lz[node]=1,ms[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(node,lo,hi);if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[node]=vl;ms[node]=con[vl];tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(lft,lo,md,lt,rt,vl);upd(rgt,md+1,hi,lt,rt,vl);
   dor[node]=dor[lft]|dor[rgt];
  ml[node]=(1LL*ml[lft]*ml[rgt])%mod; 
}
pair<int,long>get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {1,0};
  tooLazy(node,lo,hi);
  if(lo>=lt&&hi<=rt)return {ml[node],dor[node]};
  int md=(lo+hi)/2;
  pair<int,long>a=get(lft,lo,md,lt,rt);
  pair<int,long>b=get(rgt,md+1,hi,lt,rt);
   return {(1LL*a.first*b.first)%mod,a.second|b.second}; 
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int id=0;vector<int>v;
  for(int i=2;i<=300;i++)
    if(isPrime(i))v.push_back(i);
  for(int i=2;i<=300;i++)
  {
    for(int j=0;j<v.size();j++)
      if((i%v[j])==0)con[i]|=(1LL<<(j*1LL));
  }
  for(int i=0;i<5*N+2;i++)lz[i]=1;
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];build(1,1,n);
  while(m--)
  {
    string s;cin>>s;
    if(s=="MULTIPLY")
    {
      int l,r,vl;cin>>l>>r>>vl;
      upd(1,1,n,l,r,vl);
    }
    else
    {
      int l,r;cin>>l>>r;
      pair<int,long>p=get(1,1,n,l,r);
      int ans=p.first;
      for(int j=0;j<v.size();j++)
      {
        if(p.second&(1LL<<j))
          ans=(ans*((1LL*(v[j]-1)*big(v[j],mod-2))%mod))%mod;
      }
      cout<<ans<<"\n";
    }
  }
  return 0;
}