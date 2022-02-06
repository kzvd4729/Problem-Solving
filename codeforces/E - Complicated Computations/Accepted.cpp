/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2020 22:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 37800 KB                             
*  problem: https://codeforces.com/contest/1436/problem/E
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
const int N=1e6;
int sg[4*N+8];
void upd(int nd,int lo,int hi,int id,int vl)
{
  if(lo==hi){sg[nd]=vl;return;}
  int md=(lo+hi)/2;
  if(id<=md)upd(nd*2,lo,md,id,vl);
  else upd(nd*2+1,md+1,hi,id,vl);
  sg[nd]=min(sg[nd*2],sg[nd*2+1]);
}
int get(int nd,int lo,int hi,int id)
{
  if(lo>id)return N;
  if(hi<=id)return sg[nd];
  int md=(lo+hi)/2;
  return min(get(nd*2,lo,md,id),get(nd*2+1,md+1,hi,id));
}
int a[N+2],aa[N+2];vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n+2;i++)upd(1,1,n+2,i,-1);
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n+2;i++)po[i].push_back(0);
  int f=0;
  for(int i=1;i<=n;i++)if(a[i]>1)f=1;
  if(f==0)cout<<1<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    aa[i]=get(1,1,n+2,a[i]-1);
    upd(1,1,n+2,a[i],i);
     po[a[i]].push_back(i);
  }
  for(int i=1; ;i++)
  {
    int f=0;
    for(int j=1;j<po[i].size();j++)
    {
      if(aa[po[i][j]]>po[i][j-1])f=1;
    }
    if(get(1,1,n+2,i-1)>po[i].back())f=1;
    if(f==0)cout<<i<<endl,exit(0);
  }
  return 0;
}