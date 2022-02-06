/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/31/2020 20:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1107 ms                                         memory_used: 208500 KB                            
*  problem: https://codeforces.com/contest/1437/problem/G
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
struct node
{
  int next[26],link;
}trie[N+2];
int nw,ed[N+2];
void insrt(string s,int id)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'a';
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  ed[id]=now;
}
void bfs(void)
{
  queue<int>q;q.push(0);
  while(q.size())
  {
    int v=q.front(),u=trie[v].link;q.pop();
    for(int c=0;c<26;c++)
    {
      int nx=trie[v].next[c];
      if(nx)
      {
        q.push(nx);if(!v)trie[nx].link=0;
        else trie[nx].link=trie[u].next[c];
      }
      else trie[v].next[c]=trie[u].next[c];
    }
  }
}
vector<int>adj[N+2];
void makeTree(void)
{
  for(int i=1;i<=nw;i++)
    adj[trie[i].link].push_back(i);
}
int sub[N+2],ent[N+2],tim,anc[N+2],par[N+2],lev[N+2];
void dfs(int n,int p,int l)
{
  sub[n]=1,par[n]=p,lev[n]=l;
  for(auto x:adj[n])
  {
    if(x==p)continue;dfs(x,n,l+1);sub[n]+=sub[x];
  }
}
int seg[4*N+8];
void upd(int nd,int lo,int hi,int id,int vl)
{
  if(lo==hi){seg[nd]=vl;return;}
  int md=(lo+hi)/2;
  if(id<=md)upd(nd*2,lo,md,id,vl);
  else upd(nd*2+1,md+1,hi,id,vl);
  seg[nd]=max(seg[nd*2],seg[nd*2+1]);
}
int get(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return -1;
  if(lo>=lt&&hi<=rt)return seg[nd];
  int md=(lo+hi)/2;
  return max(get(nd*2,lo,md,lt,rt),get(nd*2+1,md+1,hi,lt,rt));
}
void hld(int n,int p)
{
  ent[n]=++tim;//add to the ds
  int mx=-1,b=-1;
  for(auto x:adj[n])
  {
    if(x==p)continue;if(sub[x]>mx)mx=sub[x],b=x;
  }
  if(b!=-1){anc[b]=anc[n];hld(b,n);}
  for(auto x:adj[n])
  {
    if(x==p||x==b)continue;anc[x]=x;hld(x,n);
  }
}
int hQry(int u,int v)
{
  int ret=-1;
  while(true)
  {
    if(lev[u]<lev[v])swap(u,v);
    if(anc[u]==anc[v])
    {
      return max(ret,get(1,1,tim,ent[v],ent[u]));
    }
    if(lev[anc[u]]<lev[anc[v]])swap(u,v);
    ret=max(ret,get(1,1,tim,ent[anc[u]],ent[u]));
    u=par[anc[u]];
  }
}
int nm[N+2];multiset<int>st[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;insrt(s,i);
    nm[i]=0;
  }
  bfs();makeTree();dfs(0,-1,0);hld(0,-1);
  for(int i=1;i<=tim;i++)upd(1,1,tim,i,-1);
  for(int i=1;i<=n;i++)st[ed[i]].insert(0);
  for(int i=1;i<=n;i++)upd(1,1,tim,ent[ed[i]],*st[ed[i]].rbegin());
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int id,x;cin>>id>>x;
      st[ed[id]].erase(st[ed[id]].find(nm[id]));
      nm[id]=x;st[ed[id]].insert(nm[id]);
      upd(1,1,tim,ent[ed[id]],*st[ed[id]].rbegin());
    }
    else
    {
      string s;cin>>s;int ans=-1;
      int now=0;
      for(auto x:s)
      {
        now=trie[now].next[x-'a'];
        ans=max(ans,hQry(0,now));
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}