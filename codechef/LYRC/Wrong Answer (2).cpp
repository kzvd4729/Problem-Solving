/****************************************************************************************
*  @author: kzvd4729                                         created: 27-08-2019 21:26:42                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.35 sec                                        memory_used: 760M                                 
*  problem: https://www.codechef.com/problems/LYRC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500*5000;
struct ahoCorasick
{
  struct node
  {
    int next[62],link;
  }trie[N+2];
  int sz,occur[N+2];//for occurrence of every state
  vector<int>tree[N+2];
  int con(char c)
  {
    if(c>='a'&&c<='z')return c-'a';
    else if(c>='A'&&c<='Z')return 26+c-'A';
    return 52+c-'0';
  }
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
      int c=con(s[i]);
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
      for(int c=0;c<52;c++)
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
      now=trie[now].next[con(x)];
      occur[now]++;
    }
    //dfs(0);
  }
  /*return state number of string s*/
  int stateNumber(string s)
  {
    int now=0;
    for(auto x:s)
    {
      now=trie[now].next[con(x)];
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
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>ss[i];ah.insrt(ss[i]);
  }
  ah.bfs();ah.makeTree();
  int x;cin>>x;
  for(int i=1;i<=x;i++)
  {
    string s;cin>>s;
    for(auto &x:s)if(x=='-')x=' ';
    stringstream ss(s);
    while(ss>>s)
      ah.calOccur(s);
  }
  ah.dfs(0);
  for(int i=1;i<=n;i++)
    cout<<ah.occur[ah.stateNumber(ss[i])]<<"\n";
  return 0;
}