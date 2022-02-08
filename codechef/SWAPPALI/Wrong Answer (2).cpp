/****************************************************************************************
*  @author: kzvd4729                                         created: 29-02-2020 20:27:53                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/LTIME81A/problems/SWAPPALI
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int n,dp[N+2][2];string s;
int dfs(int i,int f)
{
  int j=n-1-i;if(j<=i)return 0;
  if(dp[i][f]!=-1)return dp[i][f];
  int now=inf;
  if(f==0)
  {
    if(s[i]==s[j])now=min(now,dfs(i+1,0));
    if(i+1<j&&s[i+1]==s[j])now=min(now,1+dfs(i+1,1));
    if(j-i==2)
    {
        if(s[i]==s[j]||s[j]==s[j-1]||s[i]==s[j-1])
            now=min(now,1);
    }
  }
  else
  {
    if(s[i-1]==s[j])now=min(now,dfs(i+1,0));
    if(j-i==2)
    {
        if(s[i-1]==s[j]&&s[j]==s[j-1])now=0;
        else if(s[i-1]==s[j]||s[j]==s[j-1]||s[i-1]==s[j-1])
            now=min(now,1);
    }
    else
    {
        if(s[i-1]==s[j-1]&&s[i+1]==s[j])
            now=min(now,1+dfs(i+2,0));
    }
  }
  return dp[i][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>s;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<2;j++)dp[i][j]=-1;
    }
    int ans=dfs(0,0);if(ans==inf)ans=-1;
    if(ans!=-1)cout<<"YES\n"<<ans<<"\n";
    else cout<<"NO\n";
    //cout<<endl;
  }
  return 0;
}