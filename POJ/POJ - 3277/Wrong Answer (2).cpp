/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-06 17:52:29                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-3277
****************************************************************************************/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int R=1e9;
const int N=4e4;
int sz=1,lazy[200*N+2];
long ans;
struct segment
{
  int l,r;
  long sum;
}seg[200*N+2];
struct data
{
  int l,r,vl;
}arr[N+2];
void upd(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return ;
  if(!seg[node].l)seg[node].l=++sz;
  if(!seg[node].r)seg[node].r=++sz;
  if(lazy[node])
  {
    seg[node].sum=(hi-lo+1);
    if(lo!=hi)
    {
      lazy[seg[node].l]=1;
      lazy[seg[node].r]=1;
    }
    lazy[node]=0;
  }
  if(lo>=lt&&hi<=rt)
  {
    seg[node].sum=(hi-lo+1);
    if(lo!=hi)
    {
      lazy[seg[node].l]=1;
      lazy[seg[node].r]=1;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(seg[node].l,lo,md,lt,rt);
  upd(seg[node].r,md+1,hi,lt,rt);
  seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(!seg[node].l)seg[node].l=++sz;
  if(!seg[node].r)seg[node].r=++sz;
  if(lazy[node])
  {
    seg[node].sum=(hi-lo+1);
    if(lo!=hi)
    {
      lazy[seg[node].l]=1;
      lazy[seg[node].r]=1;
    }
    lazy[node]=0;
  }
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  int md=(lo+hi)/2;
  int p1=query(seg[node].l,lo,md,lt,rt);
  int p2=query(seg[node].r,md+1,hi,lt,rt);
  return p1+p2;
}
bool cmp(data a,data b)
{
  return a.vl>b.vl;
}
int main()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i].l>>arr[i].r>>arr[i].vl;
  sort(arr+1,arr+n+1,cmp);
  for(int i=1;i<=n;i++)
  {
    int tmp=query(1,1,R,arr[i].l,arr[i].r-1);
    ans+=((arr[i].r-arr[i].l-tmp)*1LL*arr[i].vl);
    upd(1,1,R,arr[i].l,arr[i].r-1);
  }
  cout<<ans<<endl;
  return 0;
}