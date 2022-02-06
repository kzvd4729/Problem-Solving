/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/09/2020 21:53                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/500/problem/E
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
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
int a[N+2],b[N+2],tl[N+2],seg[4*N+2];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi){seg[node]=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return max(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
int mx[N+2];
void ud(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi){seg[node]=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=seg[node*2]+seg[node*2+1];
}
int gt(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return get(node*2,lo,md,lt,rt)+get(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
   tl[n]=n;upd(1,1,n,n,n);
  for(int i=n-1;i>=1;i--)
  {
    int id=upper_bound(a+1,a+n+1,a[i]+b[i])-a;id--;
    //cout<<i<<"-->"<<id<<endl;
    tl[i]=max(i,get(1,1,n,1,id));upd(1,1,n,i,tl[i]);
  }
  //for(int i=1;i<=n;i++)cout<<tl[i]<<" ";cout<<endl;
  for(int i=1;i<=n;i++)
    mx[tl[i]]=max(mx[tl[i]],a[i]+b[i]);
  memset(seg,0,sizeof seg);
  for(int i=1;i<n;i++)
  {
    if(tl[i]!=tl[i+1])
    {
      //cout<<i<<" "<<mx[tl[i]]<<endl;
      ud(1,1,n,i,a[i+1]-mx[tl[i]]);
    }
  }
  int q;cin>>q;
  while(q--)
  {
    int a,b;cin>>a>>b;cout<<gt(1,1,n,a,b-1)<<"\n";
  }
  return 0;
}