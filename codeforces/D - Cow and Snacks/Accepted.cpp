/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 20:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 19400 KB                             
*  problem: https://codeforces.com/contest/1209/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
vector<int>ad[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  vector<pair<int,int> >vc;
  for(int i=1;i<=k;i++)
  {
    int a,b;cin>>a>>b;
    vc.push_back({a,b});
    ad[a].push_back(b);ad[b].push_back(a);
  }
  int ans=0;
  for(auto p:vc)
  {
    if(vis[p.first]&&vis[p.second])continue;
    ans++;
    queue<int>q;q.push(p.first);q.push(p.second);
    vis[p.first]=1;vis[p.second]=1;
    while(q.size())
    {
      int u=q.front();q.pop();
      for(auto x:ad[u])
      {
        if(vis[x])continue;
        vis[x]=1;ans++;q.push(x);
      }
    }
  }
  cout<<k-ans<<endl;
  return 0;
}