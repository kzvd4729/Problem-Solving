/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2020 16:53                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 592 ms                                          memory_used: 158700 KB                            
*  problem: https://codeforces.com/contest/1422/problem/F
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
#define long long long
using namespace std;
const int N=2e5,mod=1e9+7;
int sz,a[N+2];
struct segment
{
  int l,r,sm;
}seg[62*N+2];//2*lg(mx)*N
void upd(int nd,int lo,int hi,int pnd,int id,int vl)
{
  if(lo==hi){seg[nd].sm=(1LL*seg[pnd].sm*vl)%mod;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    seg[nd].l=++sz;seg[sz].sm=1;
    upd(seg[nd].l,lo,md,seg[pnd].l,id,vl);
    seg[nd].r=seg[pnd].r;
  }
  else
  {
    seg[nd].r=++sz;seg[sz].sm=1;
    upd(seg[nd].r,md+1,hi,seg[pnd].r,id,vl);
    seg[nd].l=seg[pnd].l;
  }
  seg[nd].sm=(1LL*seg[seg[nd].l].sm*seg[seg[nd].r].sm)%mod;
}
int get(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>=lt&&hi<=rt)return seg[nd].sm;
  if(lo>rt||hi<lt)return 1;
  int md=(lo+hi)/2;
  return (1LL*get(seg[nd].l,lo,md,lt,rt)*get(seg[nd].r,md+1,hi,lt,rt))%mod;
}
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
vector<int>fac[N+2];int vs[N+2];
void factorize()
{
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vs[j]=1;fac[j].push_back(i);
    }
  }
}
int inv[N+2],rot[N+2];vector<pair<int,int> >st[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=N;i++)inv[i]=big(i,mod-2);
  factorize();int n;cin>>n;seg[0].sm=1;int ls=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
     for(auto x:fac[a[i]])
    {
      int cnt=0,nm=1;
      while(a[i]%x==0)cnt++,a[i]/=x,nm=nm*x;
       rot[i]=++sz;seg[sz].sm=1;upd(rot[i],1,n,ls,i,nm);
      ls=rot[i];int tmp=nm;
      while((int)st[x].size())
      {
        if(nm==1)break;
        pair<int,int>z=st[x].back();
        if(z.second<=nm)
        {
          rot[i]=++sz;seg[sz].sm=1;upd(rot[i],1,n,ls,z.first,inv[z.second]);
          ls=rot[i];nm/=z.second;st[x].pop_back();
        }
        else
        {
          rot[i]=++sz;seg[sz].sm=1;upd(rot[i],1,n,ls,z.first,inv[nm]);
          ls=rot[i];st[x].back().second/=nm;break;
        }
      }
      st[x].push_back({i,tmp});
    }
  }
  int q;cin>>q;ls=0;
  while(q--)
  {
    int x,y;cin>>x>>y;
    x=(x+ls)%n+1,y=(y+ls)%n+1;
     //cout<<x<<" "<<y<<endl;
     if(x>y)swap(x,y);
    ls=get(rot[y],1,n,x,y);
    cout<<ls<<'\n';
  }
    return 0;
}