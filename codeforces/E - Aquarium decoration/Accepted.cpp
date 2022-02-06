/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2020 19:21                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 530 ms                                          memory_used: 98000 KB                             
*  problem: https://codeforces.com/contest/799/problem/E
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
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const long N=1e6,inf=2e16+1;
long tr;
struct treap
{
  long lt,rt,dt,pri,sz,sm;
}bst[N+2];
void cal(long node)
{
  if(node==0)return;
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;
  bst[node].sm=bst[bst[node].lt].sm+bst[bst[node].rt].sm+bst[node].dt;
}
//left tree will contain value <= vl.
pair<long,long>splitbyValue(long node,long vl)
{
  if(!node)return {0,0};pair<long,long>p;
  if(bst[node].dt<=vl)
  {
    p=splitbyValue(bst[node].rt,vl);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
  else
  {
    p=splitbyValue(bst[node].lt,vl);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
}
pair<long,long>splitbySize(long node,long ss)
{
  if(!node)return {0,0};pair<long,long>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=splitbySize(bst[node].lt,ss);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
  else
  {
    p=splitbySize(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
}
//lt and rt are bst and max element of lt <= minimum of rt
long join(long lt,long rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
long qb[N+2],qc[N+2];
vector<pair<long,long> >ta,tb,tc,td;
long arc[N+2],mis[N+2],ccc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,k;cin>>n>>m>>k;vector<long>a,b,c;long root=0;
   for(long i=1;i<=n;i++)cin>>ccc[i];
  long x;cin>>x;
  for(long i=1;i<=x;i++){long z;cin>>z;arc[z]=1;}
  cin>>x;
  for(long i=1;i<=x;i++){long z;cin>>z;mis[z]=1;}
   for(long i=1;i<=n;i++)
  {
    long x,y,z;
    x=ccc[i],y=arc[i],z=mis[i];
    if(y&&z)
    {
      bst[++tr]={0,0,x,rand(),1,x};
      pair<long,long>p=splitbyValue(root,x);
      root=join(p.first,tr);root=join(root,p.second);
       a.push_back(x),ta.push_back({x,i});
    }
    else if(y)b.push_back(x),tb.push_back({x,i});
    else if(z)c.push_back(x),tc.push_back({x,i});
    else 
    {
      bst[++tr]={0,0,x,rand(),1,x};
      pair<long,long>p=splitbyValue(root,x);
      root=join(p.first,tr);root=join(root,p.second);
       td.push_back({x,i});
    }
  }
  //cout<<bst[root].sm<<endl;
  sort(a.begin(),a.end()),sort(b.begin(),b.end()),sort(c.begin(),c.end());
    for(long i=k;i<b.size();i++)
  {
    long x=b[i];
    bst[++tr]={0,0,x,rand(),1,x};
    pair<long,long>p=splitbyValue(root,x);
    root=join(p.first,tr);root=join(root,p.second);
  }
  for(long i=k;i<c.size();i++)
  {
    long x=c[i];
    bst[++tr]={0,0,x,rand(),1,x};
    pair<long,long>p=splitbyValue(root,x);
    root=join(p.first,tr);root=join(root,p.second);
  }
  if(b.size())qb[0]=b[0];
  for(long i=1;i<b.size();i++)qb[i]=qb[i-1]+b[i];
  if(c.size())qc[0]=c[0];
  for(long i=1;i<c.size();i++)qc[i]=qc[i-1]+c[i];
   long ans=inf,pr=-2;
  if(k+k<=m&&b.size()>=k&&c.size()>=k)
  {
    long now=qb[k-1]+qc[k-1];
    pair<long,long>p=splitbySize(root,m-(k+k));
    now+=bst[p.first].sm;root=join(p.first,p.second);
     ans=now,pr=-1;
  }
  long cr=0;
  for(long i=0;i<min((long)a.size(),k);i++)
  {
    cr+=a[i];long dl=k-1-i;
     pair<long,long>r=splitbyValue(root,a[i]-1);
    pair<long,long>l=splitbySize(r.second,1);
    root=join(r.first,l.second);
     if(dl<b.size())
    {
      long x=b[dl];
      bst[++tr]={0,0,x,rand(),1,x};
      pair<long,long>p=splitbyValue(root,x);
      root=join(p.first,tr);root=join(root,p.second);
    }
    if(dl<c.size())
    {
      long x=c[dl];
      bst[++tr]={0,0,x,rand(),1,x};
      pair<long,long>p=splitbyValue(root,x);
      root=join(p.first,tr);root=join(root,p.second);
    }
    if(b.size()>=dl&&c.size()>=dl&&m>=dl+dl+i+1)
    {
      long ad1=0,ad2=0;
      if(dl)ad1=qb[dl-1],ad2=qc[dl-1];
      pair<long,long>p=splitbySize(root,m-(dl+dl+i+1));
      long now=ad1+ad2+cr+bst[p.first].sm;root=join(p.first,p.second);
      if(now<ans)ans=now,pr=i;
    }
  }
  if(ans==inf)cout<<-1<<endl,exit(0);
  cout<<ans<<endl;
   return 0;
}