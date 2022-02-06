/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2018 15:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 717 ms                                          memory_used: 62800 KB                             
*  problem: https://codeforces.com/contest/767/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,arr[N+2],sum,tr,u;
vector<int>adj[N+2],ans;
int dfs(int node)
{
  int here=arr[node];
  for(auto x:adj[node])
    here+=dfs(x);
  if(here==tr)
  {
    ans.push_back(node);
    here=0;
  }
  return here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>u>>arr[i];
    sum+=arr[i];
    adj[u].push_back(i);
  }
  tr=sum/3;
  if(tr*3!=sum)cout<<-1<<endl,exit(0);
  dfs(adj[0][0]);
  if(ans.size()>2)
    cout<<ans[0]<<" "<<ans[1]<<endl;
  else cout<<-1<<endl;
  return 0;
}