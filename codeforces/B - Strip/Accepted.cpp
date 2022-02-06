/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2019 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 20400 KB                             
*  problem: https://codeforces.com/contest/487/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int mn[N+2][20+2],mx[N+2][20+2],aa[N+2],nx[N+2],seg[5*N+10],dp[N+2];
void build(int n)
{
  for(int i=1;i<=n;i++)mn[i][0]=mx[i][0]=aa[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      mn[i][j]=mn[i][j-1],mx[i][j]=mx[i][j-1];
      if((i+(1<<(j-1)))<=n)
      {
        mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
      }
    }
  }
}
int getMin(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(mn[lt][dg],mn[rt-(1<<dg)+1][dg]);
}
int getMax(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return max(mx[lt][dg],mx[rt-(1<<dg)+1][dg]);
}
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi){seg[node]=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return min(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,s,l;cin>>n>>s>>l;
  for(int i=1;i<=n;i++)cin>>aa[i];
  build(n);
   for(int i=1;i<=n;i++)nx[i]=-1;
  for(int i=1;i<=n;i++)
  {
    int j=i+l-1;if(j>n)continue;
    if(getMax(i,j)-getMin(i,j)>s)continue;
     int lo=j,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(getMax(i,md)-getMin(i,md)>s)hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
      if(getMax(i,md)-getMin(i,md)<=s)break;
    nx[i]=md;
  }
  for(int i=1;i<=5*(n+1);i++)seg[i]=inf;
   upd(1,1,n+1,n+1,0);
  for(int i=n;i>=1;i--)
  {
    if(nx[i]==-1)dp[i]=inf;
    else dp[i]=get(1,1,n+1,i+l,nx[i]+1)+1;
     if(dp[i]>inf)dp[i]=inf;
    upd(1,1,n+1,i,dp[i]);
  }
  if(dp[1]==inf)dp[1]=-1;
  cout<<dp[1]<<endl;
  return 0;
}