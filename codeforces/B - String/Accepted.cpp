/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2018 14:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 85400 KB                             
*  problem: https://codeforces.com/contest/128/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long last,sz,occur[N+N];
long k,dp[N+N];
vector<long>v[N+N];
string s;
struct automata
{
  long len,link,next[26],clone;
}st[N+N+N];
void insrt(long c)
{
  long now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;
  st[now].clone=0;
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
      st[cl].clone=1;
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void process(void)
{
  for(long i=1;i<=sz;i++)
    v[st[i].len].push_back(i);
  for(long i=s.size();i>=1;i--)
    for(auto x:v[i])
      occur[st[x].link]+=occur[x];
}
long dfs(long now)
{
  if(dp[now]!=-1)return dp[now];
  long cnt=occur[now];
  if(now==0)cnt=0;
  for(long i=0;i<26;i++)
    if(st[now].next[i])
      cnt+=dfs(st[now].next[i]);
  return dp[now]=cnt;
}
long match(void)
{
  cin>>s;
  long now=0;
  for(long i=0;s[i];i++)
  {
    long c=s[i]-'a';
    if(st[now].next[c]==0)return 0;
    now=st[now].next[c];
  }
  return dp[now];
}
void lex(long k)
{
  long now=0;
  string ans;
  while(true)
  {
    for(long i=0;i<26;i++)
    {
      if(st[now].next[i]==0)continue;
      long nxt=dp[st[now].next[i]];
      if(k<=nxt)
      {
        ans.push_back(char(i+'a'));
        k-=occur[st[now].next[i]];
        now=st[now].next[i];
        break;
      }
      else k-=nxt;
    }
    if(k<=0)break;
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  long l=s.size();
  st[0].link=-1;
  for(long i=0;s[i];i++)insrt(s[i]-'a');
   process();
  memset(dp,-1,sizeof(dp));
  dfs(0);
   cin>>k;
  if(k>((l*(l+1))/2))cout<<"No such line."<<endl;
  else lex(k);
   return 0;
}