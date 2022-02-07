/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-14 23:59:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 470                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10559
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int aa[N+2],bb[N+2],cc[N+2],n,dp[N+2][N+2][N+2];
vector<int>pos[N+2];
int dfs(int lo,int hi,int ex)
{
  if(lo==hi)return (ex+cc[lo])*(ex+cc[lo]);
  if(dp[lo][hi][ex]!=-1)return dp[lo][hi][ex];
  int now=0;
  now=max(now,(cc[lo]+ex)*(cc[lo]+ex)+dfs(lo+1,hi,0));
  now=max(now,cc[hi]*cc[hi]+dfs(lo,hi-1,0));
  if(ex)now=max(now,ex*ex+dfs(lo,hi,0));
  for(auto x:pos[bb[lo]])
    if(x>lo&&x<=hi)
      now=max(now,dfs(lo+1,x-1,0)+dfs(x,hi,ex+cc[lo]));
  return dp[lo][hi][ex]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
    int cnt=1,ls=aa[1];int id=0;
    for(int i=2;i<=n;i++)
    {
      if(aa[i]==ls)cnt++;
      else
      {
        bb[++id]=ls;cc[id]=cnt;
        cnt=1;ls=aa[i];
      }
    }
    bb[++id]=ls;cc[id]=cnt;n=id;
    for(int i=0;i<=N;i++)pos[i].clear();
    for(int i=1;i<=n;i++)pos[bb[i]].push_back(i);
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<": "<<dfs(1,n,0)<<endl;
  }
  return 0;
}