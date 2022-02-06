/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/08/2018 23:55                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 498 ms                                          memory_used: 75000 KB                             
*  problem: https://codeforces.com/contest/960/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=100000;
int n,m,u,v,w,print;
map<int,int>mp[N+5];
void upd(int v,int idx,int vl)
{
  if(idx<=0)return ;
  for( ;idx<=N;idx+=idx&-idx)mp[v][idx]=max(mp[v][idx],vl);
}
int query(int u,int idx)
{
  if(idx<=0)return 0;
  int ret=0;
  for( ;idx>0;idx-=idx&-idx)ret=max(ret,mp[u][idx]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v>>w;
    int ret=query(u,w-1);
    upd(v,w,ret+1);
  }
  for(int i=1;i<=n;i++)print=max(print,query(i,100002));
  cout<<print<<endl;
  return 0;
}