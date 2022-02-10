/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-22 22:42:07                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-EDIST
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int dp[2002][2002],t,l1,l2;
string a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    l1=a.size();
    l2=b.size();
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=l1;i++)
    {
      for(int j=1;j<=l2;j++)
      {
        if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
    cout<<max(l1,l2)-dp[l1][l2]<<endl;
  }
  return 0;
}