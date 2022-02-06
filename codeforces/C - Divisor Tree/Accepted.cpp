/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2019 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/338/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2],n,mn;
map<long,long>mm;
long abc(long n)
{
  if(mm.find(n)!=mm.end())return mm[n];
  long str=n;
  long sq=sqrt(n+1),cnt=0;
  for(long i=2;i<=sq;i++)
  {
    while(n%i==0)
      cnt++,n/=i;
  }
  if(n>1)cnt++;
  return mm[str]=cnt;
}
void dfs(long st,vector<long>rt,long ans)
{
  if(st>n)
  {
    if(rt.size()>1)ans++;
    //cout<<"*"<<ans<<endl;
    mn=min(mn,ans);return ;
  }
  long ii=abc(aa[st]);
  if(ii==1)
  {
    vector<long>tmp=rt;
    tmp.push_back(aa[st]);
    dfs(st+1,tmp,ans+1);
  }
  else
  {
    long sz=rt.size(),cnt=0;
    for(long i=0;i<(1LL<<sz);i++)
    {
      long x=aa[st];vector<long>tmp;
      for(long j=0;j<sz;j++)
      {
        if((i&(1LL<<j))&&(x%rt[j]==0))
          x/=rt[j];
        else tmp.push_back(rt[j]);
      }
      tmp.push_back(aa[st]);
      if(x==aa[st])
      {
        if(!cnt)dfs(st+1,tmp,ans+abc(x)+1);
        cnt++;
      }
      else dfs(st+1,tmp,ans+abc(x)+1);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(long i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);vector<long>rt;mn=1e9;
  dfs(1,rt,0);cout<<mn<<endl;
  return 0;
}