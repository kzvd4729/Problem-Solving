/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-01 18:04:37                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10679
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e5;
int t,tc,last,sz,q;
struct automata
{
  int len,link;
  int next[55];
}st[N+N+2];
string s,ss;
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;

  int p,q;
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
      int cl=++sz;
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
int ret(char c)
{
  if(c>='a'&&c<='z')return c-'a';
  else return c-'A'+26;
}
bool match(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=ret(x);
    if(!st[now].next[c])return false;
    now=st[now].next[c];
  }
  return true;
}
void _clear(void)
{
  int now=0;
  for(auto x:s)
  {
    int c=ret(x);
    int tmp=st[now].next[c];
    st[now].len=0;
    st[now].link=0;
    st[now].next[c]=0;
    now=tmp;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>s;
    ss=s;
    last=0,sz=0;
    st[0].link=-1;
    for(auto x:s)
      insrt(ret(x));
    cin>>q;
    while(q--)
    {
      cin>>s;
      if(match(s))cout<<'y'<<endl;
      else cout<<'n'<<endl;
    }
    s=ss;
    _clear();
  }
  return 0;
}