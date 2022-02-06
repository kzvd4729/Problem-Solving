/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2020 20:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1419 ms                                         memory_used: 176600 KB                            
*  problem: https://codeforces.com/contest/1327/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
 struct node
{
  long next[26],link,vl;
}trie[N+2];
long nw;
void insrt(string s,long ad)
{
  long now=0,n=s.size();
  for(long i=0;i<n;i++)
  {
    long c=s[i]-'a';
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  trie[now].vl+=ad;
}
void bfs(void)
{
  queue<long>q;q.push(0);
  while(q.size())
  {
    long v=q.front(),u=trie[v].link;q.pop();
    for(long c=0;c<26;c++)
    {
      long nx=trie[v].next[c];
      if(nx)
      {
        q.push(nx);if(!v)trie[nx].link=0;
        else trie[nx].link=trie[u].next[c];
      }
      else trie[v].next[c]=trie[u].next[c];
    }
  }
}
vector<long>adj[N+2];
void dfs(long node)
{
  for(auto x:adj[node])
  {
    trie[x].vl+=trie[node].vl;
    dfs(x);
  }
}
void process()
{
  for(long i=1;i<=nw;i++)
    adj[trie[i].link].push_back(i);
  dfs(0);
}
vector<long>bad;string s;long ad[20+2][1000+2],ed[20+2][1000+2];
void precal()
{
  for(long i=0;i<bad.size()-1;i++)
  {
    long l=bad[i]+1,r=bad[i+1]-1;
    for(long k=0;k<=nw;k++)
    {
      long cnt=0,now=k;
      for(long j=l;j<=r;j++)
      {
        now=trie[now].next[s[j]-'a'];
        cnt+=trie[now].vl;
      }
      ad[i][k]=cnt;ed[i][k]=now;
    }
  }
}
long dp[1000+2][(1<<14)+2];
const long inv=1e18;
long dfs(long i,long now,long msk)
{
  if(i==bad.size()-1)return 0;
  if(dp[now][msk]!=inv)return dp[now][msk];
  long ret=-inv;
  for(long j=0;j<14;j++)
  {
    if(msk&(1<<j))continue;
    long nx=trie[now].next[j];
    ret=max(ret,trie[nx].vl+ad[i][nx]+dfs(i+1,ed[i][nx],msk|(1<<j)));
  }
  return dp[now][msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>s>>x;insrt(s,x);
  }
  bfs();process();cin>>s;
  //for(long i=0;i<=nw;i++)cout<<"*"<<trie[i].vl<<endl;
  bad.push_back(-1);
  for(long i=0;i<s.size();i++)
    if(s[i]=='?')bad.push_back(i);
  bad.push_back(s.size());
  precal();
  for(long i=0;i<1000+2;i++)
  {
    for(long j=0;j<(1<<14)+2;j++)dp[i][j]=inv;
  }
  cout<<ad[0][0]+dfs(1,ed[0][0],0)<<endl;
    return 0;
}