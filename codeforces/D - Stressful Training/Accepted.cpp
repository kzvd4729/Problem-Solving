/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2019 00:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2916 ms                                         memory_used: 14000 KB                             
*  problem: https://codeforces.com/contest/1132/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long aa[N+2],bb[N+2],cc[N+2],ex[N+2],tex[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=n;i++)
    cin>>bb[i];
  for(int i=1;i<=n;i++)
  {
    cc[i]=aa[i]/bb[i];
    ex[i]=aa[i]%bb[i];
  }
  long lo=0,hi=2e12+2,md,ans=-1;
  while(lo<=hi)
  {
    md=(lo+hi)/2;int f=0;
    priority_queue<pair<long,long> >pq;
    for(int i=1;i<=n;i++)
    {
      tex[i]=ex[i];
      pq.push({-cc[i],i});
    }
    for(int i=1;i<k;i++)
    {
      pair<long,long>p=pq.top();pq.pop();p.first*=-1LL;
      p.first+=md/bb[p.second];tex[p.second]+=md%bb[p.second];
      if(tex[p.second]>=bb[p.second])p.first++,tex[p.second]-=bb[p.second];
      pq.push({-p.first,p.second});
      if((pq.top().first*-1)<i)
      {
        f=1;break;
      }
    }
    if(f)lo=md+1;
    else ans=md,hi=md-1;
  }
  cout<<ans<<endl;
  return 0;
}