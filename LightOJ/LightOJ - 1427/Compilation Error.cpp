/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-27 19:02:09                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1427
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;

struct ahoCorasick
{
  struct node
  {
    int next[26],link;
    vector<int>ed;//for storing end position
  }trie[N+2];
  int nw,occur[N+2];//occurrence of every state
  void clean(void)
  {
    memset(trie,0,sizeof(trie));
    nw=0;
  }
  void insrt(string s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++nw;
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
};

int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);

  return 0;
}