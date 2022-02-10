/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-27 13:43:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 300                                        memory_used (MB): 116.7                           
*  problem: https://vjudge.net/problem/SPOJ-SUB_PROB
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
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
struct node
{
  int next[128+2],link;
  vector<int>nm;
}trie[N+2];
int nw,stNm[N+2];
void insrt(string s,int id)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i];
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  trie[now].nm.push_back(id);stNm[id]=now;
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
vector<int>adj[N+2];//calculate N
void makeTree(void)
{
  for(int i=1;i<=nw;i++)
    adj[trie[i].link].push_back(i);
}
void clear(void)
{
  for(int i=0;i<=nw;i++)
    memset(trie[i].next,0,sizeof trie[i].next),adj[i].clear();
  nw=0;
}
int dp[N+2];
void dfs(int nd)
{
  for(auto x:adj[nd])
  {
    dfs(x);dp[nd]|=dp[x];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string tmp;cin>>tmp;insrt(tmp,i);
  }
  bfs();makeTree();int now=0;
  for(auto x:s)
  {
    now=trie[now].next[x];
    dp[now]=true;
  }
  dfs(0);
  for(int i=1;i<=n;i++)
  {
    if(dp[stNm[i]])cout<<"Y\n";
    else cout<<"N\n";
  }
  return 0;
}