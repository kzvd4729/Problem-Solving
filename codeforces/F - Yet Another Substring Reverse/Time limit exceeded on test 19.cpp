/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2019 20:39                        
*  solution_verdict: Time limit exceeded on test 19          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 28400 KB                             
*  problem: https://codeforces.com/contest/1234/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int lo[N+2],hi[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
  int ans=0;
  for(int i=0;i<s.size();i++)
  {
    int msk=0;
    for(int j=i;j<s.size();j++)
    {
      int c=s[j]-'a';if(msk&(1<<c))break;
      msk|=(1<<c);if(!lo[msk])lo[msk]=i+1;
      hi[msk]=i+1;
    }
    ans=max(ans,__builtin_popcount(msk));
  }
  queue<int>q;vector<int>clr;
  for(int i=0;i<(1<<20);i++)
  {
    if(!lo[i])continue;q.push((1<<20)-1-i);
    while(q.size())
    {
      int u=q.front();q.pop();
      if(__builtin_popcount(i)+__builtin_popcount(u)<=ans||!u)break;
      if(lo[i]+__builtin_popcount(i)<=hi[u])
        ans=max(ans,__builtin_popcount(i)+__builtin_popcount(u));
      for(int j=0;j<20;j++)
        if(u&(1<<j)&&!vis[u^(1<<j)])q.push(u^(1<<j)),vis[u^(1<<j)]=1,clr.push_back(u^(1<<j));
    }
    while(q.size())q.pop();
    for(auto x:clr)vis[x]=0;clr.clear();
  }
  cout<<ans<<endl;
  return 0;
}