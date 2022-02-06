/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/19/2020 19:45                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 247800 KB                            
*  problem: https://codeforces.com/contest/794/problem/F
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
const int N=1e5;
int aa[N+2],pw[10+2];
struct segment
{
  int cnt[10+2][10+2],lz[10+2];
  long sm;
}seg[4*N+8];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node].sm=aa[lo];int tmp=aa[lo];
    for(int i=0;i<10;i++)
    {
      if(tmp==0)break;
      int r=tmp%10;tmp/=10;
      seg[node].cnt[i][r]++;
    }
    return;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
   seg[node].sm=seg[node*2].sm+seg[node*2+1].sm;
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<10;j++)
      seg[node].cnt[i][j]=seg[node*2].cnt[i][j]+seg[node*2+1].cnt[i][j];
  }
}
void tooLazy(int node,int lo,int hi)
{
  for(int i=0;i<10;i++)
  {
    if(seg[node].lz[i]==0)continue;
    int c=seg[node].lz[i];
    //cout<<seg[node].sm<<" ";
    for(int j=0;j<9;j++)
    {
      int now=seg[node].cnt[j][i];
      seg[node].sm-=1LL*now*pw[j]*i;
      seg[node].cnt[j][i]=0;
      seg[node].sm+=1LL*now*pw[j]*c;
      seg[node].cnt[j][c]+=now;
    }
    //cout<<seg[node].sm<<endl;
    if(lo!=hi)seg[node*2].lz[i]=c,seg[node*2+1].lz[i]=c;
    seg[node].lz[i]=0;
  }
}
void upd(int node,int lo,int hi,int lt,int rt,int x,int y)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].lz[x]=y;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,x,y);upd(node*2+1,md+1,hi,lt,rt,x,y);
   seg[node].sm=seg[node*2].sm+seg[node*2+1].sm;
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<=10;j++)
      seg[node].cnt[i][j]=seg[node*2].cnt[i][j]+seg[node*2+1].cnt[i][j];
  }
}
long get(int node,int lo,int hi,int lt,int rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sm;
  int md=(lo+hi)/2;
  return get(node*2,lo,md,lt,rt)+get(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(int i=1;i<=9;i++)pw[i]=pw[i-1]*10;
   int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i];
  build(1,1,n);//cout<<seg[1].sm<<endl;
    while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int l,r,x,y;cin>>l>>r>>x>>y;
      upd(1,1,n,l,r,x,y);
    }
    else 
    {
      int l,r;cin>>l>>r;
      cout<<get(1,1,n,l,r)<<"\n";
    }
  }
    return 0;
}