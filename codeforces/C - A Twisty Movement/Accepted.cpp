/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2018 23:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 50400 KB                             
*  problem: https://codeforces.com/contest/934/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int arr[2002],n,one[2002],two[2002],dp[2002][2002][3],ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i++)
  {
    one[i]=one[i-1];
    if(arr[i]==1)one[i]++;
  }
  for(int i=n;i>=1;i--)
  {
    two[i]=two[i+1];
    if(arr[i]==2)two[i]++;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i;j<=n;j++)
    {
      if(arr[j]==1)
      {
        dp[i][j][2]=dp[i][j-1][2];
        dp[i][j][1]=max(dp[i][j-1][1],dp[i][j-1][2])+1;
      }
      else
      {
        dp[i][j][2]=dp[i][j-1][2]+1;
        dp[i][j][1]=max(dp[i][j-1][1],dp[i][j][2]);
      }
      ans=max(ans,one[i-1]+max(dp[i][j][1],dp[i][j][2])+two[j+1]);
    }
  }
  cout<<ans<<endl;
  return 0;
}