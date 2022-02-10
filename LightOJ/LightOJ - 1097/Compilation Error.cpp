/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-15 16:59:35                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1097
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1429432;
int seg[N*4],k,f,idx,t,n,tc;
vector<int>ans;
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
void kth(int node,int lo,int hi)
{
  if(lo==hi)
  {
    idx=lo;
    return ;
  }
  int md=(lo+hi)/2;
  if(seg[node*2]>=k)kth(node*2,lo,md);
  else
  {
    k-=seg[node*2];
    kth(node*2+1,md+1,hi);
  }
}
void query(int node,int lo,int hi,int id)
{
  if(lo==hi)
  {
    f=seg[node];
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)query(node*2,lo,md,id);
  else query(node*2+1,md+1,hi,id);
}
void preprocess(void)
{
  for(int i=1;i<=N;i++)
    upd(1,1,N,i,1);
  for(int i=2;i<=N;i++)
  {
    f=0;
    query(1,1,N,i);
    if(f==0)continue;
    vector<int>here;
    for(int j=i;j<=N;j+=i)
    {
      k=j;
      kth(1,1,N);
      here.push_back(idx);
    }
    for(auto x:here)
      upd(1,1,N,x,0);
  }
}
int main()
{
  preprocess();
  for(int i=1;i<=N;i++)
  {
    f=0;
    query(1,1,N,i);
    if(f)ans.push_back(i);
  }
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    printf("Case %d: %d\n",++tc,ans[n-1]);
  }
  return 0;
}