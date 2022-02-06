/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2018 18:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/998/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[102],k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  int now=0;
  priority_queue<int>pq;
  for(int i=1;i<n;i++)
  {
    if(arr[i]%2)now++;
    else now--;
    if(now==0)
      pq.push(-abs(arr[i]-arr[i+1]));
  }
  int ans=0;
  while(pq.size())
  {
    k+=pq.top();
    pq.pop();
    if(k>=0)ans++;
  }
  cout<<ans<<endl;
  return 0;
}