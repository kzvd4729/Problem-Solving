/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 23:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 33700 KB                             
*  problem: https://codeforces.com/contest/282/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int nw,tr[N*42+2][2];long aa[N+2];
void insrt(long x)
{
  int now=0;
  for(long i=40;i>=0;i--)
  {
    bool z=(x&(1LL<<i));
    if(!tr[now][z])tr[now][z]=++nw;
    now=tr[now][z];
  }
}
long qry(long x)
{
  int now=0;long ret=0;
  for(long i=40;i>=0;i--)
  {
    bool z=(x&(1LL<<i));
    if(tr[now][!z])
    {
      ret|=(1LL<<i);now=tr[now][!z];
    }
    else now=tr[now][z];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long arr=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];arr^=aa[i];
  }
  insrt(0LL);long xxr=0,ans=0;
  for(int i=0;i<=n;i++)
  {
    xxr^=aa[i];
    ans=max(ans,qry(xxr^arr));
    insrt(xxr);
  }
  cout<<ans<<endl;
  return 0;
}