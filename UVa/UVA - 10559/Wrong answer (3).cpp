/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-13 16:58:14                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10559
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int n,aa[N+2],dp[N+2][N+2][N+2];
vector<int>v,sz;
int dfs(int st,int ls,int s)
{
  if(st>=v.size())return s*s;
  if(dp[st][ls][s]!=-1)return dp[st][ls][s];
  int now=0;
  now=max(now,s*s+dfs(st+1,v[st],sz[st]));
  if(v[st]==ls)
    now=max(now,dfs(st+1,ls,s+sz[st]));
  now=max(now,sz[st]*sz[st]+dfs(st+1,ls,s));
  return dp[st][ls][s]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
    v.clear();sz.clear();memset(dp,-1,sizeof(dp));
    int cnt=1,ls=aa[1];
    for(int i=2;i<=n;i++)
    {
      if(aa[i]==ls)cnt++;
      else 
      {
        v.push_back(ls);
        sz.push_back(cnt);cnt=1;
        ls=aa[i];
      }
    }
    v.push_back(ls);sz.push_back(cnt);
    cout<<"Case "<<++tc<<": ";
    if(v.size()==1)
    {
      cout<<sz[0]*sz[0]<<endl;continue;
    }
    else 
    {
      cout<<dfs(1,v[0],sz[0])<<endl;
    }
  }
  return 0;
}