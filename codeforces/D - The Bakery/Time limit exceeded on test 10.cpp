/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 13:21                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 34500 KB                             
*  problem: https://codeforces.com/contest/834/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3.5e4;
const int inf=1e8;
int n,k,arr[N+2],rt[N+2],sz;
int last[N+2],dp[N+2][52];
struct data
{
  int l,r,sum;
}seg[65*N];
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].sum=seg[pnode].sum+vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++sz;
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  int md=(lo+hi)/2;
  int p1=query(seg[node].l,lo,md,lt,rt);
  int p2=query(seg[node].r,md+1,hi,lt,rt);
  return p1+p2;
}
int dfs(int st,int cnt)
{
  if(cnt>k)return -inf;
  if(st==n+1&&cnt==k)return 0;
  if(st>n)return -inf;
  if(dp[st][cnt]!=-1)return dp[st][cnt];
  int here=0;
  for(int i=1;i<=n;i++)
  {
    int r=st+i-1;
    if(r>n)break;
    here=max(here,query(rt[r],1,n,st,r)+dfs(r+1,cnt+1));
  }
  return dp[st][cnt]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(last[x])
    {
      int tmp=++sz;
      upd(tmp,1,n,rt[i-1],last[x],-1);
      rt[i]=++sz;
      upd(rt[i],1,n,tmp,i,1);
    }
    else
    {
      rt[i]=++sz;
      upd(rt[i],1,n,rt[i-1],i,1);
    }
    last[x]=i;
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
   return 0;
}