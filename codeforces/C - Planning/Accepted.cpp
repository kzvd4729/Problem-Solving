/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 17:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 20300 KB                             
*  problem: https://codeforces.com/contest/854/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[300005],n,k,ans,print[300005],id;
priority_queue<pair<long,long> >pq;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i++)
  {
    pq.push({arr[i],i});
    if(i>k)
    {
      pair<long,long>p=pq.top();
      pq.pop();
      ans+=(i-p.second)*p.first;
      print[p.second]=++id;
    }
  }
  while(pq.size())
  {
    ++n;
    pair<long,long>p=pq.top();
    pq.pop();
    ans+=(n-p.second)*p.first;
    print[p.second]=++id;
  }
  cout<<ans<<endl;
  for(int i=1;i<=id;i++)cout<<print[i]+k<<" ";
  cout<<endl;
  return 0;
}