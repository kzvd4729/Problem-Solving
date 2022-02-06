/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2018 19:51                        
*  solution_verdict: Compilation error                       language: GNU C++11                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/19/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,x;
int sz,last;
string s;
struct automata
{
  int len,link,idx;
  map<int,int>next;
}st[N+N+2];
void insrt(int c,int id)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].idx=id;
   int p,q,cl;
  for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
    st[p].next[c]=now;
  if(p==-1)
    st[now].link=0;
  else
  {
    q=st[p].next[c];
    if(st[p].len+1==st[q].len)
      st[now].link=q;
    else
    {
      cl=++sz;
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      st[cl].next=st[q].next;
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
int dfs(int node,int pre,int hg)
{
  parent[node]=pre;
  level[node]=hg;
  siz[node]=1;
  for(auto x:adj[node])
  {
    if(x==pre)continue;
    siz[node]+=dfs(x,node,hg+1);
  }
  return siz[node];
}
void hld(int node,int pre,int f)
{
  if(f)
  {
    chain++;
    head[chain]=node;
  }
  chainno[node]=chain;
  int nd=-1,mx=-1;
  for(auto x:adj[node])
  {
    if(x==pre)continue;
    if(siz[x]>mx)
      mx=siz[x],nd=x;
  }
  if(nd!=-1)hld(nd,node,0);
  for(auto x:adj[node])
  {
    if(x==nd||x==pre)continue;
    hld(x,node,1);
  }
}
void suffix_tree(void)
{
  for(int i=1;i<=sz;i++)
    adj[st[i].link].push_back(i);
  dfs(0,-1,0);
  hld(0,-1,1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
      cin>>n;
  st[0].link=-1;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    insrt(x,i);
  }
  suffix_tree();
  dfs(0,-1,0);
    return 0;
}