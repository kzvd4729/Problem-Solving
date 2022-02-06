/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2020 20:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1292/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e17;
long overFlow(long a,long b)
{
  if((inf/a)<b)return 1;
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long x0,y0,ax,ay,bx,by;cin>>x0>>y0>>ax>>ay>>bx>>by;
  long xs,ys,t;cin>>xs>>ys>>t;
   vector<pair<long,long> >v;
  v.push_back({x0,y0});
  while(true)
  {
    if(overFlow(x0,ax)||overFlow(y0,ay))break;
    x0=ax*x0+bx,y0=ay*y0+by;
    v.push_back({x0,y0});
  }
  if(v.size()>100)assert(0);
  // for(auto x:v)
  //   cout<<x.first<<" "<<x.second<<endl;
  int ans=0;
  for(int i=0;i<v.size();i++)
  {
    int cnt=0;
    long ds=abs(v[i].first-xs)+abs(v[i].second-ys);
    if(ds>t)continue;cnt++;
    for(int j=i-1;j>=0;j--)
    {
      ds+=v[j+1].first-v[j].first+v[j+1].second-v[j].second;
      if(ds>t)break;cnt++;
    }
    if(ds>t)
    {
      ans=max(ans,cnt);continue;
    }
    int pr=0;
    for(int j=i+1;j<v.size();j++)
    {
      ds+=v[j].first-v[pr].first+v[j].second-v[pr].second;
      if(ds>t)break;cnt++;pr=j;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}