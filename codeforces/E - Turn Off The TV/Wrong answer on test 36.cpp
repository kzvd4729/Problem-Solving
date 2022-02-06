/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 22:47                        
*  solution_verdict: Wrong answer on test 36                 language: GNU C++17                               
*  run_time: 561 ms                                          memory_used: 202000 KB                            
*  problem: https://codeforces.com/contest/863/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int R=1e9+2;
const int N=2e5;
int n,sz=1;
pair<int,int>arr[N+2];
struct segment
{
  int l,r,lazy,sum;
}seg[64*N];
void upd(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return ;
  if(lo!=hi)
  {
    if(!seg[node].l)seg[node].l=++sz;
    if(!seg[node].r)seg[node].r=++sz;
  }
  if(seg[node].lazy)
  {
    seg[node].sum+=seg[node].lazy;
    if(lo!=hi)
    {
      seg[seg[node].l].lazy+=seg[node].lazy;
      seg[seg[node].r].lazy+=seg[node].lazy;
    }
    seg[node].lazy=0;
  }
  if(lo>=lt&&hi<=rt)
  {
    seg[node].sum++;
    //cout<<lo<<" "<<hi<<" "<<seg[node].sum<<endl;
    if(lo!=hi)
    {
      seg[seg[node].l].lazy++;
      seg[seg[node].r].lazy++;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(seg[node].l,lo,md,lt,rt);
  upd(seg[node].r,md+1,hi,lt,rt);
  seg[node].sum=min(seg[seg[node].l].sum+seg[seg[node].l].lazy,seg[seg[node].r].sum+seg[seg[node].r].lazy);
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return inf;
  if(seg[node].lazy)
  {
    seg[node].sum+=seg[node].lazy;
    if(lo!=hi)
    {
      seg[seg[node].l].lazy+=seg[node].lazy;
      seg[seg[node].r].lazy+=seg[node].lazy;
    }
    seg[node].lazy=0;
  }
  if(lo>=lt&&hi<=rt)
  {
    //cout<<lo<<" "<<hi<<" "<<seg[node].sum<<endl;
    return seg[node].sum;
  }
  int md=(lo+hi)/2;
  return min(query(seg[node].l,lo,md,lt,rt),query(seg[node].r,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].first>>arr[i].second;
//    arr[i].first++;
//    arr[i].second++;
    upd(1,1,R,arr[i].first,arr[i].second);
  }
  //cout<<query(1,1,R,3,4)<<endl;
  for(int i=1;i<=n;i++)
  {
    //cout<<query(1,1,R,arr[i].first,arr[i].second)<<endl;
    if(query(1,1,R,arr[i].first,arr[i].second)>1)cout<<i<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}