/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-27 19:32:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1051                                       memory_used (MB): 62.3                            
*  problem: https://vjudge.net/problem/LightOJ-1427
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500*500;

struct ahoCorasick
{
  struct node
  {
    int next[26],link;
  }trie[N+2];
  int sz,occur[N+2];//for occurrence of every state
  vector<int>tree[N+2];
  void clean(int n=N)
  {
    for(int i=0;i<=n;i++)
    {
      memset(trie[i].next,0,sizeof(trie[i].next));
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
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;ahoCorasick ah;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    ah.clean();
    for(int i=1;i<=n;i++)
    {
      cin>>ss[i];ah.insrt(ss[i]);
    }
    ah.bfs();ah.makeTree();ah.calOccur(s);
    cout<<"Case "<<++tc<<":\n";
    for(int i=1;i<=n;i++)
      cout<<ah.occur[ah.stateNumber(ss[i])]<<"\n";
  }
  return 0;
}