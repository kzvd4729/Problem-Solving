/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/1110/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   long ans=n;priority_queue<int>pq;
  for(int i=2;i<=n;i++)
  {
    pq.push(aa[i]-aa[i-1]-1);
    ans+=(aa[i]-aa[i-1]-1)*1LL;
  }
  k--;
  while(pq.size())
  {
    if(!k)break;k--;
    ans-=pq.top();pq.pop();
  }
  cout<<ans<<endl;
  return 0;
}