/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2020 23:02                        
*  solution_verdict: Time limit exceeded on test 38          language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 43400 KB                             
*  problem: https://codeforces.com/contest/1463/problem/E
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
void no(){cout<<0<<endl,exit(0);}
const int N=3e5;
int p[N+2],in[N+2],nm[N+2],ent[N+2],ext[N+2],tim;
int bit[N+2];
vector<int>ad[N+2],lin[N+2],rm[N+2];
vector<int>com;
int vs[N+2];vector<int>ord;
void dfs(int nd,int pr)
{
  if(vs[nd])no();vs[nd]=1;
  com.push_back(nd);nm[nd]=pr;
  for(auto x:lin[nd])dfs(x,pr);
}
void timing(int nd)
{
  ent[nd]=++tim;
  for(auto x:ad[nd])timing(x);
  ext[nd]=tim;
}
void add(int x,int vl)
{
  for( ;x<=N;x+=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int get(int lt,int rt)
{
  return get(rt)-get(lt-1);
}
void topo(int nd)
{
  vs[nd]=1;
  for(auto x:ad[nd])
    if(vs[x]==0)topo(x);
  ord.push_back(nd);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int n,k;cin>>n>>k;int rt;
  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
    if(p[i])ad[p[i]].push_back(i);
    else rt=i;
  }
  for(int i=1;i<=k;i++)
  {
    int x,y;cin>>x>>y;
    lin[x].push_back(y);in[y]++;
  }
  vector<vector<int> >cm;int sz=0;
  for(int i=1;i<=n;i++)
  {
    if(in[i])continue;com.clear();
    dfs(i,i);cm.push_back(com);rm[i]=com;
    sz+=com.size();
  }
  if(sz!=n)no();
  for(int i=1;i<=n;i++)vs[i]=0;
  timing(rt);
  //for(int i=1;i<=n;i++)cout<<nm[i]<<" ";cout<<endl;
   for(auto x:cm)
  {
    for(auto v:x)
    {
      if(get(ent[v],ext[v]))no();
      add(ent[v],1);
    }
    for(auto v:x)add(ent[v],-1);
  }
  for(int i=1;i<=n;i++)ad[i].clear();
   for(int i=1;i<=n;i++)
  {
    if(p[i]==0)continue;
    if(nm[i]==nm[p[i]])continue;
    ad[nm[i]].push_back(nm[p[i]]);
  }
  for(int i=1;i<=n;i++)if(vs[i]==0&&in[i]==0)topo(i);
   sz=0;
  //for(auto x:ord)sz+=rm[x].size();
  //if(sz!=n)assert(0);
  for(int i=0;i<ord.size();i++)
  {
    for(int j=0,x=ord[i];j<rm[x].size();j++)
      cout<<rm[x][j]<<" ";
  }
   cout<<endl;
   return 0;
}