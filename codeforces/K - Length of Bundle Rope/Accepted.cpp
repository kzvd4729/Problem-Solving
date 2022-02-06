/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2020 19:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/gym/102460/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;priority_queue<long>pq;
    for(long i=1;i<=n;i++)
    {
      long x;cin>>x;pq.push(-x);
    }
    long ans=0;
    while(pq.size()>1)
    {
      long u=-pq.top();pq.pop();
      long v=-pq.top();pq.pop();
      ans+=u+v;pq.push(-(u+v));
    }
    cout<<ans<<endl;
  }
    return 0;
}