/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-24 17:46:41                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 214 ms                                          memory_used: 248064 KB                            
*  problem: https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long nw,n,k,aa[N+2];
struct trie
{
  long next[2],cnt;
}tr[65*N+2];
void insrt(long x)
{
  long now=0;
  for(long i=62;i>=0;i--)
  {
    long z=(x&(1LL<<i));z=bool(z);
    if(!tr[now].next[z])tr[now].next[z]=++nw;
    now=tr[now].next[z];tr[now].cnt++;
  }
}
long qry()
{
  long ret=0;long now=0;
  for(long i=62;i>=0;i--)
  {
    long nx=tr[now].next[1];
    if(tr[nx].cnt>=k)
    {
      ret|=(1LL<<i);
      now=tr[now].next[1];
    }
    else now=tr[now].next[0];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  insrt(0);
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