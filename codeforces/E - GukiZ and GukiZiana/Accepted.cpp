/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2018 15:54                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 4102 ms                                         memory_used: 15500 KB                             
*  problem: https://codeforces.com/contest/551/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=5e5;
int n,q,sq;
long lazy[1003],arr[N+2];
vector<pair<long,int> >seg[1003];
void build(void)
{
  for(int i=1;i<=n;i++)
    seg[i/sq].push_back({arr[i],i});
  for(int i=0;i<=n/sq;i++)
    sort(seg[i].begin(),seg[i].end());
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
      for(int j=0;j<seg[i].size();j++)
      {
        if(seg[i][j].second>=lt&&seg[i][j].second<=rt)
          seg[i][j].first+=xx;
      }
      sort(seg[i].begin(),seg[i].end());
    }
  }
}
int query(int yy)
{
  int lt=inf,rt=0;
  for(int i=0;i<=n/sq;i++)
  {
    if(yy-lazy[i]<0)continue;
    int it=upper_bound(seg[i].begin(),seg[i].end(),make_pair(yy-lazy[i]-1,inf))-seg[i].begin();
    if(it<seg[i].size())
    {
      if(seg[i][it].first!=yy-lazy[i])continue;
      lt=min(lt,seg[i][it].second);
    }
    it=upper_bound(seg[i].begin(),seg[i].end(),make_pair(yy-lazy[i],inf))-seg[i].begin();
    it--;
    if(it<0)continue;
    if(seg[i][it].first!=yy-lazy[i])continue;
      rt=max(rt,seg[i][it].second);
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