/****************************************************************************************
*  @author: kzvd4729                                         created: May/29/2021 20:21                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1107 ms                                         memory_used: 61400 KB                             
*  problem: https://codeforces.com/contest/1303/problem/G
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#include<bits/stdc++.h>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1000000007;
 int a[N+2];
  const long inv=-(1LL<<62);//doesn't matter min or max query
bool Min=false;//true for min query false for max query
struct line
{
  long m,b;
  mutable function<const line*()>succ;
  bool operator<(const line &rhs)const
  {
    if(rhs.b!=inv)return m<rhs.m;
    const line *s=succ();
    if(!s)return 0;
    long x=rhs.m;
    return b-s->b<(s->m-m)*x;
  }
};
struct hullDynamic:public multiset<line>
{
  bool bad(iterator y)
  {
    auto z=next(y);
    if(y==begin())
    {
      if(z==end())return 0;
      return y->m==z->m&&y->b<=z->b;
    }
    auto x=prev(y);
    if(z==end())return y->m==x->m&&y->b<=x->b;
    return 1.0*(x->b-y->b)*(z->m-y->m)>=1.0*(y->b-z->b)*(y->m-x->m);
  }
  void add(long m,long b)
  {
    if(Min)m*=-1,b*=-1;
    auto y=insert({m,b});
    y->succ=[=]{return next(y)==end()?0:&*next(y);};
    if(bad(y)){erase(y);return;}
    while(next(y)!=end()&&bad(next(y)))erase(next(y));
    while(y!=begin()&&bad(prev(y)))erase(prev(y));
  }
  long get(long x)
  {
    auto l=*lower_bound((line){x,inv});
    long ret=l.m*x+l.b;
    if(Min)ret*=-1;return ret;
  }
  void _clear(){clear();}
}fr,ls;
   int tot,mark[N+2],sz[N+2];
vector<int>ad[N+2];
void reckon(int nd,int pr)
{
  tot++;sz[nd]=1;
  for(auto x:ad[nd])
  {
    if(mark[x]||x==pr)continue;
    reckon(x,nd);sz[nd]+=sz[x];
  }
}
int findCenter(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr||mark[x])continue;
    if(sz[x]>tot/2)return findCenter(x,nd);
  }
  return nd;
}
long ans=0;vector<pair<long,long> >vfr,vls;
void dfs(int center,int nd,int pr,long now,long sm,int ln,long sc,long scn)
{
  //cout<<nd<<" "<<scn<<endl;
  vls.push_back({sc,scn});
  ans=max(ans,now+ls.get(ln));
   vfr.push_back({ln,now});
  ans=max(ans,scn+fr.get(sc));
  ans=max(ans,scn+sc+a[center]);
   for(auto x:ad[nd])
  {
    if(x==pr||mark[x])continue;
    dfs(center,x,nd,now+sm+a[x],sm+a[x],ln+1,sc+a[x],scn+1LL*a[x]*ln);
     if(nd!=center)continue;
    for(auto p:vls)ls.add(p.first,p.second);
    for(auto p:vfr)fr.add(p.first,p.second);
     vls.clear();vfr.clear();
  }
}
void centroid(int nd,int pr)
{
  tot=0;reckon(nd,-1);
  int center=findCenter(nd,-1);
  mark[center]=1;
   fr.add(0,0);ls.add(0,0);
  dfs(center,center,-1,a[center],a[center],1,0,0);
  fr._clear();ls._clear();
   for(auto x:ad[center])
  {
    if(mark[x])continue;
    centroid(x,center);
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
  }
   for(int i=1;i<=n;i++)cin>>a[i];
  centroid(1,-1);
   cout<<ans<<endl;
   return 0;
}