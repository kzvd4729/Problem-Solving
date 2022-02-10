/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-16 15:46:48                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 619                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6922
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<pair<int,int> >dp[N+2];
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
  if(p1.first+p1.second!=p2.first+p2.second)
    return p1.first+p1.second<p2.first+p2.second;
  return p1.second>p2.second;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    for(int i=0;i<s.size();i++)dp[i].clear();
    if(s[0]=='a')dp[0].push_back({0,0});
    else dp[0].push_back({2,0});
    for(int i=1;i<s.size();i++)
    {
      if(s[i]=='a')
      {
        for(auto x:dp[i-1])
          dp[i].push_back({x.first,x.second+1});
      }
      else
      {
        for(auto x:dp[i-1])
        {
          if(x.second)
            dp[i].push_back({x.first,x.second-1});
          else dp[i].push_back({x.first+1,x.second});
        }
      }
      if(s[i]!=s[i-1])
      {
        if(s[i]=='a')
        {
          if(i-2<0)dp[i].push_back({2,0});
          else
          {
            for(auto x:dp[i-2])
              dp[i].push_back({x.first+1,x.second});
          }
        }
      }
      if(i>1&&s[i]!=s[i-2])
      {
        if(s[i]=='a'&&s[i-1]=='a')
        {
          if(i-3<0)dp[i].push_back({2,0});
          else
          {
            for(auto x:dp[i-3])
              dp[i].push_back({x.first+2,x.second+1});
          }
        }
      }
      sort(dp[i].begin(),dp[i].end());
      dp[i].erase(unique(dp[i].begin(),dp[i].end()),dp[i].end());
      while(dp[i].size()>10)dp[i].pop_back();
    }
    int ans=1e9;
    for(auto x:dp[s.size()-1])
    {
      //cout<<x.first<<" "<<x.second<<endl;
      ans=min(ans,x.first+x.second);
    }
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}