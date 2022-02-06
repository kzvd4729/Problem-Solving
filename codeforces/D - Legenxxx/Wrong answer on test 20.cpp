/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2019 22:06                        
*  solution_verdict: Wrong answer on test 20                 language: GNU C++14                               
*  run_time: 1232 ms                                         memory_used: 36500 KB                             
*  problem: https://codeforces.com/contest/696/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
const long inf=1e2;
struct node
{
  int next[26],link;
  int vl;
}trie[N+2];
int nw;
void insrt(string &s,int ad)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'a';
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  trie[now].vl+=ad;
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
typedef vector<vector<long> > v2d;
v2d multiply(v2d &a,v2d &b)
{
  int d=a.size(),e=a[0].size();
  int f=b.size(),g=b[0].size();
  v2d c;c.resize(d);
  for(int i=0;i<d;i++)
  {
    c[i].assign(g,-inf);
    for(int j=0;j<g;j++)
      for(int k=0;k<e;k++)
        c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
  }
  return c;
}
v2d expo(v2d a,long p)
{
  int n=a.size();v2d ret=a;
  while(p)
  {
    if(p&1)ret=multiply(ret,a);
    a=multiply(a,a);p/=2;
  }
  return ret;
}
string s;int aa[N+2],sum[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;long l;cin>>n>>l;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)
  {
    cin>>s;insrt(s,aa[i]);
  }
  bfs();
  for(int i=0;i<=nw;i++)
  {
    int nd=i;
    while(nd)
    {
      sum[i]+=trie[nd].vl;
      nd=trie[nd].link;
    }
  }
  v2d bs(nw+1);
  for(int i=0;i<=nw;i++)
  {
    bs[i].assign(nw+1,-inf);
    for(int j=0;j<26;j++)
      bs[i][trie[i].next[j]]=sum[trie[i].next[j]];
  }
  bs=expo(bs,l-1);
  long ans=0;
  for(auto x:bs[0])ans=max(ans,x);
  cout<<ans<<endl;
  return 0;
}