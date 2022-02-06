/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2018 20:15                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 1528 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/546/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e6;
int dp[N+2],t,a,b;
vector<int>dd[N+2];
void divisors(void)
{
  for(int i=2;i<=N;i++)
    for(int j=i+i;j<=N;j+=i)
      dd[j].push_back(i);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   divisors();
  for(int i=2;i<=N;i++)
    for(auto x:dd[i])
      dp[i]=max(dp[i],dp[x]+1);
   for(int i=1;i<=N;i++)
    dp[i]+=(dp[i-1]*1LL);
  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    cout<<dp[a]-dp[b]+a-b<<endl;
  }
   return 0;
}