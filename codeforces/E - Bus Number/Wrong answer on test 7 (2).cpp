/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2020 12:26                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/991/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
 int cnt[10+2];
vector<pair<int,int> >v;
long ncr[20+2][20+2];
void calNCR(int n)
{
  for(int i=1;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
  }
}
int dp[20+2][10+2];
long dfs(int pl,int id)
{
  if(id==v.size())return pl==0;
  if(dp[pl][id]!=-1)return dp[pl][id];
  long ret=0;
  if(v[id].first==0)
  {
    for(int i=1;i<=v[id].second;i++)
      if(pl-1>=i)ret+=ncr[pl-1][i]*dfs(pl-i,id+1);
  }
  else
  {
    for(int i=1;i<=v[id].second;i++)
      if(pl>=i)ret+=ncr[pl][i]*dfs(pl-i,id+1); 
  }
  return dp[pl][id]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calNCR(20);string s;cin>>s;
  for(auto x:s)cnt[x-'0']++;
   for(int i=0;i<10;i++)
    if(cnt[i])v.push_back({i,cnt[i]});
   long ans=0;
  for(int i=1;i<=s.size();i++)
  {
    memset(dp,-1,sizeof dp);
    ans+=dfs(i,0);
  }
  cout<<ans<<endl;
  return 0;
}