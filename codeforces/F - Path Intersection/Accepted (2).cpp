/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2019 20:17                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 904 ms                                          memory_used: 13600 KB                             
*  problem: https://codeforces.com/gym/102040/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
 const unsigned long mx=(1ULL<<64)-1;
const int sz=157;//64 multiplied
unsigned long on[64][64],of[64][64];
void init()
{
  for(int i=0;i<64;i++)
  {
    for(int j=i;j<64;j++)
    {
      if(j==i)on[i][j]=(1ULL<<j);
      else on[i][j]=on[i][j-1]|(1ULL<<j);
      of[i][j]=mx^on[i][j];
    }
  }
}
struct bitSet
{
  unsigned long bt[sz];
  void clear(){for(int i=0;i<sz;i++)bt[i]=0;}
  bool ck(int i){return (bool)(bt[i/64]&(1ULL<<(i%64)));}
  void set1(int i){bt[i/64]|=(1ULL<<(i%64));}
  void set0(int i){bt[i/64]&=(mx^(1ULL<<(i%64)));}
  void set1(int lt,int rt)
  {
    if(lt/64==rt/64){bt[lt/64]|=on[lt%64][rt%64];return ;}
    bt[lt/64]|=on[lt%64][63];bt[rt/64]|=on[0][rt%64];
    for(int i=lt/64+1;i<rt/64;i++)bt[i]=mx;
  }
  void set0(int lt,int rt)
  {
    if(lt/64==rt/64){bt[lt/64]&=of[lt%64][rt%64];return ;}
    bt[lt/64]&=of[lt%64][63];bt[rt/64]&=of[0][rt%64];
    for(int i=lt/64+1;i<rt/64;i++)bt[i]=0ULL;
  }
  int count1(int lt,int rt)
  {
    int ret=0;
    if(lt/64==rt/64){return __builtin_popcountll(bt[lt/64]&on[lt%64][rt%64]);}
    ret+=__builtin_popcountll(bt[lt/64]&on[lt%64][63]);
    ret+=__builtin_popcountll(bt[rt/64]&on[0][rt%64]);
    for(int i=lt/64+1;i<rt/64;i++)ret+=__builtin_popcountll(bt[i]);
    return ret;
  }
  void dNot(int lt,int rt)//current bitSet will be changed
  {
    if(lt/64==rt/64){bt[lt/64]^=on[lt%64][rt%64];return ;}
    bt[lt/64]^=on[lt%64][63];bt[rt/64]^=on[0][rt%64];
    for(int i=lt/64+1;i<rt/64;i++)bt[i]^=mx;
  }
  void dOr(bitSet &st,int lt,int rt)//current bitSet will be changed
  {
    if(lt/64==rt/64){bt[lt/64]|=(st.bt[lt/64]&on[lt%64][rt%64]);return ;}
    bt[lt/64]|=(st.bt[lt/64]&on[lt%64][63]);
    bt[rt/64]|=(st.bt[rt/64]&on[0][rt%64]);
    for(int i=lt/64+1;i<rt/64;i++)bt[i]|=st.bt[i];
  }
  void dAnd(bitSet &st,int lt,int rt)//current bitSet will be changed
  {
    if(lt/64==rt/64){bt[lt/64]&=(st.bt[lt/64]|of[lt%64][rt%64]);return ;}
    bt[lt/64]&=(st.bt[lt/64]|of[lt%64][63]);
    bt[rt/64]&=(st.bt[rt/64]|of[0][rt%64]);
    for(int i=lt/64+1;i<rt/64;i++)bt[i]&=st.bt[i];
  }
  void dXor(bitSet &st,int lt,int rt)//current bitSet will be changed
  {
    if(lt/64==rt/64){bt[lt/64]^=(st.bt[lt/64]&on[lt%64][rt%64]);return ;}
    bt[lt/64]^=(st.bt[lt/64]&on[lt%64][63]);
    bt[rt/64]^=(st.bt[rt/64]&on[0][rt%64]);
    for(int i=lt/64+1;i<rt/64;i++)bt[i]^=st.bt[i];
  }
}bt[N+2],ans,tmp1,tmp2;
 int lev[N+2],sp[N+2][15];
vector<int>adj[N+2];
void reckon(int n,int p,int h)
{
  sp[n][0]=p,lev[n]=h;
  for(int i=0;i<sz;i++)
    bt[n].bt[i]=bt[p].bt[i];
  bt[n].set1(n);
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
}
void sparse(int n)
{
  for(int j=1;j<=14;j++)
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
  for(int i=14;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=14;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];
  }
  return sp[u][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;init();
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    reckon(1,0,0);sparse(n);
     int q;cin>>q;cout<<"Case "<<++tc<<":\n";
    while(q--)
    {
      int k;cin>>k;ans.set1(1,n);
      while(k--)
      {
        int u,v;cin>>u>>v;
        int l=lca(u,v);
         for(int i=0;i<sz;i++)tmp1.bt[i]=bt[sp[l][0]].bt[i];
        for(int i=0;i<sz;i++)tmp2.bt[i]=bt[sp[l][0]].bt[i];
         tmp1.dXor(bt[u],1,n);tmp2.dXor(bt[v],1,n);
        tmp1.dOr(tmp2,1,n);ans.dAnd(tmp1,1,n);
       }
      cout<<ans.count1(1,n)<<"\n";
    }
  }
  return 0;
}