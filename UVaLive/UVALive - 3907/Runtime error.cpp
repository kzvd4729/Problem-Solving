/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-28 18:39:24                      
*  solution_verdict: Runtime error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-3907
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
const int N=50000;
int n,m;
struct node
{
  int next[26],link;
}trie[N+2];
int nw,ed[N+2];
void insrt(string s)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'A';
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  ed[now]=1;
}
void bfs(void)
{
  queue<int>q;q.push(0);
  while(q.size())
  {
    int v=q.front(),u=trie[v].link;q.pop();
    for(int c=0;c<n;c++)
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
int cl[N+2],f;
void dfs(int now)
{
  if(f||cl[now]==2)return ;
  if(cl[now]==1){f=1;return ;}
  cl[now]=1;
  for(int c=0;c<n;c++)
    if(ed[trie[now].next[c]]==0)dfs(trie[now].next[c]);
  cl[now]=2;
}
void dfs0(int now,int m)
{
  ed[now]|=m;
  for(auto x:adj[now])
    dfs0(x,ed[now]);
}
int dp[N+2];
int dfs2(int now)
{
  if(dp[now]!=-1)return dp[now];
  dp[now]=0;
  for(int c=0;c<n;c++)
    if(ed[trie[now].next[c]]==0)dp[now]=max(dp[now],1+dfs2(trie[now].next[c]));
  return dp[now];
}
string ans;
void dfs3(int now)
{
  for(int c=n-1;c>=0;c--)
  {
    if(ed[trie[now].next[c]]==0&&dp[now]-1==dp[trie[now].next[c]]&&dp[now])
    {
      ans.push_back((char)(c+'A'));
      dfs3(trie[now].next[c]);
    }
  }
}
void clear(void)
{
  for(int i=0;i<=nw;i++)
    memset(trie[i].next,0,sizeof trie[i].next),cl[i]=0,ed[i]=0,adj[i].clear();
  nw=0,f=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
      string s;cin>>s;insrt(s);
    }
    bfs();dfs(0);makeTree();dfs0(0,0);
    if(f){cout<<"No\n";clear();continue;}
    for(int i=0;i<=nw;i++)dp[i]=-1;
    int mx=dfs2(0);
    if(mx==0){cout<<"No\n";clear();continue;}
    ans.clear();dfs3(0);assert(ans.size()==mx);
    cout<<ans<<'\n';clear();
  }
  return 0;
}