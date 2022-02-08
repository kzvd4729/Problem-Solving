/****************************************************************************************
*  @author: kzvd4729                                         created: 22-04-2018 22:58:35                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK93A/problems/RUNDIR
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long t,n,dir[55];
long double x,u,pos;
vector<pair<long double,long double> >v;
bool ok(long double xx)
{
  memset(dir,0,sizeof(dir));
  dir[0]=-1;
  for(long long i=1;i<v.size();i++)
  {
    pos=v[i].first-(v[i].second*xx);
    long long f=0;
    for(long long j=i-1;j>=0;j--)
    {
      if(dir[j]==-1)
        if(v[j].first-(v[j].second*xx)<=pos)continue;
      else
        if(v[j].first+(v[j].second*xx)<=pos)continue;
      f=1;
    }
    if(f==0)
    {
      dir[i]=-1;
      continue;
    }
    pos=v[i].first+(v[i].second*xx);
    for(long long j=i-1;j>=0;j--)
    {
      if(dir[j]==-1)continue;
      if(v[j].first+(v[j].second*xx)<=pos)continue;
      return false;
    }
    dir[i]=1;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    v.clear();
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
      cin>>x>>u;
      v.push_back({x,u});
    }
    sort(v.begin(),v.end());
    long double lo=0,hi=1e18+1,md;
    for(long long i=1;i<=500;i++)
    {
      md=(lo+hi)/2.0;
      if(ok(md))lo=md;
      else hi=md;
    }
    if(md>=1e18)cout<<-1<<endl;
    else cout<<setprecision(10)<<fixed<<md<<endl;
  }
  return 0;
}