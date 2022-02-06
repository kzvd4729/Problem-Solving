/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2019 17:45                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 65500 KB                             
*  problem: https://codeforces.com/contest/852/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,sq=340,inf=1e9;
vector<int>adj[N+2];
int cl[N+2],num[N+2],cnt[2][N+2];
long mul[N+2],ans,print[N+2];
//..............................................................................
int ent[N+2],ext[N+2],tim,flt[N+N+2],sp[N+2][21],lev[N+2],vis[N+2];
struct query
{
  int lt,rt,lc,id;
}qr[N+2];
bool cmp(query a,query b)
{
  if(a.lt/sq!=b.lt/sq)return a.lt<b.lt;return a.rt<b.rt;
}
void dfs(int node,int par,int h)
{
  ent[node]=++tim,sp[node][0]=par,flt[tim]=node,lev[node]=h;
  for(auto x:adj[node])if(x!=par)dfs(x,node,h+1);
  ext[node]=++tim,flt[tim]=node;
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=20;i>=0;i--)if(lev[u]-(1<<i)>=lev[v])u=sp[u][i];
  if(u==v)return u;
  for(int i=20;i>=0;i--)if(sp[u][i]!=sp[v][i])u=sp[u][i],v=sp[v][i];
  return sp[u][0];
}
//eveything is 1 indexed
void solve(vector<pair<int,int> >vc,int n)
{
  dfs(1,-1,0);sparse(n);int q=0;
  // for(int i=1;i<=n;i++)
  //   cout<<ent[i]<<" --> "<<ext[i]<<endl;
  // for(int i=1;i<=n+n;i++)
  //   cout<<flt[i]<<" ";
  // cout<<endl;
  for(auto x:vc)
  {
    ++q;
    int u=x.first,v=x.second,lc=lca(x.first,x.second);
    if(ent[u]>ent[v])swap(u,v);
    if(u==lc)qr[q]={ent[u],ent[v],0,q};//don't need lc;
    else qr[q]={ext[u],ent[v],lc,q};
     //cout<<qr[q].lt<<" "<<qr[q].rt<<" "<<qr[q].lc<<endl;
  }
  sort(qr+1,qr+q+1,cmp);qr[0].lt=1,qr[0].rt=0;
  for(int l=1;l<=q;l++)
  {
    for(int i=qr[l].lt;i<qr[l-1].lt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])
      {
        ans+=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]++;
      }
      else
      {
        ans-=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]--; 
      }
    }
    for(int i=qr[l-1].rt+1;i<=qr[l].rt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])
      {
        ans+=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]++;
      }
      else
      {
        ans-=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]--; 
      }
    }
    for(int i=qr[l-1].lt;i<qr[l].lt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])
      {
        ans+=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]++;
      }
      else
      {
        ans-=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]--; 
      }
    }
    for(int i=qr[l].rt+1;i<=qr[l-1].rt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])
      {
        ans+=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]++;
      }
      else
      {
        ans-=cnt[cl[x]^1][num[x]];cnt[cl[x]][num[x]]--; 
      }
    }
    print[qr[l].id]=ans;
    if(qr[l].lc)
    {
      int x=qr[l].lc;print[qr[l].id]+=cnt[cl[x]^1][num[x]];
    }
  }
}
void uniq(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(num[i]);//////
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)num[i]=mp[num[i]];/////
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>cl[i];
  for(int i=1;i<=n;i++)cin>>num[i];uniq(n);
  // for(int i=1;i<=n;i++)cout<<num[i]<<" ";
  //   cout<<endl;
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<pair<int,int> >vc;
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v;vc.push_back({u,v});
  }
  solve(vc,n);
  for(int i=1;i<=q;i++)cout<<print[i]<<"\n";
  return 0;
}