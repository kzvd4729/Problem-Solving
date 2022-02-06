/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 12:57                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 1872 ms                                         memory_used: 27500 KB                             
*  problem: https://codeforces.com/gym/101991/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long ans;
struct ahoCorasick
{
  struct node
  {
    int next[26],link,mx,oc,len;
  }trie[N+2];
  int sz,occur[N+2];//for occurrence of every state
  vector<int>tree[N+2];
  void clean(int n=N)
  {
    for(int i=0;i<=n;i++)
    {
      trie[i].mx=0,trie[i].oc=0;
      memset(trie[i].next,0,sizeof(trie[i].next));
      occur[i]=0;tree[i].clear();
    }
    sz=0;
  }
  int insrt(string s,vector<int>v)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++sz;
      now=trie[now].next[c];
       trie[now].mx=v[i];
      trie[now].oc++;
      trie[now].len=i+1;
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
  void dfs(int now)
  {
    for(auto x:tree[now])
    {
      dfs(x);
      trie[now].mx=max(trie[now].mx,trie[x].mx);
    }
  }
  void traverse(void)
  {
    for(int i=1;i<=sz;i++)
    {
      long oc=trie[i].oc;
      ans=max(ans,oc*trie[i].len*trie[i].mx);
    }
  }
}ah;
 string s[N+2];
int main()
{
  freopen("exciting.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    ah.clean();
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>s[i];
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
      v.resize((int)s[i].size());
      for(int j=0;j<s[i].size();j++)
        cin>>v[j];
      ah.insrt(s[i],v);
    }
    ah.bfs();ah.makeTree();ah.dfs(0);
    ans=0;ah.traverse();
    cout<<ans<<"\n";
  }
  return 0;
}