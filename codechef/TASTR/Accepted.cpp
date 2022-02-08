/****************************************************************************************
*  @author: kzvd4729                                         created: 01-11-2018 17:00:37                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 37.1M                                
*  problem: https://www.codechef.com/problems/TASTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int sz,last,mx1[N+2],mx2[N+2];
struct automata
{
  int len,link;
  int next[26];
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
      st[q].link=st[now].link=cl;
    }
  }
  last=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s1;cin>>s1;st[0].link=-1;
  for(int i=0;s1[i];i++)
  {
    insrt(s1[i]-'a');
    mx1[i]=st[st[last].link].len;
  }
  string s2;cin>>s2;
  long ans=0;
  int now=0,ln=0,mx=0;
  for(int i=0;s2[i];i++)
  {
    int c=s2[i]-'a';
    if(st[now].next[c])now=st[now].next[c],ln++;
    else
    {
      for(;now!=-1&&!st[now].next[c];now=st[now].link);
      if(now==-1)now=0,ln=0;
      else
      {
        ln=st[now].len+1;
        now=st[now].next[c];
      }
    }
    mx2[i]=ln;
  }
  for(int i=0;i<=N+N;i++)
  {
    st[i].len=0;st[i].link=0;
    memset(st[i].next,0,sizeof(st[i].next));
  }
  st[0].link=-1;sz=0,last=0;
  for(int i=0;s2[i];i++)
  {
    insrt(s2[i]-'a');
    mx2[i]=max(mx2[i],st[st[last].link].len);
  }
  now=0,ln=0,mx=0;
  for(int i=0;s1[i];i++)
  {
    int c=s1[i]-'a';
    if(st[now].next[c])now=st[now].next[c],ln++;
    else
    {
      for(;now!=-1&&!st[now].next[c];now=st[now].link);
      if(now==-1)now=0,ln=0;
      else
      {
        ln=st[now].len+1;
        now=st[now].next[c];
      }
    }
    mx1[i]=max(mx1[i],ln);
  }
  for(int i=0;s1[i];i++)
    ans+=(i+1-mx1[i])*1LL;
  for(int i=0;s2[i];i++)
    ans+=(i+1-mx2[i])*1LL;
  cout<<ans<<endl;
  return 0;
}