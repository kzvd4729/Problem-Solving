/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-27 19:21:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 873                                        memory_used (MB): 58.4                            
*  problem: https://vjudge.net/problem/HDU-3695
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
const int N=250000;
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
    int c=s[i]-'A';
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
int dp[N+2];
void clear(void)
{
  for(int i=0;i<=nw;i++)
  {
    memset(trie[i].next,0,sizeof trie[i].next),adj[i].clear();
    trie[i].nm.clear(),dp[i]=0;
  }
  nw=0;
}
void dfs(int nd)
{
  for(auto x:adj[nd])
  {
    dfs(x);dp[nd]|=dp[x];
  }
}
string s;
int con(int i,int j)
{
  //assert(j>=i);
  int ret=0;
  for(int k=i;k<=j;k++)
    ret=ret*10+s[k]-'0';
  return ret;
}
string dcode()
{
  string rt;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='[')
    {
      int j;
      for(j=i+1; ;j++)if(s[j]==']')break;
      int nm=con(i+1,j-2);
      while(nm--)rt.push_back(s[j-1]);
      i=j;
    }
    else rt.push_back(s[i]);
  }
  return rt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      string tmp;cin>>tmp;insrt(tmp,i);
    }
    bfs();makeTree();int now=0;
    cin>>s;s=dcode();//cout<<s<<endl;
    for(auto x:s)
    {
      now=trie[now].next[x-'A'];
      dp[now]=true;
    }
    reverse(s.begin(),s.end());
    for(auto x:s)
    {
      now=trie[now].next[x-'A'];
      dp[now]=true;
    }
    dfs(0);int ans=0;
    for(int i=1;i<=n;i++)
    {
      if(dp[stNm[i]])ans++;
    }
    cout<<ans<<'\n';clear();
  }
  return 0;
}