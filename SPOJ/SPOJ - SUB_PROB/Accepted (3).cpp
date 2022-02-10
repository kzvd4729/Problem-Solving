/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-27 20:42:47                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 50                                         memory_used (MB): 5.2                             
*  problem: https://vjudge.net/problem/SPOJ-SUB_PROB
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;

struct ahoCorasick
{
  struct node
  {
    map<int,int>next;int link;
  }trie[N+2];
  int sz,occur[N+2];//for occurrence of every state
  vector<int>tree[N+2];
  void clean(int n=N)
  {
    for(int i=0;i<=n;i++)
    {
      trie[i].next.clear();
      occur[i]=0;tree[i].clear();
    }
    sz=0;
  }
  void insrt(string s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++sz;
      now=trie[now].next[c];
    }
  }
  void bfs(void)
  {
    queue<int>q;q.push(0);
    while(q.size())
    {
      int v=q.front(),u=trie[v].link;q.pop();
      for(auto x:trie[v].next)
      {
        int c=x.first;
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
  /*makes tree with reverse suffix link*/
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
      tree[trie[i].link].push_back(i);
  }
  /*calculate occurrence of every state for string s*/
  int dfs(int nd)
  {
    for(auto x:tree[nd])
      occur[nd]+=dfs(x);
    return occur[nd];
  }
  void calOccur(string s)
  {
    int now=0;
    for(auto x:s)
    {
      now=trie[now].next[x-'a'];
      occur[now]++;
    }
    dfs(0);
  }
  /*return state number of string s*/
  int stateNumber(string s)
  {
    int now=0;
    for(auto x:s)
    {
      now=trie[now].next[x-'a'];
      if(!now)return 0;
    }
    return now;
  }
};
string ss[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  ahoCorasick ah;ah.clean();
  string s;cin>>s;
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>ss[i];ah.insrt(ss[i]);
  }
  ah.bfs();ah.makeTree();ah.calOccur(s);


  for(int i=1;i<=n;i++)
  {
    if(ah.occur[ah.stateNumber(ss[i])])cout<<"Y\n";
    else cout<<"N\n";
  }

  return 0;
}