/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-27 15:42:03                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4670
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
const int N=150*70;
struct node
{
  int next[26],link;
  vector<int>nm;
}trie[N+2];
int nw,stNm[N+2];
void insrt(string s,int id)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'a';
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
vector<int>adj[N+2];//calculate N
void makeTree(void)
{
  for(int i=1;i<=nw;i++)
    adj[trie[i].link].push_back(i);
}
int cnt[N+2];
void clear(void)
{
  for(int i=0;i<=nw;i++)
  {
    memset(trie[i].next,0,sizeof trie[i].next);
    adj[i].clear(),cnt[i]=0;trie[i].nm.clear();
  }
  nw=0;
}
void dfs(int nd)
{
  for(auto x:adj[nd])
  {
    dfs(x);cnt[nd]+=cnt[x];
  }
}
string ss[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(true)
  {
    cin>>n;
    if(n==0)break;string s;
    for(int i=1;i<=n;i++)
    {
      cin>>s;insrt(s,i);
      ss[i]=s;
    }
    bfs();makeTree();
    int now=0;cin>>s;//cout<<s<<endl;
    for(auto x:s)
    {
      now=trie[now].next[x-'a'];
      cnt[now]++;
    }
    dfs(0);int mx=-1;vector<int>v;
    for(int i=1;i<=nw;i++)
    {
      if(trie[i].nm.size()==0)continue;
      if(cnt[i]>mx)mx=cnt[i],v=trie[i].nm;
      else if(cnt[i]==mx)for(auto x:trie[i].nm)v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(auto x:v)cout<<ss[x]<<'\n';
    clear();
  }
  return 0;
}