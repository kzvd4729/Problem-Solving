/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-26 16:22:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 500                                        memory_used (MB): 4                               
*  problem: https://vjudge.net/problem/LightOJ-1187
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,tc,n,arr[N+2],seg[5*N],ans;
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node]=vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=seg[node*2]+seg[node*2+1];
}
void query(int node,int lo,int hi,int vl)
{
  if(lo==hi)
  {
    ans=lo;
    return ;
  }
  int md=(lo+hi)/2;
  if(seg[node*2+1]>=vl)query(node*2+1,md+1,hi,vl);
  else query(node*2,lo,md,vl-seg[node*2+1]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&arr[i]);
      upd(1,1,n,i,1);
    }
    for(int i=n;i>=1;i--)
    {
      query(1,1,n,arr[i]+1);
      upd(1,1,n,ans,0);
    }
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}