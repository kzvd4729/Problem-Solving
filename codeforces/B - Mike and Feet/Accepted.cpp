/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/07/2018 15:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 17200 KB                             
*  problem: https://codeforces.com/contest/547/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=2e5;
int n,ans[N+2],arr[N+2];
pair<int,int>seg[4*N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]={arr[lo],lo};
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  if(seg[node*2].first<seg[node*2+1].first)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
pair<int,int>query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {inf,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=query(node*2,lo,md,lt,rt);
  pair<int,int>p2=query(node*2+1,md+1,hi,lt,rt);
  if(p1.first<p2.first)return p1;
  else return p2;
}
void divide(int lo,int hi)
{
  if(lo>hi)return ;
  pair<int,int>p=query(1,1,n,lo,hi);
  ans[hi-lo+1]=max(ans[hi-lo+1],p.first);
  divide(lo,p.second-1);
  divide(p.second+1,hi);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  build(1,1,n);
  divide(1,n);
  for(int i=n;i>=1;i--)
    ans[i]=max(ans[i],ans[i+1]);
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}