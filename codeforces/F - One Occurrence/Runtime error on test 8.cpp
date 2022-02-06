/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/26/2020 14:03                        
*  solution_verdict: Runtime error on test 8                 language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 63000 KB                             
*  problem: https://codeforces.com/contest/1000/problem/F
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
const int N=5e5;
int a[N+2];
vector<pair<int,int> >sg[4*N+8],vv[N+2];
vector<int>par[N+2];
int getR(int id,int x)
{
  if(par[id][x]==x)return x;
  return par[id][x]=getR(id,par[id][x]);
}
void mem(int nd,int sz)
{
  par[nd].resize(sz+2);
  for(int i=0;i<par[nd].size();i++)par[nd][i]=i;
}
void build(int nd,int lo,int hi)
{
  if(lo==hi)
  {
    sg[nd]=vv[lo];mem(nd,sg[nd].size());return;
  }
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
  sg[nd].resize((int)sg[nd*2].size()+(int)sg[nd*2+1].size());
  merge(sg[nd*2].begin(),sg[nd*2].end(),sg[nd*2+1].begin(),sg[nd*2+1].end(),sg[nd].begin());
   mem(nd,sg[nd].size());
}
int ans[N+2];
void get(int nd,int lo,int hi,int lt,int rt,int l,int r,int v)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    int id=lower_bound(sg[nd].begin(),sg[nd].end(),make_pair(l,-1))-sg[nd].begin();
    while(true)
    {
      id=getR(nd,id);if(id>=sg[nd].size())break;
      if(sg[nd][id].first>r)break;
      par[nd][id]=id+1;ans[sg[nd][id].second]=v;
      id++;
    }
    return ;
  }
  int md=(lo+hi)/2;
  get(nd*2,lo,md,lt,rt,l,r,v);
  get(nd*2+1,md+1,hi,lt,rt,l,r,v);
}
vector<int>po[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
  for(int i=1;i<=N;i++)po[i].push_back(0);
  for(int i=1;i<=n;i++)cin>>a[i],po[a[i]].push_back(i);
  for(int i=1;i<=N;i++)po[i].push_back(n+1);
    int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int l,r;cin>>l>>r;
    vv[l].push_back({r,i});
  }
  for(int i=1;i<=N;i++)sort(vv[i].begin(),vv[i].end());
  build(1,1,n);
   for(int i=1;i<=N;i++)
  {
    for(int j=1;j<po[i].size()-1;j++)
      get(1,1,n,po[i][j-1]+1,po[i][j],po[i][j],po[i][j+1]-1,i);
  }
  for(int i=1;i<=q;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}