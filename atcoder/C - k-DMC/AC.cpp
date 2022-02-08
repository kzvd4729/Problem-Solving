/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-24 18:24:35                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 360 ms                                          memory_used: 32668 KB                             
*  problem: https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long dd[N+2],mm[N+2],cc[N+2],dm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  string s;cin>>s;
  for(long i=1;i<=n;i++)
  {
    dd[i]=dd[i-1];mm[i]=mm[i-1];cc[i]=cc[i-1];
    dm[i]=dm[i-1];
    if(s[i-1]=='D')dd[i]++;
    if(s[i-1]=='M')
    {
      mm[i]++;dm[i]+=dd[i];
    }
    if(s[i-1]=='C')cc[i]++;
  }
  long q;cin>>q;
  while(q--)
  {
    long k;cin>>k;long ans=0;
    for(long i=1;i<=n;i++)
    {
      if(s[i-1]!='C')continue;
       long pr=max(i-k,0LL);
       long tt=dm[i]-dm[pr];
      tt-=(dd[pr]*(mm[i]-mm[pr]));
      ans+=tt;
    }
    cout<<ans<<"\n";
  }
  return 0;
}