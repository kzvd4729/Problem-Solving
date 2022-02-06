/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 20:11                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/383/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<24);
int aa[N+2],fr[N+2],dp[2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;aa[i]=0;
    for(auto x:s)
    {
      int j=x-'a';aa[i]|=(1<<j);
    }
    fr[aa[i]]++;
  }
  for(int i=0;i<=N;i++)dp[1][i]=fr[i];
  for(int j=0;j<24;j++)
  {
    for(int i=0;i<(1<<24);i++)
    {
      dp[j%2][i]=0;
      if(i&(1<<j))
      {
        dp[j%2][i]+=dp[(j+1)%2][i];
        dp[j%2][i]+=dp[(j+1)%2][i^(1<<j)];
      }
      else
      {
        dp[j%2][i]+=dp[(j+1)%2][i];
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<24);i++)
    ans^=(dp[1][i]*dp[1][i]);
  cout<<ans<<endl;
  return 0;
}