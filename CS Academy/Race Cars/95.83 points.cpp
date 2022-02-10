/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 95.83 points                            language: C++                                     
*  run_time: 239 ms                                          memory_used: 7364 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long con=10e12;
long n,x,y,d,v,dd,vv,id;
vector<pair<long,long> >vc,un,up,dw;
long bs1(void)
{
  long x=((dd*1.00)/(vv*1.00))*con;
  long lo,hi,md;
  lo=0,hi=n-1;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(dw[md].first<x)lo=md;
    else if(dw[md].first>x)hi=md;
    else if(dw[md].second<id)lo=md;
    else if(dw[md].second>id)hi=md;
  }
  long ans=n;
  for(int i=lo;i<=hi;i++)
  {
    if(dw[i].first>x||dw[i].first==x&&dw[i].second>id)return i+1;
  }
  return ans;
}
long bs2(void)
{
  long vx=vv+x;
  long x=((dd*1.00)/(vx*1.00))*con;
  long lo,hi,md;
  lo=0,hi=n-1;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(un[md].first<x)lo=md;
    else if(un[md].first>x)hi=md;
    else if(un[md].second<id)lo=md;
    else if(un[md].second>id)hi=md;
  }
  long ans=n;
  for(int i=lo;i<=hi;i++)
  {
    if(un[i].first>x||un[i].first==x&&un[i].second>id)return i+1;
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>x>>y;
  for(int i=1;i<=n;i++)
  {
    cin>>d>>v;
    vc.push_back({d,v});
    long vx=v+x;
    long vy=v-y;
    long x=((d*1.00)/(v*1.00))*con;
    long y=((d*1.00)/(vx*1.00))*con;
    long z=((d*1.00)/(vy*1.00))*con;
    un.push_back({x,i});
    up.push_back({y,i});
    dw.push_back({z,i});
  }
  sort(un.begin(),un.end());
  sort(up.begin(),up.end());
  sort(dw.begin(),dw.end());
  for(int i=0;i<vc.size();i++)
  {
    dd=vc[i].first;
    vv=vc[i].second;
    id=i+1;
    cout<<min(bs1(),bs2())<<endl;
  }
  return 0;
}