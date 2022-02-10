/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-28 19:13:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 345                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4126
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
const int N=100;
int n,m;
struct node
{
  int next[26],link;
  int msk;
}trie[N+2];
int nw;
void insrt(string s,int id)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'a';
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  trie[now].msk|=(1<<id);
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
vector<int>adj[N+2];
void makeTree(void)
{
  for(int i=1;i<=nw;i++)
    adj[trie[i].link].push_back(i);
}
void dfs(int now,int msk)
{
  trie[now].msk|=msk;
  for(auto x:adj[now])
    dfs(x,trie[now].msk);
}
void clear(void)
{
  for(int i=0;i<=nw;i++)
    memset(trie[i].next,0,sizeof trie[i].next),adj[i].clear(),trie[i].msk=0;
  nw=0;
}
long dp[25+2][(1<<10)+2][100+2];
long rec(int i,int msk,int now)
{
  if(i>n)return dp[i][msk][now]=(msk==((1<<m)-1));
  if(dp[i][msk][now]!=-1)return dp[i][msk][now];
  long ret=0;
  for(int c=0;c<26;c++)
  {
    int nx=trie[now].next[c];
    ret+=rec(i+1,msk|trie[nx].msk,nx);
  }
  return dp[i][msk][now]=ret;
}
vector<string>vec;
void print(int i,int msk,int now,string s)
{
  if(i>n){vec.push_back(s);return ;}
  for(int c=0;c<26;c++)
  {
    int nx=trie[now].next[c];
    if(dp[i+1][msk|trie[nx].msk][nx]>0)
    {
      string tmp=s;tmp.push_back((char)('a'+c));
      print(i+1,msk|trie[nx].msk,nx,tmp);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tc=0;
  while(cin>>n>>m)
  {
    if(n==0&&m==0)break;
    for(int i=0;i<m;i++)
    {
      string s;cin>>s;insrt(s,i);
    }
    bfs();makeTree();dfs(0,0);
    memset(dp,-1,sizeof dp);
    long ans=rec(1,0,0);
    cout<<"Case "<<++tc<<": "<<ans<<" suspects\n";
    if(ans&&ans<=42)
    {
      string s;vec.clear();
      print(1,0,0,s);sort(vec.begin(),vec.end());
      for(auto x:vec)cout<<x<<'\n';
    }
    clear();
  }
  return 0;
}