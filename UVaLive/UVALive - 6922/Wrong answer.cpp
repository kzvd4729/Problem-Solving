/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-16 15:10:38                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6922
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>dp[N+2];
pair<int,int>mn(pair<int,int>p1,pair<int,int>p2)
{
  if(p1.first+p1.second<p2.first+p2.second)return p1;
  if(p2.first+p2.second<p1.first+p1.second)return p2;
  if(p1.second>p2.second)return p1;
  return p2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    if(s[0]=='a')dp[0]={0,0};
    else dp[0]={2,0};
    for(int i=1;i<s.size();i++)
    {
      if(s[i]=='a')
        dp[i]={dp[i-1].first,dp[i-1].second+1};
      else
      {
        if(dp[i-1].second)
          dp[i]={dp[i-1].first,dp[i-1].second-1};
        else dp[i]={dp[i-1].first+1,dp[i-1].second};
      }
      if(s[i]!=s[i-1])
      {
        if(s[i]=='a')
        {
          if(i-2<0)dp[i]=mn(dp[i],{2,0});
          else dp[i]=mn(dp[i],{dp[i-2].first+1,dp[i-2].second});
        }
      }
      if(i>1&&s[i]!=s[i-2])
      {
        if(s[i]=='a'&&s[i-1]=='a')
        {
          if(i-3<0)dp[i]=mn(dp[i],{2,0});
          else dp[i]=mn(dp[i],{dp[i-3].first+2,dp[i-3].second+1});
        }
      }
    }
    cout<<"Case "<<++tc<<": "<<dp[s.size()-1].first+dp[s.size()-1].second<<endl;
  }
  return 0;
}