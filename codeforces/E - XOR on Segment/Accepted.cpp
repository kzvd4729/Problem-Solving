/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2018 14:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1652 ms                                         memory_used: 36600 KB                             
*  problem: https://codeforces.com/contest/242/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,aa[N+2],seg[4*N+2][22],lazy[4*N+2];
void too_lazy(int node,int lo,int hi)
{
  if(!lazy[node])return ;
  for(int i=0;i<20;i++)
  {
    if(lazy[node]&(1<<i))
      seg[node][i]=hi-lo+1-seg[node][i];
  }
  if(lo!=hi)
  {
    lazy[node*2]^=lazy[node];
    lazy[node*2+1]^=lazy[node];
  }
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]=vl;too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);upd(node*2+1,md+1,hi,lt,rt,vl);
  for(int i=0;i<20;i++)
    seg[node][i]=seg[node*2][i]+seg[node*2+1][i];
}
vector<int>qry(int node,int lo,int hi,int lt,int rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)
  {
    vector<int>ret(20,0);return ret;
  }
  if(lo>=lt&&hi<=rt)
  {
    vector<int>ret;
    for(int i=0;i<20;i++)
      ret.push_back(seg[node][i]);
    return ret;
  }
  int md=(lo+hi)/2;
  vector<int>p1=qry(node*2,lo,md,lt,rt);
  vector<int>p2=qry(node*2+1,md+1,hi,lt,rt);
  vector<int>ret;
  for(int i=0;i<20;i++)
    ret.push_back(p1[i]+p2[i]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];upd(1,1,n,i,i,aa[i]);
  }
  int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int lt,rt;cin>>lt>>rt;
      vector<int>v=qry(1,1,n,lt,rt);
      long ans=0;
      for(int i=0;i<20;i++)
        ans+=(v[i]*1LL)*(1<<i);
      cout<<ans<<"\n";
    }
    else
    {
      int lt,rt,vl;cin>>lt>>rt>>vl;
      upd(1,1,n,lt,rt,vl);
    }
  }
  return 0;
}