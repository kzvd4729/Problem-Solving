/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2019 20:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 186200 KB                            
*  problem: https://codeforces.com/gym/102268/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long sp[N+2][20+2],aa[N+2],n,k;
void build(long n)
{
  for(long i=1;i<=n;i++)sp[i][0]=aa[i];//array
  for(long j=1;j<=20;j++)
  {
    for(long i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
long get(long lt,long rt)
{
  //if(rt<lt)return 1e9;
  long dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
bool ok(long md)
{
  vector<pair<long,long> >v;
  for(long i=1;i<=n;i++)
    if(aa[i]<=md/2)v.push_back({aa[i],i});
  long cnt=v.size();
   if(v.size()==0)return false;
   long mn=2e9+1;
  if(v[0].second>1)mn=min(mn,get(1,v[0].second-1));
  if(v.back().second<n)mn=min(mn,get(v.back().second+1,n));
   if(mn*1LL+v[0].first<=md&&mn*1LL+v.back().first<=md)cnt++;
   for(long i=1;i<v.size();i++)
  {
    if(v[i-1].second<v[i].second-1)
    {
      long mn=get(v[i-1].second+1,v[i].second-1);
      if(v[i-1].first+mn<=md&&v[i].first+mn<=md)cnt++;
    }
  }
  return cnt>=k;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(long i=1;i<=n;i++)cin>>aa[i];
   build(n);
  long lo=0,hi=2e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))hi=md;else lo=md;
  }
  for(md=lo;md<=hi;md++)if(ok(md))break;
  cout<<md<<endl;
   return 0;
}