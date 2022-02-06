/****************************************************************************************
*  @author: kzvd4729                                         created: May/22/2018 16:50                        
*  solution_verdict: Wrong answer on test 27                 language: GNU C++11                               
*  run_time: 530 ms                                          memory_used: 37900 KB                             
*  problem: https://codeforces.com/contest/19/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,x,sz,last,sp[20][N+N+2],vis[N+N+2];
int arr[N+2];
int parent[N+N+2],level[N+N+2],index[N+N+2];
vector<int>adj[N+N+2];
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
  index[id]=now;
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
      st[cl].idx=id;
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void dfs(int node,int pre,int hg)
{
  if(vis[node])return ;
  vis[node]=1;
  level[node]=hg;
  parent[node]=pre;
  for(auto x:adj[node])
    dfs(x,node,hg+1);
}
void sparse_table(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=0;i<=sz;i++)
    sp[0][i]=parent[i];
  for(int j=1;j<=18;j++)
  {
    for(int i=0;i<=sz;i++)
    {
      if(sp[j-1][i]==-1)continue;
      sp[j][i]=sp[j-1][sp[j-1][i]];
    }
  }
}
int lca(int u,int v)
{
  if(level[u]<level[v])swap(u,v);
  for(int i=18;i>=0;i--)
  {
    if(sp[i][u]==-1)continue;
    if(level[sp[i][u]]>=level[v])
      u=sp[i][u];
  }
  if(u==v)return st[u].len;
  for(int i=18;i>=0;i--)
  {
    if(sp[i][u]==-1||sp[i][v]==-1)continue;
    if(sp[i][u]==sp[i][v])continue;
    u=sp[i][u];
    v=sp[i][v];
  }
  return st[parent[u]].len;
}
void suffix_tree(void)
{
  for(int i=1;i<=sz;i++)
    adj[st[i].link].push_back(i);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  st[0].link=-1;
  vector<pair<int,int> >v;
  for(int i=n;i>=1;i--)
  {
    v.push_back({arr[i],i});
    x=arr[i];
    insrt(x,i);
  }
  suffix_tree();
  dfs(0,-1,0);
  sparse_table();
   sort(v.begin(),v.end());
  int mx=1;
  for(int i=0;i<v.size();i++)
  {
    int lt=i;
    pair<int,int>p={v[i].first,2e9};
    int rt=upper_bound(v.begin(),v.end(),p)-v.begin();
    rt--;
    for(int j=lt;j<=rt;j++)
    {
      for(int k=j+1;k<=rt;k++)
      {
        int lcp=lca(index[v[j].second],index[v[k].second]);
        if(lcp==0)continue;
        int len=abs(v[j].second-v[k].second);
        if(lcp>=len)
          mx=max(mx,max(v[j].second,v[k].second));
      }
    }
  }
  cout<<n-mx+1<<endl;
  for(int i=mx;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}