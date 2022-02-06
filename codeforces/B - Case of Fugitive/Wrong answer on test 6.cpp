/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/10/2018 22:58                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 14100 KB                             
*  problem: https://codeforces.com/contest/555/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,m,ans[N+2];
pair<long,long>ln[N+2];
struct data
{
  long lt,rt,id;
}arr[N+2],tmp[N+2];
bool cmp(data a,data b)
{
  if(a.lt!=b.lt)return a.lt<b.lt;
  else return a.rt<b.rt;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(long i=1;i<=n;i++)
    cin>>arr[i].lt>>arr[i].rt;
  for(long i=2;i<=n;i++)
  {
    tmp[i-1].lt=arr[i].lt-arr[i-1].rt;
    tmp[i-1].rt=arr[i].rt-arr[i-1].lt;
    tmp[i-1].id=i-1;
  }
  sort(tmp+1,tmp+n,cmp);
  for(long i=1;i<=m;i++)
  {
    cin>>ln[i].first;
    ln[i].second=i;
  }
  sort(ln+1,ln+m+1);
   long pt=1;
  for(long i=1;i<n;i++)
  {
    while(pt<=m)
    {
      if(ln[pt].first>=tmp[i].lt&&ln[pt].first<=tmp[i].rt)break;
      pt++;
    }
    if(pt>m)cout<<"No"<<endl,exit(0);
    ans[tmp[i].id]=ln[pt++].second;
  }
  cout<<"Yes"<<endl;
  for(long i=1;i<n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}