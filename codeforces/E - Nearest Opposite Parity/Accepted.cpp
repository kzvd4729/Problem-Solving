/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/12/2019 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 28000 KB                             
*  problem: https://codeforces.com/contest/1272/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],ds[N+2],ans[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    if(i+aa[i]<=n)
    {
      adj[i+aa[i]].push_back(i);
      //cout<<i+aa[i]<<" "<<i<<endl;
    }
    if(i-aa[i]>=1)
    {
      adj[i-aa[i]].push_back(i);
      //cout<<i-aa[i]<<" "<<i<<endl;
    }
  }
   for(int i=1;i<=n;i++)ds[i]=inf;
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]%2)q.push(i),ds[i]=0;
  }
   while(q.size())
  {
    int u=q.front();q.pop();
    for(auto v:adj[u])
    {
      if(ds[u]+1<ds[v])ds[v]=ds[u]+1,q.push(v);
    }
  }
  for(int i=1;i<=n;i++)if(aa[i]%2==0)ans[i]=ds[i];
    for(int i=1;i<=n;i++)ds[i]=inf;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]%2==0)q.push(i),ds[i]=0;
  }
   while(q.size())
  {
    int u=q.front();q.pop();
    for(auto v:adj[u])
    {
      if(ds[u]+1<ds[v])ds[v]=ds[u]+1,q.push(v);
    }
  }
  for(int i=1;i<=n;i++)if(aa[i]%2)ans[i]=ds[i];
   for(int i=1;i<=n;i++)if(ans[i]==inf)ans[i]=-1;
   for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
   return 0;
}