/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2020 18:58                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 748 ms                                          memory_used: 50600 KB                             
*  problem: https://codeforces.com/contest/1179/problem/C
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2],b[N+2];
int seg[4*N+8],lz[4*N+8];
void build(int node,int lo,int hi)
{
  if(lo==hi){seg[node]=a[lo]-b[lo];return;}
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
void toolazy(int node,int lo,int hi)
{
  seg[node]+=lz[node];
  if(lo!=hi)lz[node*2]+=lz[node],lz[node*2+1]+=lz[node];
  lz[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int ad)
{
  toolazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[node]+=ad;toolazy(node,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ad);upd(node*2+1,md+1,hi,lt,rt,ad);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi)
{
  toolazy(node,lo,hi);
  if(lo==hi)return lo;
  int md=(lo+hi)/2;
  toolazy(node*2,lo,md);toolazy(node*2+1,md+1,hi);
  if(seg[node*2+1]>0)return get(node*2+1,md+1,hi);
  else return get(node*2,lo,md);
}
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;a[x]++;
    aa[i]=x;
  }
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;b[x]++;
    bb[i]=x;
  }
  for(int i=N-1;i>=1;i--)a[i]+=a[i+1],b[i]+=b[i+1];
  build(1,1,N);int q;cin>>q;
  while(q--)
  {
    int ty,i,x;cin>>ty>>i>>x;
    if(ty==1)
    {
      int p=aa[i];aa[i]=x;
              if(x<p)upd(1,1,N,x+1,p,-1);
      else if(x>p)upd(1,1,N,p+1,x,+1);
    }
    else
    {
      int p=bb[i];bb[i]=x;
            if(x<p)upd(1,1,N,x+1,p,+1);
      else if(x>p)upd(1,1,N,p+1,x,-1);
    }
    if(seg[1]<=0)cout<<-1<<endl;
    else cout<<get(1,1,N)<<endl;
  }
  return 0;
}