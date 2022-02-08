/****************************************************************************************
*  @author: kzvd4729                                         created: 15-07-2018 16:07:18                      
*  solution_verdict: Run Time Error(SIGSEGV)                 language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/JULY18A/problems/GEARS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e8;
int n,m,arr[N+2],u,v,x,ty,color[N+2],id;
int root[N+2],cnt[N+2],vis[N+2],tmp[N+2];
vector<int>adj[N+2];
int find_root(int x)
{
  while(x!=root[x])
  {
    root[x]=root[root[x]];
    x=root[x];
  }
  return x;
}
void dfs(int node)
{
  vis[node]=1;
  tmp[++id]=node;
  if(color[node]==1)color[node]=2;
  else color[node]=1;
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
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    root[i]=i;
    cnt[i]=1;
    color[i]=1;
  }
  while(m--)
  {
    cin>>ty>>u>>v;
    int r1=find_root(u);
    int r2=find_root(v);
    if(ty==1)arr[u]=v;
    else if(ty==2)
    {
      if(cnt[r1]==-1)
        root[r2]=r1;
      else if(cnt[r2]==-1)
        root[r1]=r2;
      else if(r1==r2)
      {
        if(color[u]==color[v])
          cnt[r2]=-1;
      }
      else
      {
        if(color[u]==color[v])
        {
          id=0;
          if(cnt[u]<=cnt[v])
          {
            dfs(u);
            cnt[r2]+=cnt[r1];
            root[r1]=r2;
          }
          else
          {
            dfs(v);
            cnt[r1]+=cnt[r2];
            root[r2]=r1;
          }
          while(id--)vis[tmp[id]]=0;
        }
      }
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    else
    {
      cin>>x;
      if(r1!=r2)cout<<0<<endl;
      else if(cnt[r1]==-1||cnt[r2]==-1)cout<<0<<endl;
      else
      {
        long ttm=arr[u]*1LL*x;
        long gcd=__gcd(ttm,arr[v]*1LL);
        if(color[u]!=color[v])cout<<-(ttm/gcd)<<"/"<<arr[v]/gcd<<endl;
        else cout<<ttm/gcd<<"/"<<arr[v]/gcd<<endl;
      }
    }
//    cout<<"COLOR"<<" ";
//    for(int i=1;i<=n;i++)
//      cout<<color[i]<<" ";
//    cout<<endl;
  }
  return 0;
}