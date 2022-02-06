/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2019 19:26                        
*  solution_verdict: Wrong answer on test 26                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 8300 KB                              
*  problem: https://codeforces.com/contest/1216/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;string s;cin>>s;s="#"+s;
  for(int i=1;i<=n;i++)dp[i]=1e16;
  deque<pair<int,int> >dq,fr;
  fr.push_back({0,0});
  for(int i=1;i<=n;i++)
  {
    if(dq.size()&&dq.front().second<i)dq.pop_front();
    if(fr.size()&&fr.front().second<i-k-1)fr.pop_front();
     if(dq.size())dp[i]=dq.front().first;
    if(s[i]=='0')dp[i]=min(dp[i],dp[i-1]+i);
    else
    {
      dp[i]=min(dp[i],fr.front().first+i*1LL);
      while(dq.size())
      {
        if(dq.back().first>=fr.front().first+i*1LL)
          dq.pop_back();
        else break;
      }
      dq.push_back({fr.front().first+i*1LL,i+k});
    }
    while(fr.size())
    {
      if(fr.back().first>=dp[i])
        fr.pop_back();
      else break;
    }
    fr.push_back({dp[i],i});
  }
  cout<<dp[n]<<endl;
  return 0;
}