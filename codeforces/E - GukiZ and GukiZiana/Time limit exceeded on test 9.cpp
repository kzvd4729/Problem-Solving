/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2018 15:04                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++17                               
*  run_time: 10000 ms                                        memory_used: 17800 KB                             
*  problem: https://codeforces.com/contest/551/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=5e5;
int n,q,arr[N+2],sq;
int lazy[1003];
set<pair<int,int> >seg[1003];
void build(void)
{
  for(int i=1;i<=n;i++)
    seg[i/sq].insert({arr[i],i});
}
void upd(int lt,int rt,int xx)
{
  for(int i=0;i<=n/sq;i++)
  {
    int st=i*sq;
    if(!st)st++;
    int ed=(i+1)*sq-1;
    if(ed<lt||st>rt)continue;
//    else if(st>=lt&&ed<=rt)
//      lazy[i]+=xx;
    else
    {
      for(int j=st;j<=ed;j++)
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
int query(int yy)
{
  int lt=inf,rt=0;
  for(int i=0;i<=n/sq;i++)
  {
    auto it=upper_bound(seg[i].begin(),seg[i].end(),make_pair(yy-lazy[i]-1,inf));
    if(it!=seg[i].end())
    {
      if(it->first==yy-lazy[i])
        lt=min(lt,it->second);
    }
    auto iit=upper_bound(seg[i].begin(),seg[i].end(),make_pair(yy-lazy[i],inf));
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
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sq=sqrt(n);
  build();
//    for(int i=0;i<=n/sq;i++)
//    {
//      cout<<endl;
//      for(auto x:seg[i])
//        cout<<x.first<<" "<<x.second<<endl;
//    }
    while(q--)
  {
    int ty,l,r,x,y;
    cin>>ty;
    if(ty==1)
    {
      cin>>l>>r>>x;
      upd(l,r,x);
    }
    else
    {
      cin>>y;
      cout<<query(y)<<endl;
    }
  }
  return 0;
}