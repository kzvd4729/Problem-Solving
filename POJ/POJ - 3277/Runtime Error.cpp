/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-06 16:56:24                      
*  solution_verdict: Runtime Error                           language: C++                                     
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
int sz=1,lazy[100*N+2];
struct segment
{
  int l,r;
  long area;
}seg[100*N+2];
struct data
{
  int l,r,vl;
}arr[N+2];
bool cmp(data a,data b)
{
  return a.vl<b.vl;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(!seg[node].l)seg[node].l=++sz;
  if(!seg[node].r)seg[node].r=++sz;
  if(lazy[node])
  {
    long here=(lazy[node]*1LL*(hi-lo+1));
    seg[node].area=max(seg[node].area,here);
    if(lo!=hi)
    {
      lazy[seg[node].l]=max(lazy[seg[node].l],lazy[node]);
      lazy[seg[node].r]=max(lazy[seg[node].r],lazy[node]);
    }
  }
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    long here=(hi-lo+1)*1LL*vl;
    seg[node].area=max(seg[node].area,here);
    if(lo!=hi)
    {
      lazy[seg[node].l]=vl;
      lazy[seg[node].r]=vl;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(seg[node].l,lo,md,lt,rt,vl);
  upd(seg[node].r,md+1,hi,lt,rt,vl);
  seg[node].area=seg[seg[node].l].area+seg[seg[node].r].area;
}
int main()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i].l>>arr[i].r>>arr[i].vl;
  sort(arr+1,arr+n+1,cmp);
  for(int i=1;i<=n;i++)
    upd(1,1,R,arr[i].l,arr[i].r-1,arr[i].vl);
  cout<<seg[1].area<<endl;
  return 0;
}