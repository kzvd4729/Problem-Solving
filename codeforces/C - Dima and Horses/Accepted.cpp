/****************************************************************************************
*  @author: kzvd4729                                         created: May/13/2019 18:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 560 ms                                          memory_used: 21300 KB                             
*  problem: https://codeforces.com/contest/273/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int pr[N+2],n;
vector<int>adj[N+2];
bool test(int node)
{
  int cnt=0;
  for(auto x:adj[node])
    if(pr[x]==pr[node])cnt++;
  return cnt<=1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  while(true)
  {
    int f=0;
    for(int i=1;i<=n;i++)
    {
      if(!test(i))
        pr[i]^=1,f=1;
    }
    if(!f)break;
  }
  for(int i=1;i<=n;i++)cout<<pr[i];
  cout<<endl;
  return 0;
}