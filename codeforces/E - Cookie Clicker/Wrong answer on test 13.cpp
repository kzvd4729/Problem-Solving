/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2020 17:26                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++17                               
*  run_time: 124 ms                                          memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/377/problem/E
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
#include<bits/stdc++.h>
#define long long long  
using namespace std;
const int N=1e6;
const long inv=-(1LL<<62);
bool Min;
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
}st;
pair<int,int>a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long m;cin>>m;
   for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
  sort(a+1,a+n+1,[&](pair<int,int>x,pair<int,int>y){
    if(x.first==y.first)return x.second>y.second;
    return x.first<y.first;
  });
  vector<pair<long,long> >v;
  for(int i=1;i<=n;i++)
  {
    while(v.size())
    {
      if(a[i].second<=v.back().second)v.pop_back();
      else break;
    }
    v.push_back(a[i]);
  }
  //for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
  assert(v[0].second==0);
   st.add(v[0].first,0);long ans=(m+v[0].first-1)/v[0].first;
  for(int i=1;i<v.size();i++)
  {
    long lo=1,hi=m,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(st.get(md)>=v[i].second)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)if(st.get(md)>=v[i].second)break;
     long now=st.get(md);
    long ex=now-v[i].second;
     st.add(v[i].first,-v[i].first*md+ex);
  }
  long lo=1,hi=m,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(st.get(md)>=m)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)if(st.get(md)>=m)break;
  cout<<md<<endl;
  return 0;
}