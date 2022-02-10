/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-23 17:32:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB): 61.4                            
*  problem: https://vjudge.net/problem/SPOJ-MINMOVE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=100000;
int sz,last;
string s;
struct automata
{
  int len,link,next[26],id;
}st[N+N+N+N];
void insrt(int c,int kk)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=kk;
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
      st[cl].id=kk;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>s;
  int l=s.size();
  s+=s;
  st[0].link=-1;
  for(int i=0;s[i];i++)insrt(s[i]-'a',i+1);
  int now=0,cnt=0;
  while(l--)
  {
    for(int i=0;i<26;i++)
    {
      if(st[now].next[i])
      {
        now=st[now].next[i];
        break;
      }
    }
  }
  cout<<st[now].id-s.size()/2<<endl;
  return 0;
}