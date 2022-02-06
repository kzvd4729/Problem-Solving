/****************************************************************************************
*  @author: kzvd4729                                         created: May/23/2020 14:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 857 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1354/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int seg[N*4+2];
void add(int node,int lo,int hi,int id)
{
  if(lo==hi){seg[node]++;return;}
  int md=(lo+hi)/2;
  if(id<=md)add(node*2,lo,md,id);else add(node*2+1,md+1,hi,id);
  seg[node]=seg[node*2]+seg[node*2+1];
}
void del(int node,int lo,int hi,int k)
{
  if(lo==hi){seg[node]--;return ;}
  int md=(lo+hi)/2;
  if(seg[node*2]>=k)del(node*2,lo,md,k);
  else del(node*2+1,md+1,hi,k-seg[node*2]);
  seg[node]=seg[node*2]+seg[node*2+1];
}
void ans(int node,int lo,int hi)
{
  if(lo==hi)cout<<lo<<endl,exit(0);
  int md=(lo+hi)/2;
  if(seg[node*2])ans(node*2,lo,md);else ans(node*2+1,md+1,hi);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;add(1,1,n,x);
  }
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    if(x>0)add(1,1,n,x);else del(1,1,n,-x);
  }
  if(seg[1]==0)cout<<0<<endl;else ans(1,1,n);
  return 0;
}