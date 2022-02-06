/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/20/2018 16:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1070/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,m,t,aa[N+2];
long ck(long d)
{
  long mm=0,tt=0,ret=0,now=0;
  for(long i=1;i<=n;i++)
  {
    if(aa[i]>d)continue;
    if(tt+aa[i]>t)return ret;
    tt+=aa[i];mm++;ret++;now+=aa[i];
    if(mm==m)
    {
      mm=0;tt+=now;
      now=0;
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long ts;cin>>ts;
  while(ts--)
  {
    cin>>n>>m>>t;vector<long>v;
    for(long i=1;i<=n;i++)
    {
      cin>>aa[i];
      if(aa[i]<=t)v.push_back(aa[i]);
    }
    if(v.size()==0)
    {
      cout<<0<<" "<<1<<endl;
      continue;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     long lo=0,hi=v.size()-1,md;
    while(hi-lo>10)
    {
      md=(lo+hi)/2;
      long on=ck(v[md]);
      long tw=ck(v[min(md+1,(long)v.size()-1)]);
      if(tw>on)lo=md;
      else hi=md;
    }
    long pr1=-1,pr2;
    for(md=lo;md<=hi;md++)
    {
      long on=ck(v[md]);
      if(on>pr1)
      {
        pr1=on;pr2=md;
      }
    }
    cout<<pr1<<" "<<v[pr2]<<"\n";
  }
  return 0;
}