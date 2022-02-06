/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/29/2018 01:16                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 15000 KB                             
*  problem: https://codeforces.com/contest/954/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,r,k,arr[500005],bit[500005],x,tmp[500005];
void upd(long idx,long vl)
{
  for( ;idx<=n;idx+=idx&-idx)bit[idx]+=vl;
}
long query(long idx)
{
  long sum=0;
  for( ;idx>0;idx-=idx&-idx)sum+=bit[idx];
  return sum;
}
bool ok(long xx)
{
  long kk=k;
  long now=0;
  memset(tmp,0,sizeof(tmp));
  for(long i=1;i<=n;i++)
  {
    if(arr[i]+now<xx)
    {
      long d=xx-arr[i]-now;
      kk-=d;
      now+=d;
      tmp[min(n,i+r)]+=d;
    }
    if(i-r<1)continue;
    now-=tmp[i-r];
  }
  if(kk>=0)return true;
  else return false;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>r>>k;
  for(long i=1;i<=n;i++)
  {
    cin>>x;
    upd(max(1LL,(i-r)*1LL),x);
    upd(i+r+1,-x);
  }
  for(long i=1;i<=n;i++)arr[i]=query(i);
  long lo=0,hi=4e18,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))lo=md;
    else hi=md;
  }
  for(long i=hi;i>=lo;i--)if(ok(i))cout<<i<<endl,exit(0);
  return 0;
}