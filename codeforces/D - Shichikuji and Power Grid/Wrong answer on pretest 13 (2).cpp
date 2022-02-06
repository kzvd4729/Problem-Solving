/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/01/2019 21:53                        
*  solution_verdict: Wrong answer on pretest 13              language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1245/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;vector<vector<long> >v(n);
  for(long i=0;i<n;i++)
  {
    v[i].resize(5);
    cin>>v[i][2]>>v[i][3];
    v[i][4]=i+1;
  }
  for(long i=0;i<n;i++)
    cin>>v[i][0];
  for(long i=0;i<n;i++)
    cin>>v[i][1];
  sort(v.begin(),v.end());
   vector<pair<long,long> >ed;
  vector<long>nd;
   long ans=0;
  for(long i=0;i<n;i++)
  {
    long mn=(1LL<<63)-1LL,id;
    for(long j=0;j<i;j++)
    {
      long cs=1LL*(abs(v[i][2]-v[j][2])+abs(v[i][3]-v[j][3]))*(v[i][1]+v[j][1]);
      if(cs<mn)mn=cs,id=j;
    }
    if(v[i][0]>mn)
    {
      ed.push_back({v[i][4],v[id][4]});
      ans+=mn;
    }
    else
    {
      nd.push_back(v[i][4]);ans+=v[i][0];
    }
  }
  cout<<ans<<"\n";
  cout<<nd.size()<<"\n";
  for(auto x:nd)cout<<x<<"\n";
  cout<<ed.size()<<"\n";
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}