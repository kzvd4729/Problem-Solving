/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2018 15:36                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 7300 KB                              
*  problem: https://codeforces.com/contest/618/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>adj[N+2];
int cnt;
void dfs(int node,int par)
{
  int here=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    here++;dfs(x,node);
  }
  cnt+=max(0,here-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x,y;cin>>n>>x>>y;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int rt;
  for(int i=1;i<=n;i++)
    if(adj[i].size()==1)rt=i;
  dfs(rt,-1);
  //cout<<cnt<<endl;
  if(y<=x)
  {
    if(n==2)cout<<x<<endl;
    else if(n==3)cout<<x+y<<endl;
    else if(n==4)cout<<x+x+y<<endl;
    else cout<<(n-1)*1LL*y<<endl;
  }
  else cout<<(cnt*1LL*y)+(n-1-cnt)*1LL*x<<endl;
   return 0;
}