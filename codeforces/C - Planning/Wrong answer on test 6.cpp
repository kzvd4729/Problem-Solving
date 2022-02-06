/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 17:42                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/854/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int arr[300005],n,k,print[300005],id;
long long int ans;
priority_queue<pair<int,int> >pq;
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
      pair<int,int>p=pq.top();
      pq.pop();
      ans+=(i-p.second)*p.first;
      print[p.second]=++id;
    }
  }
  while(pq.size())
  {
    ++n;
    pair<int,int>p=pq.top();
    pq.pop();
    ans+=(n-p.second)*p.first;
    print[p.second]=++id;
  }
  cout<<ans<<endl;
  for(int i=1;i<=id;i++)cout<<print[i]+k<<" ";
  cout<<endl;
  return 0;
}