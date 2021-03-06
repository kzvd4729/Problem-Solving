/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2019 21:20                        
*  solution_verdict: Wrong answer on test 87                 language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 47100 KB                             
*  problem: https://codeforces.com/contest/587/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=320;
int occur[N+2],term[N+2];
vector<int>clr;queue<int>q;
struct node
{
  int link,next[26];
};
struct ahoCorasick
{
  vector<node>trie;
  int sz;vector<int>cnt;
  vector<vector<int> >tree;
  vector<int>suff;
  void clean(int n)
  {
    trie.resize(n+2);suff.resize(n+2);
    tree.resize(n+2);cnt.resize(n+2);
    for(int i=0;i<=n;i++)
    {
      memset(trie[i].next,0,sizeof(trie[i].next));
      cnt[i]=0;suff[i]=0;
    }
    sz=0;
  }
  int insrt(string &s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++sz;
      now=trie[now].next[c];
    }
    cnt[now]++;suff[now]=now;
    return now;
  }
  void bfs(void)
  {
    while(q.size())q.pop();q.push(0);
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
  void dfs(int nd,int par)
  {
    if(par!=-1)
    {
      cnt[nd]+=cnt[par];
      if(!suff[nd])suff[nd]=suff[par];
    }
    for(auto &x:tree[nd])
      dfs(x,nd);
  }
  void cal(void)
  {
    for(int i=1;i<=sz;i++)
      tree[trie[i].link].push_back(i);
    dfs(0,-1);
  }
  int allOccur(string &s)
  {
    int now=0,ret=0;
    for(auto &x:s)
    {
      now=trie[now].next[x-'a'];
      ret+=cnt[now];
    }
    return ret;
  }
  void abc(string &s)
  {
    for(auto &x:clr)
      occur[x]--;
    clr.clear();int now=0,link;
    for(auto &x:s)
    {
      now=trie[now].next[x-'a'];
      for(link=suff[now];link;link=suff[trie[link].link])
      {
        occur[link]++;
        clr.push_back(link);
      }
    }
  }
 }block[N+2],ah;
int bl[N+2];string ss[N+2];
vector<vector<int> >qr[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;ah.clean(N);
  vector<int>buf;int sz=0,id=-1;
  for(int i=0;i<n;i++)
  {
    cin>>ss[i];
    buf.push_back(i);
    term[i]=ah.insrt(ss[i]);
    sz+=ss[i].size();
    if(buf.size()==sq)
    {
      block[++id].clean(sz);
      for(auto &x:buf)
        block[id].insrt(ss[x]);
      buf.clear();sz=0;
    }
  }
  ah.bfs();ah.cal();
  for(int i=0;i<=id;i++)
  {
    block[i].bfs();block[i].cal();
  }
  int l,r,k;
  for(int i=0;i<q;i++)
  {
    cin>>l>>r>>k;
    l--,r--,k--;
    qr[k].push_back({l,r,i});
  }
  vector<int>ans(q+2);
  map<vector<int>,int>mp;
  for(int i=0;i<n;i++)
  {
    if(qr[i].size()==0)continue;
    for(int j=0;j<=id;j++)
      bl[j]=block[j].allOccur(ss[i]);
    ah.abc(ss[i]);
    for(auto &x:qr[i])
    {
      if(mp.count(x))
      {
        ans[x[2]]=mp[x];continue;
      }
      int l=x[0],r=x[1],sum=0;
      while(l<=r)
      {
        if(l%sq==0)break;
        sum+=occur[term[l++]];
      }
      while(l<=r)
      {
        if(r%sq==sq-1)break;
        sum+=occur[term[r--]];
      }
      if(l<=r)
      {
        for(int b=l/sq;b<=r/sq;b++)
          sum+=bl[b];
      }
      mp[x]=ans[x[2]]=sum;
    }
  }
  for(int i=0;i<q;i++)
    cout<<ans[i]<<"\n";
  return 0;
}