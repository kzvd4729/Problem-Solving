/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2021 20:10                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 171 ms                                          memory_used: 14100 KB                             
*  problem: https://codeforces.com/contest/1483/problem/C
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
const int N=3e5,inf=1e9,mod=1e9+7;
 int a[N+2],b[N+2];
pair<int,int>seg[5*N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi){seg[node]={a[lo],lo};return ;}
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
pair<int,int>get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {2e9,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=get(node*2,lo,md,lt,rt);
  pair<int,int>p2=get(node*2+1,md+1,hi,lt,rt);
  return min(p1,p2);
}
int n;
long dfs(int lo,int hi,int l,int r)
{
  if(lo>hi)return 0LL;
   pair<int,int>p=get(1,1,n,lo,hi);
  int id=p.second;
   long lf=max(0LL,dfs(lo,id-1,l,1));
  long rg=max(0LL,dfs(id+1,hi,1,r));
   if(l && r)return max({b[id]+lf+rg,0LL,lf,rg});
  else if(l)return max({b[id]+lf+rg,0LL,rg});
  else if(r)return max({b[id]+lf+rg,0LL,lf});
  else return b[id]+lf+rg;
 }
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
   build(1,1,n);
   cout<<dfs(1,n,0,0)<<endl;
     return 0;
}