/****************************************************************************************
*  @author: kzvd4729#                                        created: Sep/25/2020 14:05                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1340 ms                                         memory_used: 38800 KB                             
*  problem: https://codeforces.com/contest/1420/problem/C2
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
const int N=3e5;
const long inf=1e18;
const int ng=0,ps=1;
struct segment
{
  long psps,psng,ngps,ngng;
}seg[4*N+8];
segment merge(segment a,segment b)
{
  segment c;
  c.psps=max({a.psps+b.ngps,a.psng+b.psps,a.psps,b.psps});
  c.psng=max({a.psps+b.ngng,a.psng+b.psng,a.psng,b.psng});
  c.ngps=max({a.ngps+b.ngps,a.ngng+b.psps,a.ngps,b.ngps});
  c.ngng=max({a.ngps+b.ngng,a.ngng+b.psng,a.ngng,b.ngng});
  return c;
}
void upd(int nd,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[nd]={vl,-inf,-inf,-vl};return;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(nd*2,lo,md,id,vl);
  else upd(nd*2+1,md+1,hi,id,vl);
  seg[nd]=merge(seg[nd*2],seg[nd*2+1]);
}
int a[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  { 
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];upd(1,1,n,i,a[i]);
    }
    cout<<max(seg[1].psps,seg[1].psng)<<'\n';
    while(q--)
    {
      int l,r;cin>>l>>r;swap(a[l],a[r]);
      upd(1,1,n,l,a[l]);upd(1,1,n,r,a[r]);
      cout<<max(seg[1].psps,seg[1].psng)<<'\n';
    }
  }
  return 0;
}