/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2018 00:57                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/128/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int last,sz,occur[N+N];
vector<int>v[N+N];
string s;
struct automata
{
  int len,link,next[26];
}st[N+N+N];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;
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
void process(void)
{
  for(int i=1;i<=sz;i++)
    v[st[i].len].push_back(i);
  for(int i=s.size();i>=1;i--)
    for(auto x:v[i])
      occur[st[x].link]+=occur[x];
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
  return occur[now];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   //cin>>s;
  s="cabab";
  st[0].link=-1;
  for(int i=0;s[i];i++)insrt(s[i]-'a');
   process();
   disct_lex(1);
   //cout<<match()<<endl;
  //cout<<occur[3]<<endl;
   //cout<<occur[2]<<endl;
   return 0;
}