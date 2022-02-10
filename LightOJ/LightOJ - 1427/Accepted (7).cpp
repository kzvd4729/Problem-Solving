/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-14 12:06:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1148                                       memory_used (MB): 58                              
*  problem: https://vjudge.net/problem/LightOJ-1427
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500*500;
const int W=26;
int sz,occur[N+2],ans[N+2],tc;
int vis[N+2];
vector<int>vv[N+2];
map<string,int>mp;
struct aho_corasick
{
  int next[W+2],link,f;
}trie[N+2];
void aho_insrt(string s,int id)
{
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    if(!trie[now].next[c])trie[now].next[c]=++sz;
    now=trie[now].next[c];
  }
  trie[now].f=id;
}
void aho_build(void)
{
  queue<int>q;q.push(0);
  while(q.size())
  {
    int u=q.front();q.pop();
    int v=trie[u].link;
    for(int c=0;c<W;c++)
    {
      if(trie[u].next[c])
      {
        if(!u)trie[trie[u].next[c]].link=0;
        else trie[trie[u].next[c]].link=trie[v].next[c];
        q.push(trie[u].next[c]);
      }
      else trie[u].next[c]=trie[v].next[c];
    }
  }
}
int dfs(int node)
{
  int here=occur[node];
  //if(trie[node].f)here=occur[node];
  for(int i=0;i<vv[node].size();i++)
    here+=dfs(vv[node][i]);

occur[node]=-1;
  return ans[trie[node].f]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    for(int i=0;i<=N;i++)
    {
      memset(trie[i].next,0,sizeof(trie[i].next));
      trie[i].f=0,trie[i].link=0;
    }sz=0;mp.clear();
    memset(vis,0,sizeof(vis));
    int n;cin>>n;
    string tx,s;cin>>tx;
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      if(mp[s])vis[i]=mp[s];
      else mp[s]=i,aho_insrt(s,i);
    }
    aho_build();
    for(int i=0;i<=sz;i++)vv[i].clear();
    for(int i=1;i<=sz;i++)
      vv[trie[i].link].push_back(i);
    memset(occur,0,sizeof(occur));
//    for(int i=0;i<=sz;i++)
//      cout<<trie[i].link<<" ";
//    cout<<endl;
    int now=0;
    for(int i=0;tx[i];i++)
    {
      int c=tx[i]-'a';
      now=trie[now].next[c];
      //if(trie[now].f)occur[now]++;
      occur[now]++;
    }
//    for(int i=0;i<=sz;i++)
//      cout<<occur[i]<<" ";
//    cout<<endl;
    dfs(0);cout<<"Case "<<++tc<<":"<<"\n";
    for(int i=1;i<=n;i++)
    {
      if(vis[i])cout<<ans[vis[i]]<<"\n";
      else cout<<ans[i]<<endl;
    }
  }
  return 0;
}