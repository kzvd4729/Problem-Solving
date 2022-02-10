/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-17 16:24:11                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-APIO10A
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
#define endl '\n'
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
  void _clear(){clear();}
}st;

int aa[N+2],qm[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t;//cin>>t;
  scanf("%d",&t);
  while(t--)
  {
    int n,a,b,c;//cin>>n>>a>>b>>c;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=1;i<=n;i++)scanf("%d",&aa[i]),qm[i]=qm[i-1]+aa[i];

    st.add(0,c);long ans;
    for(int i=1;i<=n;i++)
    {
      ans=st.get(qm[i])+1LL*a*qm[i]*qm[i]+1LL*b*qm[i];
      st.add(-2LL*a*qm[i],ans+1LL*a*qm[i]*qm[i]-1LL*b*qm[i]+c);
    }
    printf("%lld\n",ans);st._clear();
  }
  return 0;
}