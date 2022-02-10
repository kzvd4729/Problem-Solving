/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-22 19:00:52                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 144                                        memory_used (MB): 4                               
*  problem: https://vjudge.net/problem/LightOJ-1314
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int t,tc,sz,last,n,lt,rt;
int indx[N+N+2];
char s[N+2];
struct automata
{
  int len,link;
  int next[27];
}st[N+N+2];
void insrt(int c,int id)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  indx[id]=now;
 
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
  scanf("%d",&t);
  while(t--)
  {
    memset(st,0,sizeof(st));
    scanf("%s",s);
    scanf("%d%d",&lt,&rt);
    n=strlen(s);
    sz=0;last=0;
    st[0].link=-1;
    int ans=0;
    
    for(int i=1;i<=n;i++)
    {
      insrt(s[i-1]-'a',i);
      int len=st[indx[i]].len;
      int lcp=st[st[indx[i]].link].len;
      if(len>=rt)len=rt;
      if(len>=lt)ans+=len-lt+1;
      if(lcp>=rt)lcp=rt;
      if(lcp>=lt)ans-=(lcp-lt+1);
    }
    printf("Case %d: %d\n",++tc,ans);
    
  }
  return 0;
}