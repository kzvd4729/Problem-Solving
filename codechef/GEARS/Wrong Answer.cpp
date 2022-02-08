/****************************************************************************************
*  @author: kzvd4729                                         created: 15-07-2018 14:32:40                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 15.2M                                
*  problem: https://www.codechef.com/JULY18A/problems/GEARS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
const int inf=1e8;
int n,m,arr[N+2],f;
int ty,u,v,x,dis,vis[N+2];
vector<int>adj[N+2];
map<pair<int,int>,int>mp;
void dfs(int node,int par,int cnt)
{
  if(vis[node])
  {
    f=1;
    return ;
  }
  vis[node]=1;
  if(node==v)dis=cnt;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(f)return ;
    dfs(x,node,cnt+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  while(m--)
  {
    cin>>ty;
    if(ty==1)
    {
      cin>>u>>x;
      arr[u]=x;
    }
    else if(ty==2)
    {
      cin>>u>>v;
      if(u>v)swap(u,v);
      if(mp[{u,v}])continue;
      mp[{u,v}]=1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    else
    {
      cin>>u>>v>>x;
      dis=inf;
      f=0;
      memset(vis,0,sizeof(vis));
      dfs(u,-1,0);
      if(f)cout<<0<<endl;
      else if(dis==inf)cout<<0<<endl;
      else
      {
        long tmp=arr[u]*1LL*x;
        long gcd=__gcd(tmp,arr[v]*1LL);
        if(dis%2==0)
          cout<<tmp/gcd<<"/"<<arr[v]/gcd<<endl;
        else cout<<"-"<<tmp/gcd<<"/"<<arr[v]/gcd<<endl;
      }
    }
  }
  return 0;
}