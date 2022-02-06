/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/16/2018 22:34                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 524300 KB                            
*  problem: https://codeforces.com/contest/1077/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long inf=1e16;
int n,k,x,aa[N+2];long dp[N+2][N+2],seg[N+2][4*N+2];
void upd(int id,int node,int lo,int hi,int idx,long vl)
{
  if(lo==hi)
  {
    seg[id][node]=vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(idx<=md)upd(id,node*2,lo,md,idx,vl);
  else upd(id,node*2+1,md+1,hi,idx,vl);
  seg[id][node]=max(seg[id][node*2],seg[id][node*2+1]);
}
long qry(int id,int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return -inf;
  if(lo>=lt&&hi<=rt)return seg[id][node];
  int md=(lo+hi)/2;
  long p1=qry(id,node*2,lo,md,lt,rt);
  long p2=qry(id,node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k>>x;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)
      dp[i][j]=-inf;
  dp[0][0]=0;
  for(int i=0;i<=N;i++)
  {
    for(int j=0;j<=N;j++)
    {
      upd(i,1,0,N,j,dp[i][j]);
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=x;j++)
    {
      dp[i][j]=aa[i]+qry(j-1,1,0,N,max(i-k-1,0),i-1);
      upd(j,1,0,N,i,dp[i][j]);
    }
  }
  long mx=-inf;
  for(int i=1;i<=x;i++)
    mx=max(mx,dp[n][i]);
  if(mx<0)mx=-1;
  cout<<mx<<endl;
  //cout<<"here"<<endl;
  // if(dp[n][x]<0)dp[n][x]=-1;
  // cout<<dp[n][x]<<endl;
  return 0;
}