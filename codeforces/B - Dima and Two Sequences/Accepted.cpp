/****************************************************************************************
*  @author: kzvd4729                                         created: May/13/2019 16:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 404 ms                                          memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/273/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<int,int>fr;
long fac(long x,long mod,long cnt)
{
  long ret=1;
  for(int i=1;i<=x;i++)
  {
    long z=i;
    while(cnt)
    {
      if(z%2==0)z/=2,cnt--;
      else break;
    }
    ret=(ret*z)%mod;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v(n+n);
  for(int i=0;i<n;i++)cin>>v[i].first,v[i].second=i+1,fr[v[i].first]++;
  for(int i=n;i<n+n;i++)cin>>v[i].first,v[i].second=i-n+1,fr[v[i].first]++;
  long mod;cin>>mod;
  sort(v.begin(),v.end());long ans=1;
  for(int i=0;i<n+n;i+=fr[v[i].first])
  {
    int cnt=0;
    for(int j=i+1;j<n+n;j++)
    {
      if(v[j].first!=v[i].first)break;
      if(v[j].second==v[j-1].second)
        cnt++;
    }
    ans=(ans*fac(fr[v[i].first],mod,cnt))%mod;
  }
  cout<<ans<<endl;
  return 0;
}