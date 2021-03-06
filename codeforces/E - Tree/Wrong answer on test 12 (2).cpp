/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 20:05                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 795 ms                                          memory_used: 138700 KB                            
*  problem: https://codeforces.com/contest/1111/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+7;
int dp[301][N+1];
/**************** LCA ********************/
int Par[N+2],Lev[N+2],Sp[N+2][22];
vector<int>Adj[N+2];
void Reckon(int n,int p,int h)
{
  Par[n]=p;Lev[n]=h;
  for(auto x:Adj[n])
    if(x!=p)Reckon(x,n,h+1);
}
void Build_Sparse(int n)
{
  memset(Sp,-1,sizeof(Sp));
  for(int i=1;i<=n;i++)
    Sp[i][0]=Par[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(Sp[i][j-1]==-1)continue;
      Sp[i][j]=Sp[Sp[i][j-1]][j-1];
    }
  }
}
int Lca(int u,int v,int &d)
{
  if(Lev[u]<Lev[v])swap(u,v);d=0;
  for(int i=20;i>=0;i--)
  {
    if(Lev[u]-(1<<i)>=Lev[v])
      u=Sp[u][i],d+=(1<<i);
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(Sp[u][i]==-1||Sp[v][i]==-1)continue;
    if(Sp[u][i]==Sp[v][i])continue;
    u=Sp[u][i];v=Sp[v][i];d+=2*(1<<i);
  }
  d+=2;return Par[u];
}
//////////////////////////////////////////
  /*************** BIT *****************/
int Bit[N+2];
void Upd(int x,int n,int vl)
{
  for( ;x<=N;x+=(x&-x))
    Bit[x]+=vl;
}
int Sum(int x)
{
  int sum=0;
  for( ;x>0;x-=(x&-x))
    sum+=Bit[x];
  return sum;
}
////////////////////////////////////////
struct data
{
  int one,two,thr;
};
vector<data>v;
bool cmp(data A,data B)
{
  return A.one<B.one;
}
bool cmp2(data A,data B)
{
  return A.thr<B.thr;
}
vector<int>ax;
int sz[N+2],ent[N+2],ext[N+2],tim;
int anc[N+2];
void dfs(int node,int par)
{
  sz[node]=1;
  for(auto &x:Adj[node])
  {
    if(x==par)continue;
    dfs(x,node);sz[node]+=sz[x];
    if(sz[x]>=sz[Adj[node][0]])
      swap(x,Adj[node][0]);
  }
}
void hld(int node,int par)
{
  ent[node]=++tim;
  for(auto &x:Adj[node])
  {
    if(x==par)continue;
    if(x==Adj[node][0])
      anc[x]=anc[node];
    else anc[x]=x;
    hld(x,node);
  }
  ext[node]=tim;
}
int hld_query(int u,int lc)
{
  int ret=0;
  while(true)
  {
    if(anc[u]==anc[lc])
      return ret+Sum(ent[u])-Sum(ent[lc]-1);
    int v=anc[u];
    ret+=Sum(ent[u])-Sum(ent[v]-1);
    u=Par[v];
  }
  return ret;
}
int m;
long rec(int i,int j)
{
  if(i>m)return 0;
  if(j>=v.size())return 1;
  if(dp[i][j]!=-1)return dp[i][j];
  long now=0;
  now=(now+rec(i+1,j+1))%mod;
  now=(now+(i-v[j].thr)*rec(i,j+1))%mod;
  return dp[i][j]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  Reckon(1,-1,0);Build_Sparse(n);
  dfs(1,-1);anc[1]=1;hld(1,-1);
  while(q--)
  {
    int k,r;cin>>k>>m>>r;
    int d;v.clear();
    for(int i=1;i<=k;i++)
    {
      int x;cin>>x;Lca(x,r,d);
      Upd(ent[x],n,1);
      v.push_back({d,x,0});
    }
    sort(v.begin(),v.end(),cmp);int id=0,f=0;
    for(auto x:v)
    {
      int lc=Lca(x.two,r,d);
      int ans=hld_query(x.two,lc);
      ans+=hld_query(r,lc);
      ans-=(Sum(ent[lc])-Sum(ent[lc]-1));
      v[id++].thr=ans-1;
      if(ans>m)f=1;
    }
    if(f)
    {
      cout<<0<<endl;continue;
    }
    for(int i=1;i<=m;i++)
      for(int j=0;j<v.size();j++)
        dp[i][j]=-1;
    int pr=rec(1,1);if(pr==0)assert(0);
    cout<<pr<<endl;
    for(auto x:v)
      Upd(ent[x.two],n,-1);
  }
  return 0;
}