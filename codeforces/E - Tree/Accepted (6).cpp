/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/10/2019 09:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 982 ms                                          memory_used: 141400 KB                            
*  problem: https://codeforces.com/contest/1111/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+7;
int dp[301][N+1];
struct data
{
  int one,two,thr;
};
vector<data>v;
bool cmp(data A,data B)
{
  return A.one<B.one;
}
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
  /**************** HLD *****************/
int Par[N+2],Lev[N+2],Sp[N+2][22];
vector<int>Adj[N+2];int Sub[N+2];
int Ent[N+2],Ext[N+2],Tim,Anc[N+2];
void Reckon(int n,int p,int h)
{
  Par[n]=p;Lev[n]=h;Sub[n]=1;
  for(auto &x:Adj[n])
  {
    if(x==p)continue;Reckon(x,n,h+1);
    Sub[n]+=Sub[x];
    if(Sub[x]>=Sub[Adj[n][0]])
      swap(x,Adj[n][0]);
  }
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
void HLD(int n,int p)
{
  Ent[n]=++Tim;
  for(auto x:Adj[n])
  {
    if(x==p)continue;//Anc[r]=r;
    if(x==Adj[n][0])Anc[x]=Anc[n];
    else Anc[x]=x;HLD(x,n);
  }
  Ext[n]=Tim;
}
int Hqry(int u,int lc)
{
  int ret=0;
  while(Anc[u]!=Anc[lc])
  {
    int v=Anc[u];
    ret+=Sum(Ent[u])-Sum(Ent[v]-1);
    u=Par[v];
  }
  return ret+Sum(Ent[u])-Sum(Ent[lc]-1);
}
int Path(int u,int v)
{
  int d,ret=0;int lc=Lca(u,v,d);
  ret=Hqry(u,lc)+Hqry(v,lc);
  ret-=Hqry(lc,lc);return ret;
}
////////////////////////////////////////
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
  Anc[1]=1;HLD(1,-1);
  while(q--)
  {
    int k,r;cin>>k>>m>>r;
    int d;v.clear();
    for(int i=1;i<=k;i++)
    {
      int x;cin>>x;Lca(x,r,d);
      Upd(Ent[x],n,1);
      v.push_back({d,x,0});
    }
    sort(v.begin(),v.end(),cmp);int id=0;
    for(auto x:v)
    {
      int ans=Path(x.two,r);
      v[id++].thr=ans-1;
    }
    for(int i=1;i<=m;i++)
      for(int j=0;j<v.size();j++)
        dp[i][j]=-1;
    int pr=rec(1,1);
    cout<<pr<<"\n";
    for(auto x:v)
      Upd(Ent[x.two],n,-1);
  }
  return 0;
}