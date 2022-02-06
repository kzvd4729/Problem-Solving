/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/01/2019 15:04                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15600 KB                             
*  problem: https://codeforces.com/contest/682/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cost[N+2],cnt;
vector<pair<int,int> >adj[N+2];
void dfs(int node,int par,long cs)
{
  if(cs>cost[node])return ;cnt++;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node,cs+x.second);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>cost[i];
  for(int i=2;i<=n;i++)
  {
    int pi,cs;cin>>pi>>cs;
    adj[i].push_back({pi,cs});
    adj[pi].push_back({i,cs});
  }
  dfs(1,-1,0);cout<<n-cnt<<endl;
  return 0;
}