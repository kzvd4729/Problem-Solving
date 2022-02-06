/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2019 20:59                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/338/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2];
long abc(long n)
{
  long sq=sqrt(n+1),cnt=0;
  for(long i=2;i<=sq;i++)
  {
    while(n%i==0)
      cnt++,n/=i;
  }
  if(n>1)cnt++;
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;for(long i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++)bb[i]=abc(aa[i]);
  vector<long>rt;long ans=0;
  for(int i=1;i<=n;i++)
  {
    sort(rt.begin(),rt.end(),greater<long>());
    if(bb[i]==1)
    {
      ans++;rt.push_back(aa[i]);
    }
    else
    {
      vector<long>rem;long xx=aa[i];
      for(auto x:rt)
      {
        if(xx%x==0)
          xx/=x;
        else rem.push_back(x);
      }
      ans+=abc(xx)+1;
      rem.push_back(aa[i]);
      rt=rem;
    }
  }
  if(rt.size()>1)ans++;
  cout<<ans<<endl;
  return 0;
}