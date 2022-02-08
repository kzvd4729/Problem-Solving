/****************************************************************************************
*  @author: kzvd4729                                         created: 11-10-2018 18:22:17                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.22 sec                                        memory_used: 36.4M                                
*  problem: https://www.codechef.com/OCT18A/problems/CPCOMP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int fr[N+2],vis[N+2],sz;
vector<int>fc[N+2];
vector<int>adj[N+2];
void seive(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      fc[j].push_back(i);
      vis[j]=1;
    }
  }
}
inline int _gcd(int u,int v)
{
  while(v!=0)
  {
    int r=u%v;
    u=v;v=r;
  }
  return u;
}
void dfs(int node)
{
  sz++;vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
int main()
{
  //ifstream cin("out.txt");
  ios_base::sync_with_stdio(0);cin.tie(0);seive();
  int n;cin>>n;vector<int>v;
  for(int i=1;i<=n;i++)
  {
    int hr=1;
    int x;cin>>x;for(auto z:fc[x])hr*=z;
    fr[hr]++;if(fr[hr]==1)v.push_back(hr);
  }
  n=v.size();
  sort(v.begin(),v.end());
  for(int i=0;i<min(n,100);i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(__gcd(v[i],v[j])==1)
        adj[i].push_back(j),adj[j].push_back(i);
    }
  }
  memset(vis,0,sizeof(vis));int ans=0;
  for(int i=0;i<n;i++)
  {
    if(vis[i])continue;
    sz=0;dfs(i);
    if(sz==1)ans+=fr[v[i]];
    else ans++;
  }
  cout<<ans<<endl;
  return 0;
}