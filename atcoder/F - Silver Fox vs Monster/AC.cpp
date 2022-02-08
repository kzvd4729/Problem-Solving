/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-26 18:23:55                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 59 ms                                           memory_used: 6516 KB                              
*  problem: https://atcoder.jp/contests/abc153/tasks/abc153_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
pair<long,long>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,d,a;cin>>n>>d>>a;
   for(long i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1);
   priority_queue<pair<long,long> >pq;long cnt=0;
  long ans=0;
  for(long i=1;i<=n;i++)
  {
    while(cnt)
    {
      if((-pq.top().first)<pp[i].first)
      {
        cnt-=pq.top().second;pq.pop();
      }
      else break;
    }
    long h=pp[i].second-cnt*a;
    if(h<=0)continue;
    long ad=(h+a-1)/a;pq.push({-(pp[i].first+2*d),ad});
    cnt+=ad;ans+=ad;
  }
  cout<<ans<<endl;
  return 0;
}