/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2019 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1132/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int aa[N+2],bb[N+2],n,dp[N+2][N+2];
vector<int>pos[N+2];
int dfs(int lo,int hi)
{
  if(lo==hi)return 1;if(lo>hi)assert(0);
  if(dp[lo][hi]!=-1)return dp[lo][hi];
  int now=1e9;
  now=min(now,1+dfs(lo+1,hi));
  now=min(now,1+dfs(lo,hi-1));
  for(auto x:pos[bb[lo]])
    if(x>lo&&x<=hi)
      now=min(now,dfs(lo+1,x-1)+dfs(x,hi));
  return dp[lo][hi]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;string s;cin>>s;
  for(int i=1;i<=n;i++)aa[i]=s[i-1]-'a';
  int cnt=1,ls=aa[1];int id=0;
  for(int i=2;i<=n;i++)
  {
    if(aa[i]==ls)cnt++;
    else
    {
      bb[++id]=ls;
      cnt=1;ls=aa[i];
    }
  }
  bb[++id]=ls;n=id;
  for(int i=1;i<=n;i++)pos[bb[i]].push_back(i);
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,n)<<endl;
  return 0;
}