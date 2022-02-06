/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 19:21                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/676/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int fr[N+2],bc[N+2],n,k;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  cin>>s;
  fr[0]=1;
  for(int i=1;i<n;i++)
  {
    if(s[i]==s[i-1])
      fr[i]=fr[i-1]+1;
    else fr[i]=1;
  }
  bc[n-1]=1;
  for(int i=n-2;i>=0;i--)
  {
    if(s[i]==s[i+1])
      bc[i]=bc[i+1]+1;
    else bc[i]=1;
  }
  int ans=min(n,k);
  for(int i=0;i<n;i++)
  {
    int j=i+k-1;
    if(j>=n)break;
    if(j<n-1)ans=max(ans,k+bc[j+1]);
    if(i)
      ans=max(ans,k+fr[i-1]);
    if(i&&j<n-1)
      if(s[i-1]==s[j+1])ans=max(ans,k+fr[i-1]+bc[j+1]);
  }
  cout<<ans<<endl;
  return 0;
}