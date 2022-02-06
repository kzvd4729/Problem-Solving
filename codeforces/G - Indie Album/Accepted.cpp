/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2019 00:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 733 ms                                          memory_used: 99300 KB                             
*  problem: https://codeforces.com/contest/1207/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5;
int bit[N+2],tim,ent[N+2],ext[N+2],ans[N+2];
vector<pair<int,int> >qr[N+2];
vector<pair<int,char> >adj[N+2];
void upd(int id,int vl)
{
  for( ;id<=N;id+=id&-id)
    bit[id]+=vl;
}
int get(int id)
{
  int ret=0;
  for( ;id>0;id-=id&-id)
    ret+=bit[id];
  return ret;
}
struct ahoCorasick
{
  struct node
  {
    int next[26],link;
  }trie[N+2];
  int sz;
  vector<int>tree[N+2];
  int insrt(string s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++sz;
      now=trie[now].next[c];
    }
    return now;
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
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
      tree[trie[i].link].push_back(i);
  }
  int dfs(int nd)
  {
    ent[nd]=++tim;
    for(auto x:tree[nd])
      dfs(x);
    ext[nd]=tim;
  }
}ah;
void dfs(int nd,int now)
{
  for(auto x:qr[nd])
    ans[x.second]=get(ext[x.first])-get(ent[x.first]-1);
  for(auto x:adj[nd])
  {
    int c=x.second-'a';
    int nx=ah.trie[now].next[c];
    if(nx)upd(ent[nx],1);dfs(x.first,nx);
    if(nx)upd(ent[nx],-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      char c;cin>>c;
      adj[0].push_back({i,c});
    }
    else
    {
      int id;char c;cin>>id>>c;
      adj[id].push_back({i,c});
    }
  }
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int x;string s;cin>>x>>s;
    qr[x].push_back({ah.insrt(s),i});
  }
  ah.bfs();ah.makeTree();ah.dfs(0);
  dfs(0,0);
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<"\n";
  return 0;
}