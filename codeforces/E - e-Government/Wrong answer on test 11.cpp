/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/27/2019 23:22                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 174800 KB                            
*  problem: https://codeforces.com/contest/163/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int bit[N+2],vis[N+2];
void upd(int id,int vl)
{
  for( ;id<=N;id+=id&-id)
    bit[id]+=vl;
}
int get(int id)
{
  int ret=0;
  for( ;id>0;id-=id&-id)
    ret+=bit[id];
  return ret;
}
struct ahoCorasick
{
  struct node
  {
    int next[26],link;
  }trie[N+2];
  int sz,occur[N+2];//for occurrence of every state
  vector<int>tree[N+2];
  int tim=0,ent[N+2],ext[N+2];
  void clean(int n=N)
  {
    for(int i=0;i<=n;i++)
    {
      memset(trie[i].next,0,sizeof(trie[i].next));
      occur[i]=0;tree[i].clear();
    }
    sz=0;
  }
  int insrt(string s)
  {
    int now=0,n=s.size();
    for(int i=0;i<n;i++)
    {
      int c=s[i]-'a';
      if(!trie[now].next[c])trie[now].next[c]=++sz;
      now=trie[now].next[c];
    }
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
  /*makes tree with reverse suffix link*/
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
    {
      //cout<<i<<" ---> "<<trie[i].link<<endl;
      tree[trie[i].link].push_back(i);
    }
  }
  /*calculate occurrence of every state for string s*/
  int dfs(int nd)
  {
    for(auto x:tree[nd])
      occur[nd]+=dfs(x);
    return occur[nd];
  }
  void timing(int node)
  {
    ent[node]=++tim;
    for(auto x:tree[node])
      timing(x);
    ext[node]=tim;
     //cout<<node<<" "<<ent[node]<<" "<<ext[node]<<endl;
  }
  void cal(string s)
  {
    int now=0,ret=0;
    for(int i=1;i<s.size();i++)
    {
      now=trie[now].next[s[i]-'a'];
      ret+=get(ent[now]);
    }
    cout<<ret<<"\n";
  }
};
int node[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q,n;cin>>q>>n;ahoCorasick ah;ah.clean();
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    node[i]=ah.insrt(s);
  }
  ah.bfs();ah.makeTree();ah.timing(0);
  for(int i=1;i<=n;i++)
  {
    //cout<<ah.ent[node[i]]<<" "<<
    upd(ah.ent[node[i]],1),upd(ah.ext[node[i]]+1,-1);
  }
  //cout<<"here"<<endl;
  while(q--)
  {
    string s;cin>>s;
    if(s[0]=='?')ah.cal(s);
    else if(s[0]=='-')
    {
      int nm=0;
      for(int i=1;i<s.size();i++)
        nm=nm*10+s[i]-'0';
      if(vis[nm])continue;vis[nm]=1;
      upd(ah.ent[node[nm]],-1),upd(ah.ext[node[nm]]+1,1);
    }
    else
    {
      int nm=0;
      for(int i=1;i<s.size();i++)
        nm=nm*10+s[i]-'0';
      if(!vis[nm])continue;vis[nm]=0;
      upd(ah.ent[node[nm]],1),upd(ah.ext[node[nm]]+1,-1);
    }
  }
  return 0;
}