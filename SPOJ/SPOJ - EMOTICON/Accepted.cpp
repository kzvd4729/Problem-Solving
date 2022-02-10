/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-28 13:57:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB): 4.6                             
*  problem: https://vjudge.net/problem/SPOJ-EMOTICON
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=15000;
struct node
{
  int next[128],link;
}trie[N+2];
int nw,f[N+2];
void insrt(string s)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i];assert(c>=0&&c<128);
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  f[now]=1;
}
void bfs(void)
{
  queue<int>q;q.push(0);
  while(q.size())
  {
    int v=q.front(),u=trie[v].link;q.pop();
    for(int c=0;c<128;c++)
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
vector<int>adj[N+2];
void makeTree(void)
{
  for(int i=1;i<=nw;i++)
    adj[trie[i].link].push_back(i);
}
void dfs(int nd,int m)
{
  f[nd]|=m;
  for(auto x:adj[nd])
    dfs(x,f[nd]);
}
void clear(void)
{
  for(int i=0;i<=nw;i++)
    memset(trie[i].next,0,sizeof trie[i].next),f[i]=0,adj[i].clear();
  nw=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(true)
  {
    int n,m;cin>>n>>m;if(n==0&&m==0)break;
    string s;
    for(int i=1;i<=n;i++)
    {
      cin>>s;insrt(s);
    }
    bfs();getline(cin,s);int ans=0;
    makeTree();dfs(0,0);
    for(int i=1;i<=m;i++)
    {
      getline(cin,s);//cout<<"**"<<s<<endl;
      stringstream ss;ss<<s;
      while(ss>>s)
      {
        int now=0;
        for(auto x:s)
        {
          int c=x;assert(c>=0&&c<128);
          now=trie[now].next[x];
          if(f[now])ans++,now=0;
        }
      }
    }
    cout<<ans<<'\n';clear();
  }
  return 0;
}