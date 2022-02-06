/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2018 13:23                        
*  solution_verdict: Wrong answer on test 50                 language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 48000 KB                             
*  problem: https://codeforces.com/contest/128/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int last,sz,occur[N+N],dp[N+N];
long k;
vector<int>v[N+N];
string s;
struct automata
{
  int len,link,next[26],clone;
}st[N+N+N];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;
  st[now].clone=0;
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
  for(int i=1;i<=sz;i++)
    v[st[i].len].push_back(i);
  for(int i=s.size();i>=1;i--)
    for(auto x:v[i])
      occur[st[x].link]+=occur[x];
}
int dfs(int now)
{
  if(dp[now]!=-1)return dp[now];
  int cnt=occur[now];
  if(now==0)cnt=0;
  for(int i=0;i<26;i++)
    if(st[now].next[i])
      cnt+=dfs(st[now].next[i]);
  return dp[now]=cnt;
}
int match(void)
{
  cin>>s;
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    if(st[now].next[c]==0)return 0;
    now=st[now].next[c];
  }
  return dp[now];
}
void lex(int k)
{
  int now=0;
  string ans;
  while(true)
  {
    for(int i=0;i<26;i++)
    {
      if(st[now].next[i]==0)continue;
      int nxt=dp[st[now].next[i]];
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
  for(int i=0;s[i];i++)insrt(s[i]-'a');
   process();
  memset(dp,-1,sizeof(dp));
  dfs(0);
   cin>>k;
  if(k>((l*(l+1))/2))cout<<"No such line."<<endl;
  else lex(k);
   return 0;
}