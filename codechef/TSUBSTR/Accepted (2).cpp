/****************************************************************************************
*  @author: kzvd4729                                         created: 01-11-2018 18:11:57                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.23 sec                                        memory_used: 163.7M                               
*  problem: https://www.codechef.com/problems/TSUBSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=250000;
long sz,dp[N+N+2],state[N+N+2];
string s;
vector<long>adj[N+N+2];
struct automata
{
  long len,link,clone;
  long next[26];
}st[N+N+2];
void insrt(long c,long last,long id)
{
  long now=++sz;
  st[now].len=st[last].len+1;
  long p,q,cl;
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
      st[cl].clone=1;
      memcpy(st[cl].next,st[q].next,sizeof(st[q].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  state[id]=now;
}
void dfs(long node,long par)
{
  insrt(s[node-1]-'a',state[par],node);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
  }
}
long dfs2(long now)
{
  if(dp[now])return dp[now];
  dp[now]=1;
  for(long c=0;c<26;c++)
  {
    if(st[now].next[c])
      dp[now]+=dfs2(st[now].next[c]);
  }
  return dp[now];
}
void lex(string ord,long k)
{
  if(k>=dp[0])
  {
    cout<<-1<<endl;
    return ;
  }
  string ans;long now=0;
  while(true)
  {
    if(!k)
    {
      cout<<ans<<endl;
      return ;
    }
    for(auto x:ord)
    {
      long c=x-'a';
      if(!st[now].next[c])continue;
      if(dp[st[now].next[c]]>=k)
      {
        ans.push_back(x);
        now=st[now].next[c];
        k--;
        break;
      }
      else
      {
        k-=dp[st[now].next[c]];
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,q;cin>>n>>q;cin>>s;
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  st[0].link=-1;dfs(1,0);
  dfs2(0);
  cout<<dp[0]<<endl;
  while(q--)
  {
    string ord;long k;cin>>ord>>k;
    lex(ord,k-1);
  }
  return 0;
}