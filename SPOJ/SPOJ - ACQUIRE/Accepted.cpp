/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-17 15:41:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 60                                         memory_used (MB): 4.8                             
*  problem: https://vjudge.net/problem/SPOJ-ACQUIRE
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
//#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;

const long inv=-(1LL<<62);
int Min;
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
struct CHT:public multiset<line>
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
  void clear(){clear();}
}st;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v(n);
  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;

  sort(v.begin(),v.end());
  vector<pair<int,int> >a;
  for(int i=0;i<n;i++)
  {
    while(a.size())
    {
      if(a.back().second<=v[i].second)a.pop_back();
      else break;
    }
    a.push_back(v[i]);
  }
  //for(int i=0;i<a.size();i++)cout<<a[i].first<<" -- "<<a[i].second<<endl;
  Min=true;st.add(a[0].second,0);
  long ans=1LL*a[0].first*a[0].second;
  for(int i=0;i<a.size();i++)
  {
    ans=st.get(a[i].first);
    if(i<a.size()-1)st.add(a[i+1].second,ans);
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}