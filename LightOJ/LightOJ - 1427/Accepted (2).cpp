/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-23 16:15:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1304                                       memory_used (MB): 68.4                            
*  problem: https://vjudge.net/problem/LightOJ-1427
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=600*600;
struct ahoCorasick
{
  struct node
  {
    int next[26],link;
    vector<int>f;
  }trie[N+2];
  int nw=0,occur[N+2],ans[N+2];
  void insrt(string s,int id)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++nw;
      now=trie[now].next[c];
    }
    trie[now].f.push_back(id);
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
  vector<int>v[N+2];
  int dfs(int node)
  {
    for(int i=0;i<v[node].size();i++)
      occur[node]+=dfs(v[node][i]);
    return occur[node];
  }
  void cal(string s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      now=trie[now].next[c];
      occur[now]++;
    }
    for(int i=1;i<=nw;i++)
      v[trie[i].link].push_back(i);
    dfs(0);
    for(int i=1;i<=nw;i++)
    {
      for(int j=0;j<trie[i].f.size();j++)
        ans[trie[i].f[j]]=occur[i];
    }
  }
  void _clear(void)
  {
    memset(trie,0,sizeof(trie));
    memset(occur,0,sizeof(occur));
    for(int i=0;i<=N;i++)v[i].clear();
    nw=0;
  }
};
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    ahoCorasick ah;
    for(int i=1;i<=n;i++)
    {
      string a;cin>>a;
      ah.insrt(a,i);
    }
    ah.bfs();ah.cal(s);
    cout<<"Case "<<++tc<<":\n";
    for(int i=1;i<=n;i++)
      cout<<ah.ans[i]<<"\n";
    ah._clear();
  }
  return 0;
}