/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2018 15:27                        
*  solution_verdict: Time limit exceeded on test 15          language: GNU C++17                               
*  run_time: 10000 ms                                        memory_used: 23800 KB                             
*  problem: https://codeforces.com/contest/551/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=5e5;
int n,q,sq;
long lazy[1003],arr[N+2];
set<pair<long,int> >seg[1003];
void build(void)
{
  for(int i=1;i<=n;i++)
    seg[i/sq].insert({arr[i],i});
}
void upd(int lt,int rt,int xx)
{
  for(int i=0;i<=n/sq;i++)
  {
    int st=max(1,i*sq);
    int ed=min((i+1)*sq-1,n);
    if(ed<lt||st>rt)continue;
    else if(st>=lt&&ed<=rt)
      lazy[i]+=(xx*1LL);
    else
    {
      for(int j=max(st,lt);j<=min(ed,rt);j++)
      {
        if(j>=lt&&j<=rt)
        {
          seg[i].erase({arr[j],j});
          arr[j]+=(xx*1LL);
          seg[i].insert({arr[j],j});
        }
      }
    }
  }
}
int query(int yy)
{
  int lt=inf,rt=0;
  for(int i=0;i<=n/sq;i++)
  {
    if(yy-lazy[i]<0)continue;
    auto it=seg[i].upper_bound({yy-lazy[i]-1,inf});
    //auto it=upper_bound(seg[i].begin(),seg[i].end(),make_pair(yy-lazy[i]-1,inf));
    if(it!=seg[i].end())
    {
      if(it->first!=yy-lazy[i])continue;
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
  scanf("%d%d",&n,&q);
  for(int i=1;i<=n;i++)
    scanf("%lld",&arr[i]);
  sq=sqrt(n);
  build();
  while(q--)
  {
    int ty,l,r,x,y;
    scanf("%d",&ty);
    if(ty==1)
    {
      scanf("%d%d%d",&l,&r,&x);
      upd(l,r,x);
    }
    else
    {
      scanf("%d",&y);
      printf("%d\n",query(y));
    }
  }
  return 0;
}