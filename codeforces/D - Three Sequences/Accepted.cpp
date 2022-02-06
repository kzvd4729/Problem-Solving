/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 23:23                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 390 ms                                          memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/1406/problem/D
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
  long bit[2][N+2];
void upd(int x,long ml,long sm)
{
  for( ;x<=N;x+=(x&-x))
    bit[0][x]+=ml,bit[1][x]+=sm;
}
long get(int x)
{
  long ml=0,sm=0,bg=x;
  for( ;x>0;x-=(x&-x))
    ml+=bit[0][x],sm+=bit[1][x];
  return ml*bg+sm;
}
long getRange(int lo,int hi)
{
  return get(hi)-get(lo-1);
}
void addRange(int lo,int hi,long vl)
{
  upd(lo,vl,-vl*(lo-1));
  upd(hi,-vl,vl*hi);
}
  int a[N+2];
void print(long x)
{
  //cout<<x<<endl;
  if(x>=0)cout<<(x+1)/2<<endl;
  else cout<<(x)/2<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    addRange(i,i,a[i]);
  }
   long ls=0;
   for(int i=2;i<=n;i++)
  {
    if(a[i-1]>a[i])ls+=(a[i-1]-a[i]);
  }
  //cout<<ls<<endl;
  print(ls+getRange(n,n));
    int q;cin>>q;
  while(q--)
  {
    int l,r,x;cin>>l>>r>>x;
     if(l>1)
    {
      long pr=getRange(l-1,l-1);
      long nw=getRange(l,l);
       if(pr>nw)ls-=(pr-nw);
    }
     if(r<n)
    {
      long pr=getRange(r,r);
      long nw=getRange(r+1,r+1);
       if(pr>nw)ls-=(pr-nw);
    }
     addRange(l,r,x);
      if(l>1)
    {
      long pr=getRange(l-1,l-1);
      long nw=getRange(l,l);
       if(pr>nw)ls+=(pr-nw);
    }
     if(r<n)
    {
      long pr=getRange(r,r);
      long nw=getRange(r+1,r+1);
       if(pr>nw)ls+=(pr-nw);
    }
     print(ls+getRange(n,n));
  }
  return 0;
}