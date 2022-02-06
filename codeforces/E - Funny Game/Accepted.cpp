/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2020 14:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 17000 KB                             
*  problem: https://codeforces.com/contest/731/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#define long long long
using namespace std;
const int N=1e6;
int n,aa[N+2],qm[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],qm[i]=qm[i-1]+aa[i];
   priority_queue<int>pq;pq.push(qm[n]);
  for(int i=n-1;i>=1;i--)
  {
    dp[i]=pq.top();pq.push(qm[i]-dp[i]);
  }
  cout<<dp[1]<<endl;
  return 0;
}