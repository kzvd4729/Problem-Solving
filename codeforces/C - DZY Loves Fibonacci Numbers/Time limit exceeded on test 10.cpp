/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/05/2020 18:54                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 37800 KB                             
*  problem: https://codeforces.com/contest/446/problem/C
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
const int N=3e5,mod=1e9+9;
typedef vector<vector<int> > v2d;
v2d multiply(v2d &a,v2d &b)
{
  int d=a.size(),e=a[0].size();
  int f=b.size(),g=b[0].size();
  if(e!=f)assert(0);//impossible to multiply
  v2d c;c.resize(d);
  for(int i=0;i<d;i++)
  {
    c[i].resize(g,0);
    for(int j=0;j<g;j++)
      for(int k=0;k<e;k++)
        c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%mod;
  }
  return c;
}
v2d power[N+2];//max power
void precalPower(v2d &b,long mx)
{
  power[0]=b;
  for(int i=1;i<=mx;i++)
    power[i]=multiply(power[i-1],power[0]);
}
int compute(v2d v,long p)//v is a column vector
{
  v=multiply(power[p-1],v);
  return v[0][0];
}
int seg[4*N+8],lza[4*N+8],aa[N+2],lzb[4*N+8];
void build(int node,int lo,int hi)
{
  if(lo==hi){seg[node]=aa[lo];return ;}
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
void tooLazy(int node,int lo,int hi)
{
  if(lza[node]==0&&lzb[node]==0)return ;
  //cout<<lo<<" ** "<<hi<<" "<<lza[node]<<" "<<lzb[node]<<endl;
  if(lo==hi)
  {
    seg[node]=(seg[node]+lza[node])%mod;
    lza[node]=0;return ;
  }
  int ad=(compute({{lzb[node]},{lza[node]}},hi-lo+1)-lzb[node]+mod)%mod;
  seg[node]=(seg[node]+ad)%mod;
  int md=(lo+hi)/2;
  lza[node*2]=(lza[node*2]+lza[node])%mod;
  lzb[node*2]=(lzb[node*2]+lzb[node])%mod;
   if(md-lo==0)
  {
    lza[node*2+1]=(lza[node*2+1]+lzb[node])%mod;
    lzb[node*2+1]=((lzb[node*2+1]+lzb[node])%mod+lza[node])%mod;
  }
  else
  {
    lza[node*2+1]=(lza[node*2+1]+compute({{lzb[node]},{lza[node]}},md-lo))%mod;
    lzb[node*2+1]=(lzb[node*2+1]+compute({{lzb[node]},{lza[node]}},md-lo+1))%mod;
  }
  lza[node]=0,lzb[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int a,int b)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    if(lo==lt)
    {
      lza[node]=(lza[node]+a)%mod;
      lzb[node]=(lzb[node]+b)%mod;
    }
    else if(lt+1==lo)
    {
      lza[node]=(lza[node]+b)%mod;
      lzb[node]=((lzb[node]+a)%mod+b)%mod; 
    }
    else
    {
      lza[node]=(lza[node]+compute({{b},{a}},lo-lt-1))%mod;
      lzb[node]=(lzb[node]+compute({{b},{a}},lo-lt))%mod;
    }
    tooLazy(node,lo,hi);
    return;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,a,b);upd(node*2+1,md+1,hi,lt,rt,a,b);
  seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
int get(int node,int lo,int hi,int lt,int rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return (get(node*2,lo,md,lt,rt)+get(node*2+1,md+1,hi,lt,rt))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  v2d b(2);b[0].resize(2),b[1].resize(2);
  b[0][0]=1,b[0][1]=1,b[1][0]=1;
  /*for(int i=0;i<b.size();i++)
  {
    for(auto x:b[i])cout<<x<<" ";
      cout<<endl;
  }*/
  precalPower(b,N);//b={{7},{5}};
  //cout<<compute(b,1)<<endl;
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  build(1,1,n);
  for(int i=1;i<=m;i++)
  {
    int ty,l,r;cin>>ty>>l>>r;
    if(ty==1)upd(1,1,n,l,r,1,1);
    else cout<<get(1,1,n,l,r)<<"\n";
  }
    return 0;
}