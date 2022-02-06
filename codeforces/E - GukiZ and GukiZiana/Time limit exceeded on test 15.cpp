/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2018 15:21                        
*  solution_verdict: Time limit exceeded on test 15          language: GNU C++14                               
*  run_time: 10000 ms                                        memory_used: 23800 KB                             
*  problem: https://codeforces.com/contest/551/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e9;
const long N=5e5;
long n,q,arr[N+2],sq;
long lazy[1003];
set<pair<long,long> >seg[1003];
void build(void)
{
  for(long i=1;i<=n;i++)
    seg[i/sq].insert({arr[i],i});
}
void upd(long lt,long rt,long xx)
{
  for(long i=0;i<=n/sq;i++)
  {
    long st=max(1LL,i*sq);
    long ed=min((i+1)*sq-1,n);
    if(ed<lt||st>rt)continue;
    else if(st>=lt&&ed<=rt)
      lazy[i]+=xx;
    else
    {
      for(long j=max(st,lt);j<=min(ed,rt);j++)
      {
        if(j>=lt&&j<=rt)
        {
          seg[i].erase({arr[j],j});
          arr[j]+=xx;
          seg[i].insert({arr[j],j});
        }
      }
    }
  }
}
long query(long yy)
{
  long lt=inf,rt=0;
  for(long i=0;i<=n/sq;i++)
  {
    auto it=seg[i].upper_bound({yy-lazy[i]-1,inf});
    //auto it=upper_bound(seg[i].begin(),seg[i].end(),make_pair(yy-lazy[i]-1,inf));
    if(it!=seg[i].end())
    {
      if(it->first==yy-lazy[i])
        lt=min(lt,it->second);
    }
    //auto iit=upper_bound(seg[i].begin(),seg[i].end(),make_pair(yy-lazy[i],inf));
    auto iit=seg[i].upper_bound({yy-lazy[i],inf});
    if(iit==seg[i].begin())continue;
    iit--;
    if(it->first==yy-lazy[i])
      rt=max(rt,iit->second);
  }
  if(lt==inf)return -1;
  return rt-lt;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  sq=sqrt(n);
  build();
  while(q--)
  {
    long ty,l,r,x,y;
    cin>>ty;
    if(ty==1)
    {
      cin>>l>>r>>x;
      upd(l,r,x);
    }
    else
    {
      cin>>y;
      cout<<query(y)<<"\n";
    }
  }
  return 0;
}