/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-07 01:51:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 30                                         memory_used (MB): 70.7                            
*  problem: https://vjudge.net/problem/SPOJ-LCS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=250000;
int sz,last;
string s;
struct automata
{
  int len,link,next[26];
}st[N+N];
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
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>s;
  st[0].link=-1;
  for(int i=0;s[i];i++)insrt(s[i]-'a');

  cin>>s;
  int cnt=0,mx=0,now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    if(st[now].next[c])
    {
      cnt++;
      now=st[now].next[c];
    }
    else
    {
      while(now!=-1)
      {
        if(st[now].next[c])
        {
          cnt=st[now].len+1;
          now=st[now].next[c];
          break;
        }
        now=st[now].link;
      }
      if(now==-1)
      {
        now=0;
        cnt=0;
      }
    }
    mx=max(cnt,mx);
  }
  cout<<mx<<endl;
  return 0;
}