/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/16/2018 21:23                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1006/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,ans;
string a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  ans=0;
  for(int i=1;i<=n/2;i++)
  {
    if(a[i-1]==a[n-i]&&b[i-1]==b[n-i])
    {
     }
    else if(a[i-1]==b[i-1])
    {
      if(a[n-i]==b[n-i])
      {
      }
      else ans++;
    }
    else if(a[i-1]==b[n-i])
    {
      if(a[n-i]==b[i-1])
      {
      }
      else ans++;
    }
    else if(a[n-i]==b[n-i])
    {
      if(a[i-1]==b[i-1])
      {
      }
      else ans++;
    }
    else if(a[n-i]==b[i-1])
    {
      if(a[i-1]==b[n-i])
      {
      }
      else ans++;
    }
    else ans+=2;
    //cout<<ans<<endl;
  }
  if(n%2&&a[n/2]!=b[n/2])ans++;
  cout<<ans<<endl;
  return 0;
}