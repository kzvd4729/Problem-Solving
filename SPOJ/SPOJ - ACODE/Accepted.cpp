/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-15 23:11:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-ACODE
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
unsigned long long int dp[5005],n;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>s)
  {
    if(s=="0")break;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=s.size();i++)
    {
      if(s[i-1]=='0')dp[i]=dp[i-2];
      else
      {
        n=(s[i-2]-'0')*10+s[i-1]-'0';
        if(s[i-2]=='0')dp[i]=dp[i-1];
        else if(n<=26)dp[i]=dp[i-1]+dp[i-2];
        else dp[i]=dp[i-1];
      }
    }
    //for(long i=1;i<=s.size();i++)cout<<dp[i]<<endl;
    cout<<dp[s.size()*1LL]<<endl;
  }
  return 0;
}