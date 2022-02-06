/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2020 18:04                        
*  solution_verdict: Time limit exceeded on test 25          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 194500 KB                            
*  problem: https://codeforces.com/contest/986/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=420,mod=1e9+7;
const int R=1e7;
vector<int>adj[N+2];
vector<int>pr[N+2];
int ent[N+2],ext[N+2],tim,flt[N+N+2],sp[N+2][21],lev[N+2],vis[N+2];
int ans[N+2],mxp[R+2],prm[R+2],aa[N+2];
int mx[R+2];
int powr(int p,int x)
{
  int ret=1;
  while(x--)ret*=p;
  return ret;
}
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
struct query
{
  int lt,rt,lc,nm,id;
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
int fr[R+2];
void solve(vector<vector<int> >vc,int n)
{
  dfs(1,-1,0);sparse(n);int q=0;
  for(auto x:vc)
  {
    ++q;
    int u=x[0],v=x[1],lc=lca(x[0],x[1]);
    if(ent[u]>ent[v])swap(u,v);
    if(u==lc)qr[q]={ent[u],ent[v],0,x[2],q};//don't need lc;
    else qr[q]={ext[u],ent[v],lc,x[2],q};
  }
  sort(qr+1,qr+q+1,cmp);qr[0].lt=1,qr[0].rt=0;
  //cout<<"here"<<endl;
  /*for(int i=1;i<=q;i++)
  {
    cout<<"*"<<qr[i].id<<endl;
  }*/
  for(int l=1;l<=q;l++)
  {
    for(int i=qr[l].lt;i<qr[l-1].lt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])for(auto z:pr[x])fr[z]++;
      else for(auto z:pr[x])fr[z]--;
    }
    for(int i=qr[l-1].rt+1;i<=qr[l].rt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])for(auto z:pr[x])fr[z]++;
      else for(auto z:pr[x])fr[z]--;
    }
    for(int i=qr[l-1].lt;i<qr[l].lt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])for(auto z:pr[x])fr[z]++;
      else for(auto z:pr[x])fr[z]--;
    }
    for(int i=qr[l].rt+1;i<=qr[l-1].rt;i++)
    {
      int x=flt[i];vis[x]^=1;
      if(vis[x])for(auto z:pr[x])fr[z]++;
      else for(auto z:pr[x])fr[z]--;
    }
    /*for(int i=1;i<=R;i++)
    {
      if(fr[i])cout<<"*"<<i<<" "<<fr[i]<<endl;
    }
    exit(0);*/
    //store current answer to ans[qr[l].id];
     vector<int>v;int x=qr[l].nm;
    while(x!=1)
    {
      v.push_back(prm[x]);mx[prm[x]]++;
      x/=prm[x];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto z:v)
    {
      int now=powr(z,mxp[z]);
      int stt=powr(z,mx[z]);//cout<<stt<<endl;
      while(now!=1)
      {
        //cout<<"*"<<fr[now]-cnt<<endl;
        ans[qr[l].id]=(1LL*ans[qr[l].id]*big(min(now,stt),fr[now]))%mod;
        now/=z;
      }
      mx[z]=0;
    }
    if(qr[l].lc)
    {
      //cout<<"here"<<endl;
      //cout<<__gcd(aa[qr[l].lc],qr[l].nm)<<endl;
      ans[qr[l].id]=(1LL*ans[qr[l].id]*__gcd(aa[qr[l].lc],qr[l].nm))%mod;
    }
    ///exit(0);
  }
}
bool vs[R+2];
void seive()
{
  for(int i=2;i<=R;i++)
  {
    if(vs[i])continue;
    for(int j=i;j<=R;j+=i)vs[j]=1,prm[j]=i;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;seive();
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[i]=x;
    vector<int>v;
    while(x!=1)
    {
      v.push_back(prm[x]);mx[prm[x]]++;
      x/=prm[x];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto z:v)
    {
      pr[i].push_back(powr(z,mx[z]));
      mx[z]=0;
    }
  }
  /*for(int i=1;i<=n;i++)
  {
    cout<<i<<"*  ";
    for(auto x:pr[i])
      cout<<x<<" ";
    cout<<endl;
  }*/
  int q;cin>>q;vector<vector<int> >vc;
  for(int i=1;i<=q;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    vc.push_back({u,v,w});
  }
  for(int i=1;i<=q;i++)ans[i]=1;
  for(int i=2;i<=R;i++)
  {
    long p=i;
    for(int c=2; ;c++)
    {
      p*=i;
      if(p>R){mxp[i]=c-1;break;}
    }
  }
  solve(vc,n);
  for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
  return 0;
}