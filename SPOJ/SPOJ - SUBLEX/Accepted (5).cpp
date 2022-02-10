/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-07 11:21:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 150                                        memory_used (MB): 41                              
*  problem: https://vjudge.net/problem/SPOJ-SUBLEX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=9e4;
int sz,last,dp[N+N+2];
int k;
string s,ans;
struct automata
{
  int len,link,next[26];
}st[N+N+2];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;

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
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
int dfs(int now)
{
  if(dp[now]!=-1)return dp[now];
  dp[now]=1;
  for(int i=0;i<26;i++)
    if(st[now].next[i])dp[now]+=dfs(st[now].next[i]);
  return dp[now];
}
void klex(int now)
{
  for(int i=0;i<26;i++)
  {
    if(!st[now].next[i]||!k)continue;
    int tmp=dp[st[now].next[i]];
    if(tmp>=k)
    {
      ans.push_back((char)(i+'a'));
      k--;
      klex(st[now].next[i]);
      break;
    }
    else k-=tmp;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>s;
  st[0].link=-1;
  for(int i=0;s[i];i++)
    insrt(s[i]-'a');
  memset(dp,-1,sizeof(dp));
  dfs(0);
  int q;cin>>q;
  while(q--)
  {
    cin>>k;
    ans.clear();
    klex(0);
    cout<<ans<<endl;
  }
  return 0;
}