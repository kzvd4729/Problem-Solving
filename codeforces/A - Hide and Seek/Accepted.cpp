/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2019 11:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1161/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],prv[N+2],nex[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;int ans=n+n+n-2;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;vis[x]=1;
    if(vis[x-1])prv[x]=1;
    if(vis[x+1])nex[x]=1;
  }
  for(int i=1;i<=n;i++)
    ans=ans-(vis[i]+prv[i]+nex[i]);
  cout<<ans<<endl;
  return 0;
}