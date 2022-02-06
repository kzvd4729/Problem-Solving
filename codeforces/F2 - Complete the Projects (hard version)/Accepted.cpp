/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2019 13:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 12700 KB                             
*  problem: https://codeforces.com/contest/1203/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
#define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<setw(2)<<x<<" ";
  cerr<<")"<<endl;
}
 const int N=1e6;
vector<pair<int,int> >pos,neg;
vector<vector<int> >dp;
int dfs(int r,int id)
{
  if(r<0)return -1e9;if(id==neg.size())return 0;
  //cout<<r<<" --> "<<id<<endl;
  if(dp[r][id]!=-1)return dp[r][id];
  int now=dfs(r,id+1);
  if(neg[id].first<=r)now=max(now,1+dfs(r-neg[id].second,id+1));
  return dp[r][id]=now;
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
  return a.second-a.first<b.second-b.first;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,r;cin>>n>>r;
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;
    if(b>=0)pos.push_back({a,b});
    else neg.push_back({a,-b});
  }
  sort(pos.begin(),pos.end());
  int ans=0;
  for(auto x:pos)
    if(x.first<=r)ans++,r+=x.second;
  sort(neg.begin(),neg.end(),cmp);
  //for(auto x:neg)DP(x);
  dp.resize(r+1);
  for(int i=0;i<=r;i++)dp[i].resize((int)neg.size(),-1);
  SP(ans);SP(r);
  cout<<ans+dfs(r,0)<<endl;
  return 0;
}