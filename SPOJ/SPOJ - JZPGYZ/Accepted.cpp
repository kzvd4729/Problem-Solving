/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-27 14:29:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 210                                        memory_used (MB): 272.4                           
*  problem: https://vjudge.net/problem/SPOJ-JZPGYZ
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
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=360000;
struct node
{
  int next[128+2],link;
  vector<int>nm;
}trie[N+2];
int nw,stNm[N+2];
void insrt(string s,int id)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i];
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  trie[now].nm.push_back(id);stNm[id]=now;
}
void bfs(void)
{
  queue<int>q;q.push(0);
  while(q.size())
  {
    int v=q.front(),u=trie[v].link;q.pop();
    for(int c=0;c<128;c++)
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
vector<int>adj[N+2];//calculate N
void makeTree(void)
{
  for(int i=1;i<=nw;i++)
    adj[trie[i].link].push_back(i);
}
void clear(void)
{
  for(int i=0;i<=nw;i++)
    memset(trie[i].next,0,sizeof trie[i].next),adj[i].clear();
  nw=0;
}
string tx[N+2];
vector<int>bff[N+2];
int sz;
struct segment
{
  int l,r,sm;
}seg[42*N+2];//2*lg(mx)*N
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi){seg[node].sm=seg[pnode].sm+vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++sz;
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>=lt&&hi<=rt)return seg[node].sm;
  if(lo>rt||hi<lt)return 0;
  int md=(lo+hi)/2;
  return get(seg[node].l,lo,md,lt,rt)+get(seg[node].r,md+1,hi,lt,rt);
}
int last[N+2],root[N+2];
int tim,ent[N+2],ext[N+2],lsr;
void dfs(int nd)
{
  ++tim;ent[nd]=tim;

  root[tim]=root[tim-1];
  sort(bff[nd].begin(),bff[nd].end());
  bff[nd].erase(unique(bff[nd].begin(),bff[nd].end()),bff[nd].end());
  for(auto x:bff[nd])
  {
    int tmp=++sz;
    upd(tmp,1,N,lsr,tim,1);
    if(last[x]){root[tim]=++sz;upd(root[tim],1,N,tmp,last[x],-1);}
    else root[tim]=tmp;

    lsr=root[tim];last[x]=tim;
  }
  for(auto x:adj[nd])
    dfs(x);
  ext[nd]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>tx[i];
  for(int i=1;i<=q;i++)
  {
    string s;cin>>s;insrt(s,i);
  }
  bfs();
  for(int i=1;i<=n;i++)
  {
    int now=0;
    for(auto x:tx[i])
    {
      now=trie[now].next[x];
      bff[now].push_back(i);
    }
  }
  makeTree();dfs(0);

  for(int i=1;i<=q;i++)
  {
    int nd=stNm[i];
    cout<<get(root[ext[nd]],1,N,ent[nd],ext[nd])<<'\n';
  }
  return 0;
}