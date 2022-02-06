/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2019 20:15                        
*  solution_verdict: Memory limit exceeded on test 27        language: GNU C++14                               
*  run_time: 780 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/587/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=320;
int occur[N+2],term[N+2];
vector<int>clr;
struct ahoCorasick
{
  struct node
  {
    int next[26],link;
  };
  vector<node>trie;
  int sz;vector<int>cnt;
  vector<vector<int> >tree;
  void clean(int n=N)
  {
    trie.resize(n+2);
    tree.resize(n+2);cnt.resize(n+2);
    for(int i=0;i<=n;i++)
    {
      memset(trie[i].next,0,sizeof(trie[i].next));
      cnt[i]=0;
    }
    sz=0;
  }
  int insrt(string s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++sz;
      now=trie[now].next[c];
    }
    cnt[now]++;
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
  void dfs(int nd,int par)
  {
    if(par!=-1)cnt[nd]+=cnt[par];
    for(auto x:tree[nd])
      dfs(x,nd);
  }
  void cal(void)
  {
    for(int i=1;i<=sz;i++)
      tree[trie[i].link].push_back(i);
    dfs(0,-1);
  }
  int allOccur(string s)
  {
    int now=0,ret=0;
    for(auto x:s)
    {
      now=trie[now].next[x-'a'];
      ret+=cnt[now];
    }
    return ret;
  }
  void abc(string s)
  {
    for(auto x:clr)
      occur[x]--;
    clr.clear();
    int now=0;
    for(auto x:s)
    {
      now=trie[now].next[x-'a'];
      for(int link=now;link;link=trie[link].link)
      {
        occur[link]++;
        clr.push_back(link);
      }
    }
  }
 }block[sq+2],ah;
int bl[sq+2];string ss[N+2];
vector<vector<int> >qr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;ah.clean();
  vector<string>buf;int sz=0,id=-1;
  for(int i=0;i<n;i++)
  {
    string s;cin>>s;
    buf.push_back(s);
    term[i]=ah.insrt(s);
    sz+=s.size();
    if(buf.size()==sq)
    {
      block[++id].clean(sz);
      for(auto x:buf)
        block[id].insrt(x);
      buf.clear();sz=0;
    }
    ss[i]=s;
  }
  ah.bfs();ah.cal();
  for(int i=0;i<=id;i++)
  {
    block[i].bfs();block[i].cal();
  }
  for(int i=0;i<q;i++)
  {
    int l,r,k;cin>>l>>r>>k;
    l--,r--,k--;
    vector<int>v{l,r,i};
    qr[k].push_back(v);
  }
  vector<int>ans(q+2);
  for(int i=0;i<n;i++)
  {
    if(qr[i].size()==0)continue;
    for(int j=0;j<=id;j++)
      bl[j]=block[j].allOccur(ss[i]);
    ah.abc(ss[i]);
    for(auto x:qr[i])
    {
      int l=x[0],r=x[1],sum=0;
      //cout<<l<<" "<<r<<" -----> ";
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
      //cout<<l<<" "<<r<<endl;
      if(l<=r)
      {
        for(int b=l/sq;b<=r/sq;b++)
          sum+=bl[b];
      }
      ans[x[2]]=sum;
    }
  }
  for(int i=0;i<q;i++)
    cout<<ans[i]<<"\n";
  return 0;
}