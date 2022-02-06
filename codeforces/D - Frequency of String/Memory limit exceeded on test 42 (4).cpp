/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2019 16:31                        
*  solution_verdict: Memory limit exceeded on test 42        language: GNU C++14                               
*  run_time: 529 ms                                          memory_used: 524300 KB                            
*  problem: https://codeforces.com/contest/963/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
 int stateNumber[N+2];
struct ahoCorasick
{
  struct node
  {
    int link,next[26],f=0;
  }trie[N+2];
  int sz=0;
  vector<int>tree[N+2],occur[N+2];
  int insrt(string s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++sz;
      now=trie[now].next[c];
    }
    trie[now].f=1;
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
  /*calculate occurrence of every state for string s*/
  void dfs(int nd)
  {
    for(auto x:tree[nd])
    {
      dfs(x);
      for(auto z:occur[x])
        occur[nd].push_back(z);
    }
  }
  void calOccur(string s)
  {
    int now=0,id=0;
    for(auto x:s)
    {
      now=trie[now].next[x-'a'];
      occur[now].push_back(id);
      id++;
    }
    dfs(0);
    for(int i=1;i<=sz;i++)
      if(trie[i].f)sort(occur[i].begin(),occur[i].end());
  }
};
int kk[N+2];string ss[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n;cin>>n;
  ahoCorasick ah;
  for(int i=1;i<=n;i++)
  {
    cin>>kk[i]>>ss[i];
    stateNumber[i]=ah.insrt(ss[i]);
  }
  //cout<<"here"<<endl;
  ah.bfs();ah.makeTree();
  ah.calOccur(s);
  for(int i=1;i<=n;i++)
  {
    int nm=stateNumber[i];
    if(ah.occur[nm].size()<kk[i])
    {
      cout<<-1<<"\n";continue;
    }
    int len=ss[i].size();
    int mn=1e9;
    for(int j=0;j+kk[i]-1<ah.occur[nm].size();j++)
      mn=min(mn,ah.occur[nm][j+kk[i]-1]-ah.occur[nm][j]);
    cout<<mn+len<<"\n";
  }
  return 0;
}