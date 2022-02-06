/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 16:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/884/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,arr[N+2],sz,vis[N+2];
vector<long>adj[N+2];
void dfs(long node)
{
  vis[node]=1;
  sz++;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>arr[i];
    adj[i].push_back(arr[i]);
  }
  vector<long>vv;
  for(long i=1;i<=n;i++)
  {
    if(vis[i])continue;
    sz=0;
    dfs(i);
    vv.push_back(sz);
  }
  sort(vv.begin(),vv.end());
  if(vv.size()==1)
    cout<<vv[0]*vv[0]<<endl;
  else
  {
    long ans=0;
    vv[vv.size()-2]+=vv[vv.size()-1];
    for(long i=0;i<vv.size()-1;i++)
      ans+=vv[i]*vv[i];
    cout<<ans<<endl;
  }
  return 0;
}