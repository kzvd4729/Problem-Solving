/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2019 22:47                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++11                               
*  run_time: 4804 ms                                         memory_used: 79300 KB                             
*  problem: https://codeforces.com/contest/1254/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
int sub[N+2],n,tim,ent[N+2],ext[N+2],vis[N+2];
long bit[N+2],sum[N+2],buf[N+2];
vector<int>adj[N+2],dir[N+2],bin[N+2];
int big(int b,int p,int m=mod)
{
  int ret=1;
  while(p)
  {
    if(p&1)ret=(1LL*ret*b)%m;
    b=(1LL*b*b)%m;p/=2;
  }
  return ret;
}
void upd(int x,int vl)
{
  for( ;x<=n;x+=x&-x)bit[x]+=vl;
}
long get(int x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
void dfs(int node,int par)
{
  sub[node]=1;ent[node]=++tim;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dir[node].push_back(x);
    dfs(x,node);sub[node]+=sub[x];
  }
  ext[node]=tim;
}
bool cmp(int a,int b){return ent[a]<ent[b];}
void clear(int node,long ad)
{
  sum[node]+=ad;
  for(auto x:dir[node])
    clear(x,ad+buf[node]*(n-sub[x]));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  for(int i=1;i<=n;i++)
  {
    sort(dir[i].begin(),dir[i].end(),cmp);
    for(auto x:dir[i])bin[i].push_back(ent[x]);
  }
   vector<int>cl;
  while(m--)
  {
    int ty;cin>>ty;
    /*if(cl.size()>300)
    {
      clear(1,0);
      for(auto x:cl)vis[x]=0,buf[x]=0;
      cl.clear();
    }*/
    if(ty==1)
    {
      int v,d;cin>>v>>d;sum[v]+=1LL*d*n;
      upd(1,1LL*d*sub[v]);upd(ent[v],-1LL*d*sub[v]);
      upd(ext[v]+1,1LL*d*sub[v]);
       buf[v]+=d;if(!vis[v])vis[v]=1,cl.push_back(v);
    }
    else
    {
      int v;cin>>v;long ans=get(ent[v])+sum[v];
      //cout<<ans<<endl;
      for(auto x:cl)
      {
        int id=upper_bound(bin[x].begin(),bin[x].end(),ent[v])-bin[x].begin();
        //cout<<id<<" "<<x<<" -- "<<bin[x][id]<<endl;
        id--;
        if(id>=0&&(ent[v]>=ent[dir[x][id]]&&ent[v]<=ext[dir[x][id]]))
          ans+=buf[x]*(n-sub[dir[x][id]]);
      }
      //cout<<ans<<endl;
      cout<<(1LL*(ans%mod)*big(n,mod-2))%mod<<endl;
    }
  }
  return 0;
}