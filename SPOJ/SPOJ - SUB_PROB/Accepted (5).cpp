/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-23 16:26:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 660                                        memory_used (MB): 210.9                           
*  problem: https://vjudge.net/problem/SPOJ-SUB_PROB
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
struct ahoCorasick
{
  struct node
  {
    int link;map<int,int>next;
    vector<int>f;
  }trie[N+2];
  int nw=0,occur[N+2],ans[N+2];
  vector<int>un;
  void insrt(string s,int id)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';un.push_back(c);
      if(!trie[now].next[c])trie[now].next[c]=++nw;
      now=trie[now].next[c];
    }
    trie[now].f.push_back(id);
  }
  void bfs(void)
  {
    queue<int>q;q.push(0);
    sort(un.begin(),un.end());
    un.erase(unique(un.begin(),un.end()),un.end());
    while(q.size())
    {
      int v=q.front(),u=trie[v].link;q.pop();
      for(auto c:un)
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
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;string s;cin>>s>>n;
  ahoCorasick ah;
  for(int i=1;i<=n;i++)
  {
    string a;cin>>a;
    ah.insrt(a,i);
  }
  ah.bfs();ah.cal(s);
  for(int i=1;i<=n;i++)
  {
    if(ah.ans[i])cout<<"Y\n";
    else cout<<"N\n";
  }
  return 0;
}