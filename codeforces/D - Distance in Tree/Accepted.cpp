/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2018 16:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 496 ms                                          memory_used: 207100 KB                            
*  problem: https://codeforces.com/contest/161/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e4;
long n,k,u,v,dp[N+2][502],ans;
vector<long>adj[N+2];
void dfs(long node,long par)
{
  dp[node][0]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
    for(long i=k;i>=1;i--)dp[x][i]=dp[x][i-1];
    dp[x][0]=0;
    for(long i=0;i<=k;i++)dp[node][i]+=dp[x][i];
  }
  long cnt=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
//    if(node==2)
//    {
//      for(long i=0;i<=k;i++)cout<<dp[node][i]<<" ";
//      cout<<endl;
//      for(long i=0;i<=k;i++)cout<<dp[x][i]<<" ";
//      cout<<endl;
//    }
    for(long i=0;i<=k;i++)
    {
      ///if(node==3)cout<<cnt<<endl;
      cnt+=dp[x][i]*(dp[node][k-i]-dp[x][k-i]);
    }
  }
  cnt+=dp[node][k];
  ans=ans+cnt/2;
//  cout<<"node "<<node<<" "<<cnt<<endl;
//  if(adj[node].size()==1&&par!=-1)return ;
//  if(par==-1)ans+=(cnt/(adj[node].size()*1LL));
//  else ans+=(cnt/(adj[node].size()*1LL-1));
  //cout<<"node "<<node<<" "<<cnt<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(long i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  cout<<ans<<endl;
  return 0;
}