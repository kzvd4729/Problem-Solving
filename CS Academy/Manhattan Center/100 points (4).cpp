/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 995 ms                                          memory_used: 2136 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,k;
pair<int,int>arr[N+2];
long cal(int xx)
{
  vector<int>v;
  for(int i=1;i<=n;i++)
    v.push_back(abs(arr[i].first-xx)+arr[i].second);
  sort(v.begin(),v.end());
  long sum=0;
  for(int i=0;i<k;i++)
    sum+=(v[i]*1LL);
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i].first>>arr[i].second;
  int lo=0,hi=1e8;
  while(hi-lo>3)
  {
    int md1=lo+(hi-lo)/3;
    int md2=lo+2*(hi-lo)/3;
    if(cal(md1)<cal(md2))hi=md2;
    else lo=md1;
  }
  long ans=1e14;
  for(int md=lo;md<=hi;md++)
    ans=min(ans,cal(md));
  cout<<ans<<endl;
  return 0;
}