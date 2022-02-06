/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2021 19:16                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 93 ms                                           memory_used: 47700 KB                             
*  problem: https://codeforces.com/contest/1513/problem/D
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
  int a[N+2];
 pair<int,int>seg[4*N+8];
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
 int n,p;
long dfs(int lo,int hi)
{
  if(lo==hi)return 0;
   int id=get(1,1,n,lo,hi).second;
   long now=0;
   int rt=id+1,lt=id-1;
  for(int i=id+1;i<=hi;i++)
  {
    if((a[i]%a[id])==0)rt++,now+=min(a[id],p);
    else break;
  }
  for(int i=id-1;i>=lo;i--)
  {
    if((a[i]%a[id])==0)lt--,now+=min(a[id],p);
    else break;
  }
   if(rt<=hi)
  {
    if(rt==id+1)now+=p+dfs(rt,hi);
    else now+=dfs(rt-1,hi);
  }
  if(lt>=lo)
  {
    if(lt==id-1)now+=p+dfs(lo,lt);
    else now+=dfs(lo,lt+1);
  }
   return now;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>n>>p;
     for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
     cout<<dfs(1,n)<<endl; 
  }
  return 0;
}