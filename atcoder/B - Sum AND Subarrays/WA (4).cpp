/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-24 17:35:26                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 269 ms                                          memory_used: 327936 KB                            
*  problem: https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long tr[64*N+2][4],nw,n,k,aa[N+2];
void insrt(long x)
{
  long now=0;
  for(long i=62;i>=0;i--)
  {
    bool z=(x&(1LL<<i));
    tr[now][2+z]++;
    if(!tr[now][z])tr[now][z]=++nw;
    now=tr[now][z];
  }
}
long qry()
{
  long ret=0;long now=0;
  for(long i=62;i>=0;i--)
  {
    if(tr[now][3]>=k)
    {
      ret|=(1LL<<i);
      now=tr[now][1];
    }
    else now=tr[now][0];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  for(long i=1;i<=n;i++)
  {
    long sum=0;
    for(long j=i;j<=n;j++)
    {
      sum+=(aa[j]*1LL);//cout<<sum<<endl;
      insrt(sum);
    }
  }
  cout<<qry()<<endl;
  return 0;
}