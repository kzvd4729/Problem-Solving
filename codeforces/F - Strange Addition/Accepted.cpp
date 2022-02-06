/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2020 15:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2230 ms                                         memory_used: 40400 KB                             
*  problem: https://codeforces.com/contest/1380/problem/F
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
const int N=5e5;
const int mod=998244353;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int dp[N+2],way[N+2];
void precal()
{
  for(int i=10;i<20;i++)
  {
    for(int j=0;j<10;j++)
      if(i-j<10)way[i]++;
  }
  dp[0]=1;dp[1]=2;
  for(int i=2;i<=N;i++)
    dp[i]=(2LL*dp[i-1]+1LL*way[11]*dp[i-2])%mod;
  //for(int i=1;i<=10;i++)cout<<dp[i]<<" ";
  //cout<<endl;
}
int seg[2][4*N+8],lz[2][4*N+8];
void tooLazy(int id,int node,int lo,int hi)
{
  if(lz[id][node]==0)return;seg[id][node]=lz[id][node];
  if(lo!=hi)
  {
    lz[id][node*2]=lz[id][node],lz[id][node*2+1]=lz[id][node];
    lz[id][node]=0;
  }
}
void upd(int id,int node,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(id,node,lo,hi);
  if(lo>rt||hi<lt)return;
  if(lo>=lt&&hi<=rt)
  {
    lz[id][node]=vl;tooLazy(id,node,lo,hi);
    return;
  }
  int md=(lo+hi)/2;
  upd(id,node*2,lo,md,lt,rt,vl);
  upd(id,node*2+1,md+1,hi,lt,rt,vl);
}
int get(int i,int node,int lo,int hi,int id)
{
  tooLazy(i,node,lo,hi);
  if(lo==hi)return seg[i][node];
  int md=(lo+hi)/2;
  if(id<=md)return get(i,node*2,lo,md,id);
  else return get(i,node*2+1,md+1,hi,id);
}
int ans=1;
int ret(int a,int b)
{
  if(!a)return b+1;
  return (1LL*dp[a]*(b+1)+1LL*dp[a-1]*way[10+b])%mod;
}
void process(string s,int n)
{
  int l=1;
  for(int i=1;i<=n;i++)
  {
    if(i<n&&s[i]=='1')continue;
    ans=(1LL*ans*ret(i-l,s[i]-'0'))%mod;
    upd(0,1,1,n,l,i,l);upd(1,1,1,n,l,i,i);
    l=i+1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  precal();int n,m;cin>>n>>m;
  string s;cin>>s;s="#"+s;process(s,n);
   while(m--)
  {
    int id;char c;cin>>id>>c;
    if(s[id]==c)
    {
      cout<<ans<<endl;continue;
    }
    int l=get(0,1,1,n,id),r=get(1,1,1,n,id);
    ans=(1LL*ans*big(ret(r-l,s[r]-'0'),mod-2))%mod;
    if(id==n)
    {
      s[id]=c;
      ans=(1LL*ans*ret(r-l,s[r]-'0'))%mod;
      cout<<ans<<endl;continue;
    }
    if(c=='1')
    {
      s[id]=c;assert(r<n);
      int lt=get(0,1,1,n,r+1),rt=get(1,1,1,n,r+1);
      //cout<<l<<" "<<r<<" "<<lt<<" "<<rt<<endl;
      ans=(1LL*ans*big(ret(rt-lt,s[rt]-'0'),mod-2))%mod;
      ans=(1LL*ans*ret(rt-l,s[rt]-'0'))%mod;
      upd(0,1,1,n,l,rt,l);upd(1,1,1,n,l,rt,rt);
      cout<<ans<<endl;
    }
    else
    {
      s[id]=c;
      if(id==r)
      {
        ans=(1LL*ans*ret(r-l,s[r]-'0'))%mod;
        cout<<ans<<endl;
      }
      else
      {
        ans=(1LL*ans*ret(id-l,s[id]-'0'))%mod;
        ans=(1LL*ans*ret(r-id-1,s[r]-'0'))%mod;
         upd(0,1,1,n,l,id,l);upd(1,1,1,n,l,id,id);
        upd(0,1,1,n,id+1,r,id+1);upd(1,1,1,n,id+1,r,r);
        cout<<ans<<endl;
      }
    }
  }
  return 0;
}