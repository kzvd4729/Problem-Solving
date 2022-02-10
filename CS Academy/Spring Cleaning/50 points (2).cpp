/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 50 points                               language: C++                                     
*  run_time: 279 ms                                          memory_used: 14.5 MB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define log long long
using namespace std;
long n,m,now,sum,ans;
long vis[100005],x,print[100005],in[100005];
vector<long>adj[100005],root;
void dfs(long node)
{
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    vis[x]=1;
    dfs(x);
    cout<<node<<" "<<x<<endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>x;
    in[x]++;
    adj[i].push_back(x);
  }
  for(long i=1;i<=n;i++)if(in[i]==0)root.push_back(i);
  if(root.size()==0)root.push_back(1);
  for(auto x:root)
  {
    dfs(x);
  }
  return 0;
}