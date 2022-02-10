/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-24 16:22:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-airconditioned
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=300;
int ans,seg[4*N],n;
struct data
{
  int l,r;
}arr[N+2];
bool cmp(data A,data B)
{
  return A.r<B.r;
}
void upd(int node,int lo,int hi,int id)
{
  if(lo==hi)
  {
    seg[node]=1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id);
  else upd(node*2+1,md+1,hi,id);
  seg[node]=seg[node*2]+seg[node*2+1];
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return query(node*2,lo,md,lt,rt)+query(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i].l>>arr[i].r;
  sort(arr+1,arr+n+1,cmp);

  for(int i=1;i<=n;i++)
  {
    int x=query(1,1,N,arr[i].l,arr[i].r);
    if(x==0)
    {
      ans++;
      upd(1,1,N,arr[i].r);
    }
  }
  cout<<ans<<endl;
  return 0;
}