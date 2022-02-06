/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2019 20:12                        
*  solution_verdict: Time limit exceeded on test 2           language: GNU C++14                               
*  run_time: 10000 ms                                        memory_used: 103500 KB                            
*  problem: https://codeforces.com/gym/102040/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=225,inf=1e9;
int ds[sq+2][N+2],n,lg;
vector<int>adj[N+2];
void bfs(int l,int r,int id)
{
  for(int i=1;i<=n;i++)
    ds[id][i]=inf;
  queue<int>q;
  for(int i=l;i<=r;i++)
    q.push(i),ds[id][i]=0;
   while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(ds[id][u]+1<ds[id][x])
        ds[id][x]=ds[id][u]+1,q.push(x);
    }
  }
}
//.................................
int lev[N+2],sp[N+2][21];
void reckon(int n,int p,int h)
{
  sp[n][0]=p;lev[n]=h;
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
}
void sparse(int n)
{
  for(int j=1;j<=lg;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  int d=0;
  for(int i=lg;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i],d+=(1<<i);
  }
  if(u==v)return d;
  for(int i=lg;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];d+=2*(1<<i);
  }
  return d+2;
}
int lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;lg=33-__builtin_clz(n);
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    int cnt=0;
    for(int i=0;i<=n;i+=sq)
      bfs(i+1,min(n,i+sq),++cnt);
    reckon(1,-1,0);sparse(n);
     int q;cin>>q;cout<<"Case "<<++tc<<":\n";
    while(q--)
    {
      int ty;cin>>ty;
      if(ty==1)
      {
        int x,l,r;cin>>x>>l>>r;
        lt[x]=l,rt[x]=r;
      }
      else if(ty==2)
      {
        int x;cin>>x;lt[x]=-1;
      }
      else
      {
        int c,m;cin>>c>>m;int ans=inf;
        while(m--)
        {
          int x;cin>>x;if(lt[x]==-1)continue;
          int l=lt[x],r=rt[x];
           while(l<=r)
          {
            if(l%sq==1)break;
            ans=min(ans,lca(l++,c));
          }
          while(l<=r)
          {
            if(r%sq==0)break;
            ans=min(ans,lca(r--,c)); 
          }
          if(l<=r)
          {
            for(int i=(l+sq-1)/sq;i<=r/sq;i++)
              ans=min(ans,ds[i][c]);
          }
        }
        if(ans==inf)ans=-1;
        cout<<ans<<"\n";
      }
     }
  }
  return 0;
}