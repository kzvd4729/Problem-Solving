/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/25/2020 22:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 858 ms                                          memory_used: 46700 KB                             
*  problem: https://codeforces.com/contest/1373/problem/F
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
const int N=1e6;
int seg[4*N+8],lazy[4*N+8];
void tooLazy(int node,int lo,int hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int ad)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=ad;tooLazy(node,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ad);upd(node*2+1,md+1,hi,lt,rt,ad);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi,int lt,int rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 1e9;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return min(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
int a[N+2],b[N+2],c[N+2];
void clear(int n)
{
  for(int i=0;i<4*n+8;i++)seg[i]=0,lazy[i]=0;
  for(int i=1;i<=n;i++)c[i]=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;clear(n);int f=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
     c[1]=min(a[1],b[1]);c[2]=min(b[1]-c[1],a[2]);upd(1,1,n,1,1,c[1]);
    for(int i=2;i<n;i++)
    {
      int nd=a[i]-c[i];upd(1,1,n,i,i,nd);
      if(nd<=b[i])
      {
        c[i]+=nd;c[i+1]=min(b[i]-nd,a[i+1]);
      }
      else
      {
        c[i]+=b[i];nd-=b[i];
        int gt=get(1,1,n,1,i);if(gt<nd){f=1;break;}
        upd(1,1,n,1,i,-nd);c[i]+=nd;c[1]-=nd;
      }
    }
    if(f){cout<<"NO\n";continue;}
    if(b[n]>=a[n]-c[n]+a[1]-c[1])cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}