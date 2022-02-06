/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2018 11:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 9600 KB                              
*  problem: https://codeforces.com/contest/1027/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int par[N+2],cs[N+2],now,vis[N+2];
stack<int>st;
void dfs(int node,int cnt)
{
 if(vis[node])
 {
  if(vis[node]<cnt)
  {
   now=0;
   return ;
  }
  while(true)
  {
   now=min(now,cs[st.top()]);
   if(st.top()==node)return ;
   st.pop();
  }
 }
 vis[node]=cnt;
 st.push(node);
 dfs(par[node],cnt);
}
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
  int n;cin>>n;
 for(int i=1;i<=n;i++)cin>>cs[i];
 for(int i=1;i<=n;i++)cin>>par[i];
 int cnt=0;long ans=0;
 for(int i=1;i<=n;i++)
 {
  if(vis[i])continue;
  while(st.size())st.pop();
  now=1e9;dfs(i,++cnt);
  ans+=(now*1LL);
 } 
 cout<<ans<<endl;
 return 0;
}