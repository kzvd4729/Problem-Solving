/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-30 19:03:37                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-STRLCP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long b1=29,b2=31,mod1=1e9+7,mod2=1e9+9;
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret%mod;
}
struct treap
{
  long l,r,prio,sz;
  long h1,h2;
  char c;
}st[N+2];
void _sz(long node)
{
  if(!node)return ;
  st[node].h1=st[st[node].l].h1+(bigmod(b1,st[st[node].l].sz+1,mod1)*((long)st[node].c+st[st[node].r].h1))%mod1;
  st[node].h2=st[st[node].l].h2+(bigmod(b2,st[st[node].l].sz+1,mod2)*((long)st[node].c+st[st[node].r].h2))%mod2;
  st[node].sz=st[st[node].l].sz+st[st[node].r].sz+1;
}
pair<long,long>split_sz(long node,long ss)
{
  if(!node)return {0,0};
  if(st[node].sz<=ss)return {node,0};
  if(!ss)return {0,node};
  if(st[st[node].l].sz>=ss)
  {
    pair<long,long>ret=split_sz(st[node].l,ss);
    st[node].l=ret.second;_sz(node);
    return {ret.first,node};
  }
  else
  {
    pair<long,long>ret=split_sz(st[node].r,ss-st[st[node].l].sz-1);
    st[node].r=ret.first;_sz(node);
    return {node,ret.second};
  }
}
long join(long lt,long rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(st[lt].prio>=st[rt].prio)
  {
    st[lt].r=join(st[lt].r,rt);_sz(lt);
    return lt;
  }
  else
  {
    st[rt].l=join(lt,st[rt].l);_sz(rt);
    return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    string s;cin>>s;long root=0,nw=0,sum=0;
    for(auto x:s)
    {
      ++nw;st[nw]={0,0,rand(),1,b1*(long)x,b2*(long)x,x};
      root=join(root,nw);
    }
    long q;cin>>q;
    while(q--)
    {
      char ch;cin>>ch;
      if(ch=='Q')
      {
        long l,r;cin>>l>>r;if(r<l)swap(l,r);
        long hi=s.size()-r,lo=0,md,ans=0;
        while(lo<=hi)
        {
          md=(lo+hi)/2;

          pair<long,long>p=split_sz(root,l+md);
          long hs1=st[p.first].h1,hs2=st[p.first].h2;
          root=join(p.first,p.second);
          p=split_sz(root,l-1);
          hs1=(hs1-st[p.first].h1+mod1)%mod1;hs2=(hs2-st[p.first].h2+mod2)%mod2;
          root=join(p.first,p.second);

          hs1=(hs1*bigmod(bigmod(b1,l-1,mod1),mod1-2,mod1))%mod1;
          hs2=(hs2*bigmod(bigmod(b2,l-1,mod2),mod2-2,mod2))%mod2;

          p=split_sz(root,r+md);
          long hh1=st[p.first].h1,hh2=st[p.first].h2;
          root=join(p.first,p.second);
          p=split_sz(root,r-1);
          hh1=(hh1-st[p.first].h1+mod1)%mod1;hh2=(hh2-st[p.first].h2+mod2)%mod2;
          root=join(p.first,p.second);

          hh1=(hh1*bigmod(bigmod(b1,r-1,mod1),mod1-2,mod1))%mod1;
          hh2=(hh2*bigmod(bigmod(b2,r-1,mod2),mod2-2,mod2))%mod2;

          if(hs1==hh1&&hs2==hh2)ans=md+1,lo=md+1;
          else hi=md-1;
        }
        printf("%lld\n",ans);
      }
      else if(ch=='R')
      {
        int po;char cc;cin>>po>>cc;
        pair<int,int>p1=split_sz(root,po);
        pair<int,int>p2=split_sz(p1.first,po-1);
        ++nw;st[nw]={0,0,rand(),1,b1*(long)cc,b2*(long)cc,cc};
        root=join(p2.first,nw);root=join(root,p1.second);
      }
      else
      {
        int po;char cc;cin>>po>>cc;
        pair<int,int>p=split_sz(root,po);
        ++nw;st[nw]={0,0,rand(),1,b1*(long)cc,b2*(long)cc,cc};
        root=join(p.first,nw);root=join(root,p.second);
      }
    }
  }
  return 0;
}