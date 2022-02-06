/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 14:26                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 186 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1469/problem/F
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
const long N=1e6,inf=1e9,mod=1e9+7;
  long bit[2][N+2];
void upd(long x,long ml,long sm)
{
  for( ;x<=N;x+=(x&-x))
    bit[0][x]+=ml,bit[1][x]+=sm;
}
long get(long x)
{
  long ml=0,sm=0,bg=x;
  for( ;x>0;x-=(x&-x))
    ml+=bit[0][x],sm+=bit[1][x];
  return ml*bg+sm;
}
long getRange(long lo,long hi)
{
  return get(hi)-get(lo-1);
}
void addRange(long lo,long hi,long vl)
{
  upd(lo,vl,-vl*(lo-1));
  upd(hi,-vl,vl*hi);
}
  long a[N+2],k;
 long find()
{
  long lo=1,hi=N,md;
   while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(getRange(1,md)<k)lo=md;
    else hi=md;
  }
  for(md=lo;md<=hi;md++)
    if(getRange(1,md)>=k)return md;
   return inf;
}
 void add(long pt,long x)
{
  if(x%2)
  {
    long hf=x/2;
    addRange(pt+2,pt+hf+1,1);
    addRange(pt+2,pt+hf+1,1);
  }
  else
  {
    long hf=x/2;
    addRange(pt+2,pt+hf,1);
    addRange(pt+2,pt+hf+1,1);
  }
  if(pt)addRange(pt,pt,-1);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n>>k;
   for(long i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
   add(0,a[n]);
  long pt=1,ans=find();
   for(long i=n-1;i>=1;i--)
  {
    while(getRange(pt,pt)==0 && pt<=N)pt++;
    if(pt>N)break;
     add(pt,a[i]);
     ans=min(ans,find());
  }
  if(ans==inf)ans=-1;
  cout<<ans<<endl;
  return 0;
}