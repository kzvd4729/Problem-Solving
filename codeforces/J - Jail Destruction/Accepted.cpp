/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 18:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 26600 KB                             
*  problem: https://codeforces.com/gym/102307/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long sum[4*N+2],mn[4*N+2],lazy[4*N+2],num[4*N+2],aa[N+2];
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    sum[node]=aa[lo];mn[node]=aa[lo];
    num[node]=1;return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  sum[node]=sum[node*2]+sum[node*2+1];
  mn[node]=min(mn[node*2],mn[node*2+1]);
  num[node]=num[node*2]+num[node*2+1];
}
void too_lazy(long node,long lo,long hi)
{
  if(lazy[node]==0)return ;
  sum[node]-=num[node]*lazy[node];
  mn[node]-=lazy[node];
  lazy[node*2]+=lazy[node];
  lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void upd(long node,long lo,long hi,long lt,long rt,long vl)
{
  too_lazy(node,lo,hi);
  if(num[node]==0)return ;
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    if(mn[node]>vl)
    {
      lazy[node]+=vl;
      too_lazy(node,lo,hi);
      return ;
    }
    if(lo==hi)
    {
      sum[node]=0;num[node]=0;mn[node]=0;
      return ;
    }
  }
  long md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
   sum[node]=sum[node*2]+sum[node*2+1];
  num[node]=num[node*2]+num[node*2+1];
  if(num[node*2]==0)mn[node]=mn[node*2+1];
  else if(num[node*2+1]==0)mn[node]=mn[node*2];
  else mn[node]=min(mn[node*2],mn[node*2+1]);
}
long get(long node,long lo,long hi,long lt,long rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return sum[node];
  long md=(lo+hi)/2;
  return get(node*2,lo,md,lt,rt)+get(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,q;cin>>n>>q;
  for(long i=1;i<=n;i++)cin>>aa[i];
  build(1,1,n);
  while(q--)
  {
    long ty;cin>>ty;
    if(ty==1)
    {
      long lt,rt;cin>>lt>>rt;
      //if(lt>rt)swap(lt,rt);/////////
      if(lt<=rt)cout<<get(1,1,n,lt,rt)<<"\n";
      else cout<<get(1,1,n,lt,n)+get(1,1,n,1,rt)<<"\n";
    }
    else
    {
      long lt,rt,vl;cin>>lt>>rt>>vl;
      //if(lt>rt)swap(lt,rt);/////////
      if(lt<=rt)upd(1,1,n,lt,rt,vl);
      else {upd(1,1,n,lt,n,vl);upd(1,1,n,1,rt,vl);}
    }
  }
  return 0;
}